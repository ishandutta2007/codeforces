#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 200000+5;

std::priority_queue<int,std::vector<int>,std::greater<int> > q;
int head[MAXN];

struct Edge{
    int to,next;
}e[MAXN<<1];
int cnt;
inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}
bool vis[MAXN];

inline void bfs(){
    q.push(1);CLR(vis,false);
    while(!q.empty()){
        int v = q.top();q.pop();
        //if(vis[v]) continue;
        printf("%d ",v);vis[v] = true;
        for(int i = head[v];i;i = e[i].next){
            if(!vis[e[i].to]) q.push(e[i].to),vis[e[i].to] = true;
        }
    }
}

int main(){
    int N,M;scanf("%d%d",&N,&M);
    FOR(i,1,M){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    bfs();
    return 0;
}