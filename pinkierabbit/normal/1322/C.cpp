#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define MM 500005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
inline T range(T l, T r) {
	return std::uniform_int_distribution<T>(l, r)(rng);
}

inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m;
ll a[MN],b[MN],c[MN];int p[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%lld",a+i),b[i]=range(0llu,ULLONG_MAX),c[i]=0,p[i]=i;
	F(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		c[y]^=b[x];
	}
//	F(i,1,n)printf("%llu,",c[i]);puts("");
	sort(p+1,p+n+1,[](int i,int j){return c[i]<c[j];});
	ll s=0,ans=0;
	F(i,1,n){if(c[p[i]]!=0)s+=a[p[i]];if(i==n||c[p[i]]!=c[p[i+1]])ans=__gcd(ans,s),s=0;}
	printf("%lld\n",ans);
}	return 0;
}