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

const int MAXN = 2e5 + 5;

int n,m;

struct Edge{
	int u,v,w;
	bool operator < (const Edge &t) const {
		return w > t.w;
	}
}e[MAXN];

int f[MAXN];
bool cir[MAXN];

inline int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
	std::sort(e+1,e+m+1);
	FOR(i,1,n) f[i] = i;
	LL ans = 0;
	FOR(i,1,m){
		int fx = find(e[i].u),fy = find(e[i].v);
		if(fx == fy && !cir[fx]){
			cir[fx] = 1;
			ans += e[i].w;
			continue;
		}
		if(!(cir[fx]&&cir[fy])){
			f[fx] = fy;
			cir[fy] |= cir[fx];
			ans += e[i].w;
		}
	}
	printf("%lld\n",ans);
	return 0;
}