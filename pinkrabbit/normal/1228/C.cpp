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
#define mod 1000000007
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
inline ll qpow(ll b,ll e){ll a=1;for(;e;e>>=1,b=b*b%mod)if(e&1)a=a*b%mod;return a;}
int x;ll n;
int p[55],c;
int main(){
	scanf("%d%lld",&x,&n);
	for(int i=2;i*i<=x;++i)if(x%i==0){p[++c]=i;while(x%i==0)x/=i;}if(x>1)p[++c]=x;
	ll ans=1;
	F(i,1,c){ll d=0;for(ll j=n/p[i];j;j/=p[i])d+=j;ans=ans*qpow(p[i],d)%mod;}
	printf("%lld\n",ans);
	return 0;
}