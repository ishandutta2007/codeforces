#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define pf emplace_front
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 100 + 5;
const int ha = 998244353;
int n,x[MAXN],y[MAXN];
int id[MAXN];

inline int dis(int i,int j){
	return std::abs(x[i]-x[j]) + std::abs(y[i]-y[j]);
}

int now;

inline bool cmp(int x,int y){
	return dis(now,x) < dis(now,y);
}

std::vector<int> G[MAXN],S;
bool vis[MAXN];
std::vector<int> vec;

inline void dfs(int v){
	vis[v] = 1;S.pb(v);
	for(auto x:G[v]){
		if(vis[x]) continue;
		dfs(x);
	}
}

int f[2][MAXN];
int used;

inline void add(int &x,int y){
	x += y-ha;x += x>>31&ha;
}

int main(){
	scanf("%d",&n);FOR(i,1,n) scanf("%d%d",x+i,y+i),id[i] = i;
	FOR(i,1,n){
		now = i;std::sort(id+1,id+n+1,cmp);
		G[i].pb(id[2]);
		FOR(j,3,n){
			if(dis(i,id[j]) != dis(i,id[j-1])) break;
			G[i].pb(id[j]);
		}
	}
	// size = 2
	FOR(i,1,n) FOR(j,i+1,n){
		if(SZ(G[i]) == 1 && SZ(G[j]) == 1 && G[i][0] == j && G[j][0] == i){
			used += 2;
			vec.pb(2);
		}
	}
	FOR(i,1,n) std::sort(all(G[i]));
	// size = 3
	FOR(i,1,n) if(SZ(G[i]) == 2){
		FOR(j,i+1,n) if(SZ(G[j]) == 2){
			FOR(k,j+1,n) if(SZ(G[k]) == 2){
				bool flag = 1;
				FOR(x,0,1) flag &= (G[i][x] == i || G[i][x] == j || G[i][x] == k);
				FOR(x,0,1) flag &= (G[j][x] == i || G[j][x] == j || G[j][x] == k);
				FOR(x,0,1) flag &= (G[k][x] == i || G[k][x] == j || G[k][x] == k);
				if(flag){
					vec.pb(3);
					used += 3;
				}
			}
		}
	}
	// size = 4
	FOR(i,1,n) if(SZ(G[i]) == 3){
		FOR(j,i+1,n) if(SZ(G[j]) == 3){
			FOR(k,j+1,n) if(SZ(G[k]) == 3){
				FOR(l,k+1,n) if(SZ(G[l]) == 3){
					bool flag = 1;
					FOR(x,0,2) flag &= (G[i][x] == i || G[i][x] == j || G[i][x] == k || G[i][x] == l);
					FOR(x,0,2) flag &= (G[j][x] == i || G[j][x] == j || G[j][x] == k || G[j][x] == l);
					FOR(x,0,2) flag &= (G[k][x] == i || G[k][x] == j || G[k][x] == k || G[k][x] == l);
					FOR(x,0,2) flag &= (G[l][x] == i || G[l][x] == j || G[l][x] == k || G[l][x] == l);
					if(flag){
						vec.pb(4);
						used += 4;
					}
				}
			}
		}
	}
	FOR(i,1,n-used) vec.pb(1);
	f[now = 0][0] = 1;
	for(auto x:vec){
		CLR(f[now^1],0);
		FOR(i,0,n){
			if(!f[now][i]) continue;
			add(f[now^1][i+x],f[now][i]);
			if(x != 1) add(f[now^1][i+1],f[now][i]);
		}
		now ^= 1;
	}
	int ans = 0,fac = 1;
	FOR(i,1,n){
		fac = 1ll*fac*(n-i+1)%ha;
		if(!f[now][i]) continue;
		add(ans,1ll*fac*f[now][i]%ha);
	}
	printf("%d\n",ans);
	return 0;
}