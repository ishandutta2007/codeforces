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

const int MAXN = 1e5+5;

struct Edge{
	int to,w,c,nxt;
}e[MAXN<<1];
int head[MAXN],cnt = 1;

inline void add(int u,int v,int w,int c){
	e[++cnt] = (Edge){v,w,c,head[u]};head[u] = cnt;
	e[++cnt] = (Edge){u,0,-c,head[v]};head[v] = cnt;
}

bool inq[MAXN];
int dis[MAXN],pre[MAXN];
int S,T,N;

inline bool spfa(){
	std::queue<int> q;
	FOR(i,0,N) dis[i] = 1e9,pre[i] = -1;
	q.push(S);dis[S] = 0;pre[S] = 0;inq[S] = 1;
	while(!q.empty()){
		int v = q.front();q.pop();inq[v] = 0;
		for(int i = head[v];i;i = e[i].nxt){
			if(e[i].w > 0 && dis[e[i].to] > dis[v]+e[i].c){
				dis[e[i].to] = dis[v]+e[i].c;pre[e[i].to] = i;
				if(!inq[e[i].to]) q.push(e[i].to),inq[e[i].to] = 1;
			}
		}
	}
	return pre[T] != -1;
}

int maxFlow,minCost;

inline void work(){
	while(spfa()){
		int v = T,flow = 1e9;
		while(v != S){
			flow = std::min(flow,e[pre[v]].w);
			v = e[pre[v]^1].to;
		}
		maxFlow += flow;v = T;
		while(v != S){
			minCost += flow*e[pre[v]].c;
			e[pre[v]].w -= flow;e[pre[v]^1].w += flow;
			v = e[pre[v]^1].to;
		}
	}
}

int n1,n2,m,r,b;
char str[MAXN];
int du[MAXN];// -
int edge[MAXN];

int main(){
	scanf("%d%d%d%d%d",&n1,&n2,&m,&r,&b);
	int s = n1+n2+1,t = s+1;S = t+1;T = N = S+1;
	scanf("%s",str+1);
	FOR(i,1,n1){
		if(str[i] == 'R'){// (s,i,[1,inf],0)
			du[s]++;du[i]--;
			add(s,i,1e9,0);
		}
		else if(str[i] == 'B'){ // (i,t,[1,inf],0)
			du[i]++;du[t]--;
			add(i,t,1e9,0);
		}
		else{
			add(s,i,1e9,0);add(i,t,1e9,0);
		}
	}
	scanf("%s",str+1);
	FOR(i,1,n2){
		if(str[i] == 'R'){// (i,t,[1,inf],0)
			du[i+n1]++;du[t]--;
			add(i+n1,t,1e9,0);
		}
		else if(str[i] == 'B'){ // (s,i,[1,inf],0)
			du[s]++;du[i+n1]--;
			add(s,i+n1,1e9,0);
		}
		else{
			add(s,i+n1,1e9,0);add(i+n1,t,1e9,0);
		}
	}
	add(t,s,1e9,0);
	FOR(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		edge[i] = cnt+1;
		add(u,v+n1,1,r);
		add(v+n1,u,1,b);
	}
	int sm = 0;
	FOR(i,1,N-2){
		if(du[i] > 0) add(i,T,du[i],0);
		else add(S,i,-du[i],0),sm -= du[i];
	}
	work();
	// DEBUG(maxFlow);DEBUG(sm);
	if(maxFlow != sm) {puts("-1");exit(0);}
	else printf("%d\n",minCost);
	FOR(i,1,m){
		if(!e[edge[i]].w) putchar('R');
		else if(!e[edge[i]+2].w) putchar('B');
		else putchar('U');
	}
	return 0;
}