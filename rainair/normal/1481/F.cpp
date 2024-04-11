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

const int MAXN = 1e5 + 5;
int n,x;
std::vector<int> G[MAXN];
int dep[MAXN],cnt[MAXN];
bool leaf[MAXN];

inline void dfs(int v,int fa=0){
	dep[v] = dep[fa]+1;
	++cnt[dep[v]];
	leaf[v] = 1;
	for(auto x:G[v]){
		if(x == fa) continue;
		dfs(x,v);leaf[v] = 0;
	}
}

bool f[455][MAXN];
int ps[MAXN],pre[455][MAXN];
std::vector<P<int,int> > S;
std::vector<int> D[MAXN];
bool res[MAXN];
// std::mt19937 g(123123);
int main(){
	scanf("%d%d",&n,&x);
// 	n = 1e5;x = g()%(n+1);
	FOR(i,2,n){
		int p;scanf("%d",&p);
// 		int p = 1+g()%(i-1);
		G[p].pb(i);
	}
	dfs(1);
	f[0][0] = 1;
	int mxd = 0;
	FOR(i,1,n) if(cnt[i]) D[cnt[i]].pb(i),mxd = i;
	FOR(i,1,n) if(SZ(D[i])) S.pb(i,SZ(D[i]));
	FOR(i,1,SZ(S)){
		int c = S[i-1].se,x = S[i-1].fi;
		FOR(j,0,n){
			if(f[i-1][j]){
				ps[j] = j;
				pre[i][j] = j;
				f[i][j] = 1;
				continue;
			}
			ps[j] = j-x < 0 ? -1e9 : ps[j-x];
			pre[i][j] = ps[j];
			if(ps[j] >= j-c*x) f[i][j] = 1;
		}
	}
	if(f[SZ(S)][x]){
		printf("%d\n",mxd);
		int now = x;
		ROF(i,SZ(S),1){
			int c = (now-pre[i][now])/S[i-1].fi;
			FOR(j,0,c-1) res[D[S[i-1].fi][j]] = 1;
			now = pre[i][now];
		}
		FOR(i,1,n) putchar(res[dep[i]]?'a':'b');puts("");
		return 0;
	}
	printf("%d\n",mxd+1);
	FOR(i,1,n) D[i].clear();
	FOR(i,1,n) D[dep[i]].pb(i);
	int ra = x,rb = n-x;
	FOR(i,1,mxd){
		if(ra >= SZ(D[i])){
			for(auto x:D[i]) res[x] = 1;
			ra -= SZ(D[i]);
		}
		else if(rb >= SZ(D[i])){
			for(auto x:D[i]) res[x] = 0;
			rb -= SZ(D[i]);
		}
		else{
			// nonleaf is equal
			// nonleaf <= remain/2 <= max(ra,rb)
			int ta = ra,tb = rb;
			for(auto x:D[i]){
				if(ta > tb){
					if(leaf[x]){
						if(rb) res[x] = 0,--rb;
						else res[x] = 1,--ra;
					}
					else{
						res[x] = 1;--ra;
					}
				}
				else{
					if(leaf[x]){
						if(ra) res[x] = 1,--ra;
						else res[x] = 0,--rb;
					}
					else{
						res[x] = 0;--rb;
					}
				}
			}
		}
	}
	FOR(i,1,n) putchar(res[i]?'a':'b');puts("");
	return 0;
}