#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define MN 100005
#define ll long long
#define mod 998244353
#define inf 100000
int t,n;
int x[MN],y[MN],f1[MN],f2[MN],f3[MN],f4[MN];
int mxx,mnx,mxy,mny;
int main(){
	scanf("%d",&t);
	while(t--){
		mxx=mxy=inf,mnx=mny=-inf;
		scanf("%d",&n);
		F(i,1,n){
			scanf("%d%d%d%d%d%d",x+i,y+i,f1+i,f2+i,f3+i,f4+i);
			if(!f1[i])mnx=max(mnx,x[i]);
			if(!f2[i])mxy=min(mxy,y[i]);
			if(!f3[i])mxx=min(mxx,x[i]);
			if(!f4[i])mny=max(mny,y[i]);
		}
		if(mnx<=mxx&&mny<=mxy)printf("1 %d %d\n",mxx,mxy);
		else puts("0");
	}
	return 0;
}