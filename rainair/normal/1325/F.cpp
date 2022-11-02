#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

const int MAXN = 2e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;
int dep[MAXN];bool vis[MAXN];
int n,m;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}
int lim;
int fa[MAXN];

inline void dfs(int v,int fa=0){
    vis[v] = 1;dep[v] = dep[fa]+1;::fa[v] = fa;
    for(int i = head[v];i;i = e[i].nxt){
        if(!vis[e[i].to]){
            dfs(e[i].to,v);
        }
        else if(dep[e[i].to] > dep[v]){
            if(dep[e[i].to]-dep[v]+1 >= lim){
                int t = e[i].to;
                printf("2\n%d\n",dep[e[i].to]-dep[v]+1);
                while(t != ::fa[v]) printf("%d ",t),t = ::fa[t];
                puts("");
                exit(0);
            }
        }
    }
}

int id[MAXN];

inline bool cmp(int x,int y){
    return dep[x] > dep[y];
}

int tag[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    lim = std::ceil(std::sqrt(1.0*n));
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs(1);
    FOR(i,1,n) id[i] = i;
    std::sort(id+1,id+n+1,cmp);
    FOR(v,1,n){
        if(tag[id[v]] == 2) continue;
        tag[id[v]] = 1;
        for(int i = head[id[v]];i;i = e[i].nxt) tag[e[i].to] = 2;
    }
    std::vector<int> ans;FOR(i,1,n) if(tag[i] == 1) ans.pb(i);
    printf("%d\n",1);
    FOR(i,1,lim) printf("%d ",ans[i-1]);puts("");
    return 0;
}