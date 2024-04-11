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

const int MAXN = 1e5 + 5;
int t,T,n,m;
std::vector<int> G[MAXN];
int l[MAXN],r[MAXN];
int col[MAXN];bool vis[MAXN];
bool flag = 1;
std::vector<int> S;

inline void dfs(int v){
	vis[v] = 1;S.pb(v);
	for(auto x:G[v]){
		if(vis[x]){
			flag &= (col[x]^col[v]);
		}
		else{
			col[x] = col[v]^1;
			dfs(x);
		}
	}
}

int main(){
	scanf("%d%d%d%d",&t,&T,&n,&m);
	FOR(i,1,n) scanf("%d%d",l+i,r+i);
	int mx = -1e9,mn = 1e9;
	FOR(i,1,n) mx = std::max(mx,l[i]),mn = std::min(mn,r[i]);
	// DEBUG(mx);DEBUG(mn);
	while(mx+mn > T) mn--;
	while(mx+mn < t) mx++;
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		G[u].pb(v);G[v].pb(u);
	}
	// 1 = mx
	// 2 = mn
	FOR(i,1,n){
		if(vis[i]) continue;
		S.clear();dfs(i);
		if(!flag){
			puts("IMPOSSIBLE");
			return 0;
		}
		int l1=0,r1=1e9,l2=0,r2=1e9;
		for(auto x:S){
			if(col[x]){
				l2 = std::max(l2,l[x]);
				r2 = std::min(r2,r[x]);
			}
			else{
				l1 = std::max(l1,l[x]);
				r1 = std::min(r1,r[x]);
			}
		}
		if(l1 <= mx && mx <= r1 && l2 <= mn && mn <= r2){
			continue;
		}
		l1=0,r1=1e9,l2=0,r2=1e9;
		for(auto x:S){
			col[x] ^= 1;
			if(col[x]){
				l2 = std::max(l2,l[x]);
				r2 = std::min(r2,r[x]);
			}
			else{
				l1 = std::max(l1,l[x]);
				r1 = std::min(r1,r[x]);
			}
		}
		if(l1 <= mx && mx <= r1 && l2 <= mn && mn <= r2){
			continue;
		}
		puts("IMPOSSIBLE");return 0;
	}
	puts("POSSIBLE");
	printf("%d %d\n",mx,mn);
	FOR(i,1,n) putchar(col[i]?'2':'1');puts("");
	return 0;
}