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
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,p,k,x,y,a[MN];
ll f[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d",&n,&p,&k);
	F(i,1,n)scanf("%1d",a+i);
	scanf("%d%d",&x,&y);
	ll ans=infll;
	dF(i,n,p){
		f[i]=a[i]?0:x;
		if(i+k<=n)f[i]+=f[i+k];
		ans=min(ans,f[i]+(ll)(i-p)*y);
	}
	printf("%lld\n",ans);
}	return 0;
}