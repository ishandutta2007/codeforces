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
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	ll p; int q;
	scanf("%lld%d",&p,&q);
	if(p%q!=0){printf("%lld\n",p);continue;}
	ll ans=0;
	int x=q; ll y=p;
	for(int i=2;i*i<=x;++i)if(x%i==0){
		int k=1; ll w=1;
		while(x%i==0)x/=i,k*=i;
		while(y%i==0)y/=i,w*=i;
		ans=max(ans,p/w*(k/i));
	}
	if(x>1){
		int i=x;
		int k=1; ll w=1;
		while(x%i==0)x/=i,k*=i;
		while(y%i==0)y/=i,w*=i;
		ans=max(ans,p/w*(k/i));
	}
	printf("%lld\n",ans);
}	return 0;
}