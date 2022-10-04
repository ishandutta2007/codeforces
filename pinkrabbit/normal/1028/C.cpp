#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=(a);i<=(b);++i)
#define dF(i,a,b) for(int i=(a);i>=(b);--i)
const int INF=0x3f3f3f3f;
#define Luogu Judge-INF
int n,q;
int x[300001],y[300001],X[300001],Y[300001];
int xx[300001],yy[300001],XX[300001],YY[300001];
int xxx[300001],yyy[300001],XXX[300001],YYY[300001];

int main(){
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d%d%d",x+i,y+i,X+i,Y+i);
	xx[0]=-INF; yy[0]=-INF; XX[0]=INF; YY[0]=INF;
	xxx[n+1]=-INF; yyy[n+1]=-INF; XXX[n+1]=INF; YYY[n+1]=INF;
	F(i,1,n) xx[i]=max(xx[i-1],x[i]), XX[i]=min(XX[i-1],X[i]), yy[i]=max(yy[i-1],y[i]), YY[i]=min(YY[i-1],Y[i]);
	dF(i,n,1) xxx[i]=max(xxx[i+1],x[i]), XXX[i]=min(XXX[i+1],X[i]), yyy[i]=max(yyy[i+1],y[i]), YYY[i]=min(YYY[i+1],Y[i]);
	F(i,1,n){
		int mix=max(xx[i-1],xxx[i+1]);
		int mx=min(XX[i-1],XXX[i+1]);
		int miy=max(yy[i-1],yyy[i+1]);
		int my=min(YY[i-1],YYY[i+1]);
		if(mix<=mx&&miy<=my) {printf("%d %d",mix,miy); return 0;}
	}
	return 0;
}