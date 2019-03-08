/* Created by "go tool cgo" - DO NOT EDIT. */

/* package command-line-arguments */


#line 1 "cgo-builtin-prolog"

#include <stddef.h> /* for ptrdiff_t below */

#ifndef GO_CGO_EXPORT_PROLOGUE_H
#define GO_CGO_EXPORT_PROLOGUE_H

typedef struct { const char *p; ptrdiff_t n; } _GoString_;

#endif

/* Start of preamble from import "C" comments.  */


#line 3 "/home/lixiaocui1/Project/go/src/wrappertoc/Test1/etcdclient.go"

#include <stdlib.h>

enum EtcdErrCode
{
  StatusOK = 0,
  ErrNewEtcdClientV3 = -1,
  ErrEtcdPut = -2,
  ErrEtcdGet = -3,
  ErrEtcdGetNotExist = -4,
  ErrEtcdList = -5,
  ErrEtcdListNotExist = -6,
  ErrEtcdDelete = -7,
  ErrEtcdRename = -8,
  ErrEtcdSnapshot = -9,
  ErrObjectNotExist = -10,
  ErrObjectType = -11,
  ErrEtcdTxn = -12,
  ErrEtcdTxnUnkownOp = -13
};

enum OpType {
  OpPut = 1,
  OpDelete = 2
};

struct EtcdConf {
	char *Endpoints;
	int len;
    int DialTimeout;
};

struct Operation {
	enum OpType opType;
	char *key;
	char *value;
	int keyLen;
	int valueLen;
};

#line 1 "cgo-generated-wrapper"


/* End of preamble from import "C" comments.  */


/* Start of boilerplate cgo prologue.  */
#line 1 "cgo-gcc-export-header-prolog"

#ifndef GO_CGO_PROLOGUE_H
#define GO_CGO_PROLOGUE_H

typedef signed char GoInt8;
typedef unsigned char GoUint8;
typedef short GoInt16;
typedef unsigned short GoUint16;
typedef int GoInt32;
typedef unsigned int GoUint32;
typedef long long GoInt64;
typedef unsigned long long GoUint64;
typedef GoInt64 GoInt;
typedef GoUint64 GoUint;
typedef __SIZE_TYPE__ GoUintptr;
typedef float GoFloat32;
typedef double GoFloat64;
typedef float _Complex GoComplex64;
typedef double _Complex GoComplex128;

/*
  static assertion to make sure the file is being used on architecture
  at least with matching size of GoInt.
*/
typedef char _check_for_64_bit_pointer_matching_GoInt[sizeof(void*)==64/8 ? 1:-1];

typedef _GoString_ GoString;
typedef void *GoMap;
typedef void *GoChan;
typedef struct { void *t; void *v; } GoInterface;
typedef struct { void *data; GoInt len; GoInt cap; } GoSlice;

#endif

/* End of boilerplate cgo prologue.  */

#ifdef __cplusplus
extern "C" {
#endif


// TODO(lixiaocui): 下面的操作err细分，可能需要增加重试逻辑；
// TODO(lixiaocui): 日志打印看是否需要glog

extern GoInt32 NewEtcdClientV3(struct EtcdConf p0);

extern GoInt32 EtcdClientPut(int p0, char* p1, char* p2, int p3, int p4);

/* Return type for EtcdClientGet */
struct EtcdClientGet_return {
	GoInt32 r0;
	char* r1;
	GoInt r2;
};

extern struct EtcdClientGet_return EtcdClientGet(int p0, char* p1, int p2);

/* Return type for EtcdClientList */
struct EtcdClientList_return {
	GoInt32 r0;
	GoUint64 r1;
	GoInt64 r2;
};

// TODO(lixiaocui): list可能需要有长度限制

extern struct EtcdClientList_return EtcdClientList(int p0, char* p1, char* p2, int p3, int p4);

extern GoInt32 EtcdClientDelete(int p0, char* p1, int p2);

extern GoInt32 EtcdClientTxn2(int p0, struct Operation p1, struct Operation p2);

/* Return type for EtcdClientGetSingleObject */
struct EtcdClientGetSingleObject_return {
	GoInt32 r0;
	char* r1;
	GoInt r2;
};

extern struct EtcdClientGetSingleObject_return EtcdClientGetSingleObject(GoUint64 p0);

/* Return type for EtcdClientGetMultiObject */
struct EtcdClientGetMultiObject_return {
	GoInt32 r0;
	char* r1;
	GoInt r2;
};

extern struct EtcdClientGetMultiObject_return EtcdClientGetMultiObject(GoUint64 p0, GoInt p1);

extern void EtcdClientRemoveObject(GoUint64 p0);

#ifdef __cplusplus
}
#endif
