#ifndef __qCTKAbstractQObjectFactory_h
#define __qCTKAbstractQObjectFactory_h

#include "qCTKAbstractObjectFactory.h"

#include <QDebug>

//----------------------------------------------------------------------------
template<typename BaseClassType>
class qCTKAbstractQObjectFactory : protected qCTKAbstractObjectFactory<BaseClassType>
{
public:
  //-----------------------------------------------------------------------------
  // Description:
  // Constructor/Desctructor
  explicit qCTKAbstractQObjectFactory(){}
  virtual ~qCTKAbstractQObjectFactory(){}

  //----------------------------------------------------------------------------
  // Description:
  // Create an instance of the object
  BaseClassType * instantiate(const QString& itemKey)
    {
    return this->qCTKAbstractObjectFactory<BaseClassType>::instantiate(itemKey);
    }

  //----------------------------------------------------------------------------
  // Description:
  // Uninstanciate the object
  void uninstantiate(const QString& itemKey)
    {
    this->qCTKAbstractObjectFactory<BaseClassType>::uninstantiate(itemKey);
    }

  //----------------------------------------------------------------------------
  // Description:
  // Get list of all registered item names
  QStringList names()
    {
    return this->qCTKAbstractObjectFactory<BaseClassType>::names();
    }

  //-----------------------------------------------------------------------------
  // Description:
  // Register an object in the factory
  // Note: The parameter 'key' passed by reference will be updated with the associated object name
  template<typename ClassType>
  bool registerQObject(QString& key)
    {
    key = QString::fromLatin1(ClassType::staticMetaObject.className());
    return this->qCTKAbstractObjectFactory<BaseClassType>::template registerObject<ClassType>(key);
    }

private:
  qCTKAbstractQObjectFactory(const qCTKAbstractQObjectFactory &);  // Not implemented
  void operator=(const qCTKAbstractQObjectFactory&); // Not implemented
};

#endif
