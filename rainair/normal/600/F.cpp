#include<bits/stdc++.h>

#define fi first
#define se second
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

const int MAXN = 1000+5;
const int MAXM = 2e5 + 5;
int f[2][MAXN][MAXN];//   
int du[2][MAXN];
int g[MAXN][MAXN];
int ans[MAXM];

inline void work(int a,int b,int u,int v,int x,int y){
	//  (x,y) 
	int to = f[b][v][x];
	f[a][u][x] = v;f[b][v][x] = u;
	if(!to) f[b][v][y] = 0;
	else work(b,a,v,to,y,x);
}

int main(){
	int a,b,m;
	scanf("%d%d%d",&a,&b,&m);
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		g[u][v] = i;
		du[0][u]++;du[1][v]++;
		int t0=1,t1=1;
		while(f[0][u][t0]) ++t0;
		while(f[1][v][t1]) ++t1;
		if(t0 == t1) f[0][u][t0] = v,f[1][v][t1] = u;
		else work(0,1,u,v,t0,t1);
	}
	int mx = 0;
	FOR(i,1,a) mx = std::max(mx,du[0][i]);
	FOR(i,1,b) mx = std::max(mx,du[1][i]);
	FOR(i,1,a){
		FOR(j,1,mx){
			if(f[0][i][j]) ans[g[i][f[0][i][j]]] = j;
		}
	}
	printf("%d\n",mx);
	FOR(i,1,m) printf("%d ",ans[i]);puts("");
	return 0;
}