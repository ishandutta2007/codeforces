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


typedef long long LL;
const int Mod = 998244353;
const int G = 3, iG = 332748118;
const int MS = 1 << 18;

inline int qPow(int b, int e) {
	int a = 1;
	for (; e; e >>= 1, b = (LL)b * b % Mod)
		if (e & 1) a = (LL)a * b % Mod;
	return a;
}

inline int gInv(int b) { return qPow(b, Mod - 2); }

int Inv[MS], Fac[MS], iFac[MS];

inline void Init(int N) {
	Fac[0] = 1;
	for (int i = 1; i < N; ++i) Fac[i] = (LL)Fac[i - 1] * i % Mod;
	iFac[N - 1] = gInv(Fac[N - 1]);
	for (int i = N - 1; i >= 1; --i) iFac[i - 1] = (LL)iFac[i] * i % Mod;
	for (int i = 1; i < N; ++i) Inv[i] = (LL)Fac[i - 1] * iFac[i] % Mod;
}


ll n;
int t,c[MN];
ll p[MN];
map<ll,int>mp;
void dfs(int i,ll v,int s,ll x){
	if(i>t)return mp[v]=x*Fac[s]%mod,void();
	for(int j=0;j<=c[i];++j,v*=p[i])dfs(i+1,v,s+j,(ll)x*iFac[j]%mod);
}
int main(){
	scanf("%lld",&n);
	for(ll i=2;i*i<=n;++i)if(n%i==0){
		p[++t]=i;
		while(n%i==0)++c[t],n/=i;
	}if(n>1)p[++t]=n,c[t]=1;
	Init(100000);
	dfs(1,1,0,1);
	int q;
	scanf("%d",&q);
	while(q--){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		ll d=__gcd(a,b);
		a/=d,b/=d;
		printf("%lld\n",(ll)mp[a]*mp[b]%mod);
	}
	return 0;
}