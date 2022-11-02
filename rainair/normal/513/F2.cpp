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

const int MAXN = 22 + 5;
const int MAXM = 2e5 + 5;
int n,m;
char str[MAXN][MAXN];

inline int id(int i,int j){
	return (i-1)*m+j;
}

int dis[MAXN*MAXN][MAXN*MAXN];
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};

inline void bfs(P v,int dis[]){
	FOR(i,1,n*m) dis[i] = 1e9+114514;
	dis[id(v.fi,v.se)] = 0;std::queue<P> q;q.push(v);
	while(!q.empty()){
		P v = q.front();q.pop();
		if(str[v.fi][v.se] == '#') continue;
		FOR(k,0,3){
			int xx = v.fi+dx[k],yy = v.se+dy[k];
			if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && str[xx][yy] != '#' && dis[id(xx,yy)] > 1e9){
				dis[id(xx,yy)] = dis[id(v.fi,v.se)]+1;
				q.push(MP(xx,yy));
			}
		}
	}
}

struct Node{
	int x,y,z;LL t;
	Node(int x=0,int y=0,int z=0,LL t=0) : x(x),y(y),z(z),t(t) {}
	
	inline bool operator < (const Node &_) const {
		return t < _.t;
	}
};

Node B[MAXM],G[MAXM];
int k;

namespace F{
	struct Edge{
		int to,w,nxt;
	}e[MAXM<<5];
	int S,T,N;
	int head[MAXM],cur[MAXM],cnt = 1,dep[MAXM];
	int ans = 0;
	
	inline void clear(){
		FOR(i,1,N) head[i] = cur[i] = 0;cnt = 1;ans = 0;
	}
	
	inline void add(int u,int v,int w){
		// printf("%d %d %d\n",u,v,w);
		e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
		e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
	}
	
	inline bool bfs(){
		FOR(i,0,N) cur[i] = head[i],dep[i] = 0;
		// DEBUG(cur[1]);DEBUG(head[1]);
		std::queue<int> q;q.push(S);dep[S] = 1;
		while(!q.empty()){
			int v = q.front();q.pop();
			for(int i = head[v];i;i = e[i].nxt){
				if(e[i].w > 0 && !dep[e[i].to]){
					dep[e[i].to] = dep[v]+1;
					if(e[i].to == T) return 1;
					q.push(e[i].to);
				}
			}
		}
		return dep[T];
	}
	
	inline int dfs(int v,int flow=1e9){
		if(v == T) return flow;
		if(!flow) return 0;
		int ans = 0;
		for(int &i = cur[v];i;i = e[i].nxt){
			if(e[i].w > 0 && dep[e[i].to] == dep[v]+1){
				int t = dfs(e[i].to,std::min(e[i].w,flow));
				if(t>0){
					e[i].w -= t;e[i^1].w += t;flow -= t;ans += t;
					if(!flow) return ans;
				}
			}
		}
		if(!ans) dep[v] = 0;
		return ans;
	}
	
	inline void Dinic(){
		int flow;
		while(bfs()){
			while((flow=dfs(S))) ans += flow;
			// exit(0);
		}
	}
}

std::vector<Node> edge[MAXM],tmp;
int ts[MAXM];
std::mt19937 g32(114514);

inline bool chk(LL lim){
    F::clear();
    F::N = 2*n*m+2*k+2;F::S = F::N-1;F::T = F::N;
	FOR(i,1,k) F::add(F::S,2*n*m+i,1),F::add(2*n*m+k+i,F::T,1);
	FOR(i,1,n) FOR(j,1,m) F::add(id(i,j),n*m+id(i,j),1);
	FOR(i,1,k){
		FOR(x,1,n){
			FOR(y,1,m){
				if(dis[id(B[i].x,B[i].y)][id(x,y)] > 1e9) continue;
				LL d = 1ll*dis[id(B[i].x,B[i].y)][id(x,y)]*B[i].z;
                if(d > lim) continue;
                F::add(n*m+id(x,y),2*n*m+k+i,1);
			}
		}
		FOR(x,1,n){
			FOR(y,1,m){
				if(dis[id(G[i].x,G[i].y)][id(x,y)] > 1e9) continue;
				LL d = 1ll*dis[id(G[i].x,G[i].y)][id(x,y)]*G[i].z;
                if(d > lim) continue;
                F::add(2*n*m+i,id(x,y),1);
			}
		}
	}
    F::Dinic();
    return F::ans==k;
}

int main(){
	int b,g;
	scanf("%d%d%d%d",&n,&m,&b,&g);
	if(std::abs(b-g) != 1){
		puts("-1");
		return 0;
	}
	FOR(i,1,n) scanf("%s",str[i]+1);
	FOR(i,1,n) FOR(j,1,m) bfs(MP(i,j),dis[id(i,j)]);
	int _,__,___;scanf("%d%d%d",&_,&__,&___);
	FOR(i,1,b) scanf("%d%d%d",&B[i].x,&B[i].y,&B[i].z);
	FOR(i,1,g) scanf("%d%d%d",&G[i].x,&G[i].y,&G[i].z);
	k = std::max(b,g);
	if(b < g) B[k] = Node(_,__,___);
	else G[k] = Node(_,__,___);
    LL l = 0,r = 1e18,ans = -1;
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%lld\n",ans);
	return 0;
}