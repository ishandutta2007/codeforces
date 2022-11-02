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

const int MAXN = 5e5 + 5;

struct Edge{
	int to,w,nxt;
}e[MAXN];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
	e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
}

int n,m;
int vis[MAXN];
int t0[MAXN],t1[MAXN],dis[MAXN];

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,m){
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		add(v,u,1<<w);
	}
	CLR(dis,0x3f);CLR(t0,0x3f);CLR(t1,0x3f);
	std::queue<int> q;dis[n] = t0[n] = t1[n] = 0;q.push(n);
	while(!q.empty()){
		int v = q.front();q.pop();
		dis[v] = std::max(t0[v],t1[v]);
		for(int i = head[v];i;i = e[i].nxt){
			if(vis[e[i].to]&e[i].w) continue;
			if(e[i].w == 1) t0[e[i].to] = dis[v]+1;
			else t1[e[i].to] = dis[v]+1;
			vis[e[i].to] |= e[i].w;
			if(vis[e[i].to] == 3) q.push(e[i].to);
		}
	}
	printf("%d\n",dis[1]>1e9?-1:dis[1]);
	FOR(i,1,n){
		putchar(t0[i]>t1[i]?'0':'1');
	}
	puts("");
	return 0;
}