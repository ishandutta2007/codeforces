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

int n,m;
int p[MAXN],c[MAXN];

inline void Solve(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%d",p+i);
	std::sort(p+1,p+n+1);
	FOR(i,1,m) scanf("%d",c+i);
	int l = 1,r = n;LL ans = 0;
	FOR(i,1,m){
		while(l <= r && p[l] == i) ans += c[i],++l;
		if(l <= r) --r,ans += c[i];
	}
	printf("%lld\n",ans);
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}