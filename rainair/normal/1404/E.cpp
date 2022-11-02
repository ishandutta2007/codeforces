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

const int MAXN = 200+5;
char str[MAXN][MAXN];
int n,m;

namespace Flow{
	const int MAXM = 2e5 + 5;
    struct Edge{
        int to,w,nxt;
    }e[MAXM<<3];
    int head[MAXM],cur[MAXM],cnt=1;
    int dep[MAXM];
    int S,T,N;

    inline void add(int u,int v,int w){
        e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
        e[++cnt] = (Edge){u,0,head[v]};head[v] = cnt;
    }

    inline bool bfs(){
        FOR(i,0,N) cur[i] = head[i],dep[i] = 0;
        std::queue<int> q;q.push(S);dep[S] = 1;
        while(!q.empty()){
            int v = q.front();q.pop();
            for(int i = head[v];i;i = e[i].nxt){
                if(e[i].w > 0 && !dep[e[i].to]){
                    dep[e[i].to] = dep[v] + 1;
                    if(e[i].to == T) return true;
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
            if(e[i].w > 0 && dep[e[i].to] == dep[v] + 1){
                int t = dfs(e[i].to,std::min(flow,e[i].w));
                if(t>0){
                    ans += t;flow -= t;
                    e[i].w -= t;e[i^1].w += t;
                    if(!flow) break;
                }
            }
        }
        return ans;
    }

    inline int Dinic(){
        int ans = 0,t = 0;
        while(bfs()) while((t=dfs(S))) ans += t;
        return ans;
    }
};

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

inline int id(int i,int j){
	return (i-1)*m+j;
}

int main(){
	scanf("%d%d",&n,&m);
	FOR(i,1,n) scanf("%s",str[i]+1);
	Flow::T = Flow::N = n*m+2;Flow::S = n*m+1;
	FOR(i,1,n){
		FOR(j,1,m){
			if(str[i][j] == '.') continue;
			int c1=0,c2=0;
			FOR(k,0,3){
				int ii = i+dx[k],jj = j+dy[k];
				if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && str[ii][jj] == '#'){
					Flow::add(id(i,j),id(ii,jj),1);
				}
				else{
					if(k <= 1) c1++;
					else c2++;
				}
			}
			Flow::add(Flow::S,id(i,j),c1);Flow::add(id(i,j),Flow::T,c2);
		}
	}
	// FOR(i,1,n) FOR(j,1,m){
		// if((i+j)&1) Flow::add(id(i,j),Flow::T,1e9);
		// else Flow::add(Flow::S,id(i,j),1e9);
	// }
	printf("%d\n",Flow::Dinic()/2);
	return 0;
}