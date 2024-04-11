#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
int n;
LL a[MAXN],b[MAXN],c[MAXN];

inline void Solve(){
	scanf("%d",&n);
	FOR(i,0,n-1) scanf("%lld%lld",a+i,b+i);
	FOR(i,0,n-1) c[i] = std::max(0ll,a[i]-b[(i-1+n)%n]);
	LL sm = 0;FOR(i,0,n-1) sm += c[i];
	LL ans = 1e18;
	FOR(i,0,n-1) ans = std::min(ans,sm-c[i]+a[i]);
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}