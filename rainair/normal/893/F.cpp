/*
 * Author: RainAir
 * Time: 2019-10-10 13:31:11
 */
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
#define U unsigned
#define P std::pair
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

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int dep[MAXN],dfn[MAXN],sz[MAXN],n,rt,a[MAXN];
std::vector<int> S[MAXN];

inline void dfs(int v,int fa=0){
    static int ts = 0;
    dfn[v] = ++ts;sz[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dep[e[i].to] = dep[v] + 1;dfs(e[i].to,v);
        sz[v] += sz[e[i].to];
    }
}

int mn[MAXN<<5],lc[MAXN<<5],rc[MAXN<<5],root[MAXN],tot;

inline void pushup(int x){
    mn[x] = std::min(mn[lc[x]],mn[rc[x]]);
}

inline void build(int &v,int l,int r){
    v = ++tot;
    if(l == r){
        mn[v] = 2e9;
        return;
    }
    int mid = (l + r) >> 1;
    build(lc[v],l,mid);
    build(rc[v],mid+1,r);
    pushup(v);
}

inline void insert(int prev,int &v,int l,int r,int p,int d){
    mn[v = ++tot] = mn[prev];lc[v] = lc[prev];rc[v] = rc[prev];
    if(l == r){
        mn[v] = d;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) insert(lc[prev],lc[v],l,mid,p,d);
    else insert(rc[prev],rc[v],mid+1,r,p,d);
    pushup(v);
}

inline int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return mn[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc[x],l,mid,L,R);
    if(L > mid) return query(rc[x],mid+1,r,L,R);
    return std::min(query(lc[x],l,mid,L,mid),query(rc[x],mid+1,r,mid+1,R));
}
/*
inline int query(int x,int l,int r,int L,int R){
    //if(x)DEBUG(x);
    if(L <= l && r <= R) return mn[x];
    int mid = (l + r) >> 1,ans = 1e9;
    if(L <= mid) ans = std::min(ans,query(lc[x],l,mid,L,R));
    if(R > mid) ans = std::min(ans,query(rc[x],mid+1,r,L,R));
    return ans;
}
*/
int depv[MAXN];

int main(){
    //mn[0] = 1e9;
    scanf("%d%d",&n,&rt);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    dep[rt] = 1;dfs(rt);
/*    std::sort(all(S),[](int x,int y) -> bool{
              return dep[x] == dep[y] ? dfn[x] < dfn[y] : dep[x] < dep[y];
              });*/
    FOR(i,1,n) S[dep[i]].pb(i);
    int mx = 0;build(root[0],1,n);
    FOR(i,1,n) mx = std::max(mx,dep[i]);
    FOR(i,1,mx){
        root[i] = root[i-1];
        for(auto x:S[i]){
            insert(root[i],root[i],1,n,dfn[x],a[x]);
        }
    }
    int q;scanf("%d",&q);int la = 0;
    FOR(i,1,q){
        int v,k;scanf("%d%d",&v,&k);
        v = (v+la)%n+1;k = (k+la)%n;
//        DEBUG(v);DEBUG(k);
        if(!k) printf("%d\n",la = a[v]);
        else printf("%d\n",la = query(root[std::min(mx,dep[v]+k)],1,n,dfn[v],dfn[v]+sz[v]-1));
//        else printf("%d\n",la = query(root[depv[std::min(mx,dep[v]+k-1)]],1,n,dfn[v],dfn[v]+sz[v]-1));
    }
    return 0;
}