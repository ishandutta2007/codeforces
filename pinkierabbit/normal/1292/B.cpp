#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 100000000000000000
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,ans;
ll x[100],y[100],ax,ay,bx,by;
ll xs,ys,t;
int main(){
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by,&xs,&ys,&t);
	n=0;
	while(x[n]<=(inf-bx)/ax&&y[n]<=(inf-by)/ay){
		x[n+1]=x[n]*ax+bx;
		y[n+1]=y[n]*ay+by;
		++n;
	}
//	F(i,0,n)printf("(%lld,%lld)\n",x[i],y[i]);
	F(i,0,n){
		ll z=abs(x[i]-xs)+abs(y[i]-ys);
		if(z>t)continue;
		int j=i;
		while(j>0&&z+abs(x[j-1]-x[j])+abs(y[j-1]-y[j])<=t)
			z+=abs(x[j-1]-x[j])+abs(y[j-1]-y[j]),--j;
//		printf("%d:%d\n",i,i-j+1);
		ans=max(ans,i-j+1);
	}
	F(i,0,n){
		ll z=abs(x[i]-xs)+abs(y[i]-ys);
		if(z>t)continue;
		int j=i;
		while(j<n&&z+abs(x[j+1]-x[j])+abs(y[j+1]-y[j])<=t)
			z+=abs(x[j+1]-x[j])+abs(y[j+1]-y[j]),++j;
//		printf("%d:%d\n",i,j-i+1);
		ans=max(ans,j-i+1);
	}
	printf("%d\n",ans);
	return 0;
}