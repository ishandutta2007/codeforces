#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 305
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
int n;ll k,ans;
ll fac[MN],ifac[MN];
inline ll qpow(ll b,ll e){ll a=1;for(;e;e>>=1,b=b*b%mod)if(e&1)a=a*b%mod;return a;}
inline ll binom(int n,int m){if(m<0||m>n)return 0;return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){
	scanf("%d%lld",&n,&k);
	fac[0]=1;
	F(i,1,n)fac[i]=fac[i-1]*i%mod;
	F(i,0,n)ifac[i]=qpow(fac[i],mod-2);
	if(k==1)return puts("1"),0;
	F(i,0,n)F(j,0,n)ans=(ans+((i+j)&1?-1:1)*(qpow(k,(n-i)*(n-j))*qpow(k-1,n*n-(n-i)*(n-j))%mod)%mod*binom(n,i)%mod*binom(n,j))%mod/*,printf("%d,%d : %lld\n",i,j,(qpow(k,(n-i)*(n-j))*qpow(k-1,n*n-(n-i)*(n-j))%mod)%mod)*/;
	printf("%lld\n",(ans+mod)%mod);
	return 0;
}