#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lowbit(x) ((x)&(-(x)))
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define fors(i, a, b) for(int i = (a); i < (b); ++i)
using namespace std;
const int maxn = 2e5 + 5;
ll lim;
int n, q;
#define P pair<ll,int>
struct edge{int u, v; ll w;}e[maxn];
vector<P> g[maxn];
int dfn[maxn], idx = 0, fa[maxn], in[maxn], out[maxn];
ll dep[maxn];
void pre_dfs(int u){
    dfn[++idx] = u; in[u] = idx;
    fors(i,0,g[u].size()){
        int v = g[u][i].second; ll w = g[u][i].first;
        if(v == fa[u]) continue;
        dep[v] = dep[u] + w; fa[v] = u;
        pre_dfs(v); dfn[++idx] = u;
    }out[u] = idx;
    return;
}
void init(){
    idx = 0;
    scanf("%d%d%lld", &n, &q, &lim);
    fors(i,0,n-1){
        int u, v; ll w; scanf("%d%d%lld", &u, &v, &w); e[i] = (edge){u, v, w};
        g[u].pb(P(w, v)); g[v].pb(P(w, u));
    }
    fa[1] = 0;
    pre_dfs(1);
    fors(i,0,n-1){
        if(fa[e[i].u] == e[i].v) swap(e[i].u, e[i].v);
    }
}
ll lz[maxn<<2], val[maxn<<2], mt[maxn<<2], lm[maxn<<2], mr[maxn<<2], lmr[maxn<<2];
void up(int rt){
    val[rt] = max(val[rt<<1], val[rt<<1|1]);
    mt[rt] = max(mt[rt<<1], mt[rt<<1|1]);
    lm[rt] = max({lm[rt<<1], lm[rt<<1|1], val[rt<<1] + mt[rt<<1|1]});
    mr[rt] = max({mr[rt<<1], mr[rt<<1|1], mt[rt<<1] + val[rt<<1|1]});
    lmr[rt] = max( { lmr[rt<<1], lmr[rt<<1|1], lm[rt<<1] + val[rt<<1|1], val[rt<<1] + mr[rt<<1|1] } );
    return;
}
void down(int rt){
    if(lz[rt] == 0) return;
    lz[rt<<1] += lz[rt]; lz[rt<<1|1] += lz[rt];
    val[rt<<1] += lz[rt]; val[rt<<1|1] += lz[rt];
    mt[rt<<1] -= 2*lz[rt]; mt[rt<<1|1] -= 2*lz[rt];
    lm[rt<<1] -= lz[rt]; lm[rt<<1|1] -= lz[rt];
    mr[rt<<1] -= lz[rt]; mr[rt<<1|1] -= lz[rt];
    lz[rt] = 0;
}
void build(int rt, int l, int r){
    if(l == r){
        int u = dfn[l];
        lz[rt] = 0; val[rt] = dep[u]; mt[rt] = -2*dep[u]; lm[rt] = val[rt]+mt[rt]; mr[rt] = val[rt]+mt[rt]; lmr[rt] = 0;
        return;
    }
    build(lson); build(rson); up(rt); return;
}
void update(int rt, int l ,int r, int L, int R, ll d){
    if(L <= l && r <= R){
        lz[rt] += d; val[rt] += d; mt[rt] -= 2*d; lm[rt] -= d; mr[rt] -= d; return;
    }down(rt);
    if(L <= mid) update(lson, L, R , d);
    if(R > mid) update(rson, L, R, d);
    up(rt); return;
}
void sol(){
    build(1, 1, idx);
    ll lastans = 0;
    while(q--){
        int id; ll w;
        scanf("%d%lld", &id, &w);
        id = (id + lastans)%(n-1);
        w = (w + lastans)%lim;
        int u = e[id].v;
        ll d = w-e[id].w;
        e[id].w += d;
        update(1, 1, idx, in[u], out[u], d);
        lastans = lmr[1];
        printf("%lld\n", lastans);
    }
}
int main()
{
    init();
    sol();
}