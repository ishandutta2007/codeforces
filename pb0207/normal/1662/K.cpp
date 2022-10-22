#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;

const db eps=1e-4;

int T=50;
int TT=45;

db res=1e9;
db nx[3],ny[3];
db f5(db x,db y) {
	db s=0;
	FOR(i,0,2) s+=sqrt((x-nx[i])*(x-nx[i])+(y-ny[i])*(y-ny[i]));
	return s;
}
db f4(db x) {
	db L=-1e4,R=1e4;
	FOR(_,1,TT) {
		db m1=(L*2+R)/3;
		db m2=(L+R*2)/3;
		if(f5(x,m1)<f5(x,m2)) R=m2;
		else L=m1;
	}
	return f5(x,L);
}
db f3() {
	db L=-1e4,R=1e4;
	FOR(_,1,TT) {
		db m1=(L*2+R)/3;
		db m2=(L+R*2)/3;
		if(f4(m1)<f4(m2)) R=m2;
		else L=m1;
	}
	return f4(L);
}
int X[3],Y[3];
db f2(db x,db y) {
	db t=0;
	FOR(i,0,2) {
		FOR(j,0,2) nx[j]=X[j],ny[j]=Y[j];
		nx[i]=x;ny[i]=y;
		t=max(t,f3());
	}
	if(t<res) res=t;
	return t;
}
db f1(db x) {
	db L=-1e4,R=1e4;
	FOR(_,1,T) {
		db m1=(L*2+R)/3;
		db m2=(L+R*2)/3;
		if(f2(x,m1)<f2(x,m2)) R=m2;
		else L=m1;
	}
	return f2(x,L);
}
int main() {
	FOR(i,0,2) scanf("%d%d",&X[i],&Y[i]);
//	cerr << f2(0,0) << endl;
	db L=-1e4,R=1e4;
	FOR(_,1,T) {
		db m1=(L*2+R)/3;
		db m2=(L+R*2)/3;
		if(f1(m1)<f1(m2)) R=m2;
		else L=m1;
	}
	T=TT=100;
	f1(L);
	printf("%.8lf\n",res);
	return 0;
}