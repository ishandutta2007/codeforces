#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;

std::vector<int> vec[MAXN],tvec[MAXN];
int bel[MAXN];
int ps[MAXN],n,q,s,d,tot;
int arr[MAXN];

std::set<int> S;
int id[1000003];
std::vector<P<int,int> > G[MAXN];

int lim[MAXN];

inline void dfs(int v,int fa=0){
	for(auto x:G[v]){
		if(x.fi == fa) continue;
		lim[x.fi] = std::max(lim[v],x.se);
		dfs(x.fi,v);
	}
}

inline int calc(int x,int y){
	int dis = std::abs(ps[x]-ps[y]);
	return std::abs(dis-d);
}

inline int getmin(int x){
	P<int,int> res = MP(1e9,0);
	auto p = S.lower_bound(ps[x]-d);
	if(p != S.end()) res = std::min(res,MP(calc(x,id[*p]),*p));
	if(p != S.begin()){
		--p;
		res = std::min(res,MP(calc(x,id[*p]),*p));
	}
	p = S.lower_bound(ps[x]+d);
	if(p != S.end()) res = std::min(res,MP(calc(x,id[*p]),*p));
	if(p != S.begin()){
		--p;
		res = std::min(res,MP(calc(x,id[*p]),*p));
	}
	return id[res.se];
}

int f[MAXN];

inline int find(int x){
	return x == f[x] ? x : f[x] = find(f[x]);
}

inline bool merge(int x,int y){
	x = find(x);y = find(y);
	if(x == y) return 0;
	f[x] = y;return 1;
}

int tmp[MAXN];

int main(){
	scanf("%d%d%d%d",&n,&q,&s,&d);
	FOR(i,1,n) scanf("%d",ps+i),id[ps[i]] = i;
	FOR(i,1,n) bel[i] = i,vec[i].pb(i);tot = n;
	FOR(i,1,n) S.insert(ps[i]);
	while(tot > 1){
		FOR(i,1,tot) f[i] = i;
		FOR(i,1,tot){
			for(auto x:vec[i]) S.erase(ps[x]);
			int mn = 1e9,pu = -1,pv = -1;
			for(auto x:vec[i]){
				// weight = |dis - d|
				int to = getmin(x);
				if(mn > calc(to,x)){
					pu = x;pv = to;mn = calc(x,to);
				}
			}
			if(merge(bel[pu],bel[pv])){
				G[pu].pb(pv,mn);G[pv].pb(pu,mn);
			}
			//printf("%d %d %d\n",pu,pv,mn);
			// link (i,bel[to],mn)
			for(auto x:vec[i]) S.insert(ps[x]);
		}
		//puts("");
		FOR(i,1,tot) tmp[i] = 0,tvec[i] = vec[i],vec[i].clear();
		int t = tot;tot = 0;
		FOR(i,1,t){
			if(!tmp[find(i)]) tmp[find(i)] = ++tot;
			vec[tmp[find(i)]].insert(vec[tmp[find(i)]].end(),all(tvec[i]));
		}
		FOR(i,1,tot) for(auto x:vec[i]) bel[x] = i;
		//FOR(i,1,n) printf("%d ",bel[i]);puts("");
	}
	dfs(s);
//	FOR(i,1,n) DEBUG(lim[i]);
	FOR(i,1,q){
		int to,k;scanf("%d%d",&to,&k);
		puts(k >= lim[to] ? "YES" : "NO");
	}
	return 0;
}