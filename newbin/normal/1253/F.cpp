#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define P pair<ll, int>
using namespace std;
const int maxn = 3e5 + 50;
struct edge{
    int u ,v , nxt;
    ll w;
    bool operator < (const edge &a)const{return w < a.w;}
}e[maxn*2];
int cnt = 0;
int head[maxn];
void add(int u, int v, ll w){
    e[cnt] = (edge){u, v, head[u], w};
    head[u] = cnt++;
}
int n, m, k, Q;
priority_queue<P, vector<P>, greater<P> > q;
ll dis[maxn];
void dij(){
    while(q.size()){
        P temp = q.top();q.pop();
        int u = temp.second;
        if(dis[u] < temp.first) continue;
        for(int i = head[u]; ~i; i = e[i].nxt){
            int v = e[i].v; ll w = e[i].w;
            if(dis[v] > dis[u] + w){
                dis[v] = dis[u] + w;
                q.push(P(dis[v], v));
            }
        }
    }
}
void init(){
    memset(head, -1, sizeof head);
    cin>>n>>m>>k>>Q;
    for(int i = 0; i < m; ++i){
        int u, v; ll w; scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    memset(dis, 0x3f, sizeof dis);
    for(int i = 1; i <= k; ++i){
        dis[i] = 0; q.push(P(0, i));
    }dij();
    int tp = 0;
    for(int i = 0; i < cnt; i += 2){
        e[tp] = e[i];
        e[tp++].w += dis[e[i].u]+dis[e[i].v];
    }
    cnt = tp;
}
ll ans[maxn];
int fa[maxn*2];
int fnd(int x){
    if(x == fa[x]) return x;
    return fa[x] = fnd(fa[x]);
}
int tot;
vector<int> g[maxn];
ll val[maxn];
int f[maxn][20], dep[maxn];
void get_mst(){
    tot = n;
    for(int i = 0; i <cnt; ++i){
        int u = e[i].u; int v = e[i].v;
        u = fnd(u); v = fnd(v); if(u == v) continue;
        fa[u] = fa[v] = ++tot; fa[tot] = tot; val[tot] = e[i].w;
        g[tot].push_back(v); f[v][0] = tot;
        g[tot].push_back(u); f[u][0] = tot;
    }
}
void dfs(int u){
    for(int i = 0; i+1 < 20; ++i) f[u][i+1] = f[f[u][i]][i];
    for(int i = 0; i < g[u].size(); ++i) dep[g[u][i]] =dep[u]+1, dfs(g[u][i]);
}
int lca(int u, int v){
    if(dep[u] > dep[v]) swap(u, v);
    int d = dep[v] - dep[u]; for(int i = 19; i >= 0; --i) if(d>>i&1) v = f[v][i];
    if(u == v) return u;
    for(int i = 19; i >= 0; --i){
        if(f[u][i] == f[v][i]) continue;
        u = f[u][i]; v = f[v][i];
    }return f[u][0];
}
void sol(){
    for(int i = 1; i <= n; ++i) fa[i] = i;
    sort(e, e+cnt);
    get_mst();
    dfs(tot);
    while(Q--){
        int u, v; scanf("%d%d", &u, &v);
        printf("%lld\n", val[lca(u,v)]);
    }
}
int main()
{
    init();
    sol();
}