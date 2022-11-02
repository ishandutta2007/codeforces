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

const int MAXN = 5e5 + 5;

int n,m,k;
int N;

std::vector<int> G[MAXN];
int dfn[MAXN],low[MAXN],st[MAXN],tp,tot,bel[MAXN],ts;
bool ins[MAXN];

inline void dfs(int v){
	dfn[v] = low[v] = ++ts;st[++tp] = v;ins[v] = 1;
	for(auto x:G[v]){
		if(!dfn[x]){
			dfs(x);
			low[v] = std::min(low[v],low[x]);
		}
		else if(ins[x]) low[v] = std::min(low[v],dfn[x]);
	}
	if(low[v] == dfn[v]){
		int t = -1;++tot;
		do{
			t = st[tp--];
			bel[t] = tot;
			ins[t] = 0;
		}while(t != v);
	}
}

inline int calc(int i,int j,int x){// ai >= j, true or false
	return ((i-1)*(k+2)+j+1)<<1|x;
}

inline void add(int x,int y){
	G[x].pb(y);
	G[y^1].pb(x^1);
//	printf("%d %d\n%d %d\n",x,y,y^1,x^1);
}

inline void Solve(){ts = tp = tot = 0;
	scanf("%d%d%d",&n,&m,&k);N = calc(n,k+1,1);
	FOR(i,1,N) G[i].clear(),dfn[i] = low[i] = bel[i] = ins[i] = 0;
	FOR(i,1,n){
		ROF(j,k,0){
			add(calc(i,j+1,1),calc(i,j,1));
		}
		add(calc(i,1,0),calc(i,1,1));
		add(calc(i,k+1,1),calc(i,k+1,0));
	}
	FOR(i,1,n-1) FOR(x,0,k+1) add(calc(i,x,1),calc(i+1,x,1));
	FOR(i,1,m){
		int o;scanf("%d",&o);
		if(o == 1){
			int x,v;scanf("%d%d",&x,&v);
			// x != v <==>  x >= v+1 || !(x >= v)
			add(calc(x,v+1,0),calc(x,v,0));
		}
		if(o == 2){
			int x,y,v;scanf("%d%d%d",&x,&y,&v);
			// x+y <= v
			FOR(xx,1,k){
				// y <= v-x <= v-xx
				//  x >= xx  y <= v-x <= v-xx <=> !(y>=v-xx+1)
				if(v-xx >= 1) add(calc(x,xx,1),calc(y,std::min(k+1,v-xx+1),0));
				else add(calc(x,xx,1),calc(x,xx,0));
			}
		}
		if(o == 3){
			int x,y,v;scanf("%d%d%d",&x,&y,&v);
			// x+y >= v
			FOR(xx,1,k){
				// y >= v-x
				//  x <= xx <=> !(x>=xx+1)  y >= v-x >= v-xx
				if(v-xx <= k) add(calc(x,xx+1,0),calc(y,std::max(0,v-xx),1));
				else add(calc(x,xx+1,0),calc(x,xx+1,1));
			}
		}
	}
	FOR(i,1,N) if(!dfn[i]) dfs(i);
/*	FOR(i,1,n){
		FOR(j,0,k+1){
			printf("%d %d\n",bel[calc(i,j,0)],bel[calc(i,j,1)]);
		}
	}*/
	FOR(i,1,n) FOR(j,0,k+1) if(bel[calc(i,j,0)] == bel[calc(i,j,1)]){
		puts("-1");
		return;
	}
	FOR(i,1,n){
		FOR(j,0,k+1){
//			DEBUG((bel[calc(i,j,0)] > bel[calc(i,j,1)]));
		}
		FOR(j,2,k+1) if(bel[calc(i,j,0)] < bel[calc(i,j,1)]){
			printf("%d ",j-1);
			break;
		}
	}
	puts("");
}

int main(){
	int T;scanf("%d",&T);
	while(T--) Solve();
	return 0;
}