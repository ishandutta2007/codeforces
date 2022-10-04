#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define ld long double
// from_luogu
int n;
int x[300001],y[300001];
ld chk(ld X){
	ld A=0;
	F(i,1,n) A=max(A,((x[i]-X)*(x[i]-X)+(ld)y[i]*y[i])/((ld)2*y[i]));
	return A;
}

int main(){
	int Mx=0;
	scanf("%d",&n);
	F(i,1,n) scanf("%d%d",x+i,y+i);
	if(y[1]<0) F(i,1,n) y[i]=-y[i];
	F(i,1,n) if(y[i]<0) return puts("-1"),0;
	ld l=-1.1e7, r=1.1e7, mid1, mid2;
	F(ti,1,100){
		mid1=(l+l+r)/3, mid2=(l+r+r)/3;
		ld a1=chk(mid1), a2=chk(mid2);
		if(a1>a2) l=mid1;
		else r=mid2;
	} printf("%.10lf\n",(double)chk(mid1));
	return 0;
}