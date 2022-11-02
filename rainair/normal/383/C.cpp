/*
 * Author: RainAir
 * Time: 2019-08-23 16:32:22
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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
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

#define lc ((x)<<1)
#define rc ((x)<<1|1)
int sm[MAXN<<2],tag[MAXN<<2],dfn[MAXN],a[MAXN];

inline void pushup(int x){
    sm[x] = sm[lc] + sm[rc];
}

inline void build(int x,int l,int r){
    if(l == r){
        sm[x] = a[dfn[l]];return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(x);
}

inline void cover(int x,int l,int r,int d){
    sm[x] += (r-l+1)*d;
    tag[x] += d;
}

inline void pushdown(int x,int l,int r){
    int mid = (l + r) >> 1;
    if(tag[x]){
        cover(lc,l,mid,tag[x]);
        cover(rc,mid+1,r,tag[x]);
        tag[x] = 0;
    }
}

inline void modify(int x,int l,int r,int L,int R,int d){
    if(l == L && r == R){
        cover(x,l,r,d);return;
    }
    int mid = (l + r) >> 1;pushdown(x,l,r);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    pushup(x);
}

inline int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;pushdown(x,l,r);
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R);
}

int dep[MAXN],sz[MAXN];

inline void dfs(int v,int fa=0){
    static int ts = 0;dfn[v] = ++ts;sz[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dep[e[i].to] = dep[v] + 1;
        dfs(e[i].to,v);sz[v] += sz[e[i].to];
    }
}

int n,m;

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }dep[1] = 1;
    dfs(1);//build(1,1,n);
    FOR(i,1,n) DEBUG(dfn[i]);
    FOR(i,1,m){
        int opt,x;scanf("%d%d",&opt,&x);
        if(opt == 1){
            int val;scanf("%d",&val);
            if(!(dep[x] & 1)) val = -val;
            modify(1,1,n,dfn[x],dfn[x]+sz[x]-1,val);
        }
        if(opt == 2){
            int val = query(1,1,n,dfn[x],dfn[x]);
            if(!(dep[x] & 1)) val = -val;
            printf("%d\n",a[x]+val);
        }
    }
    return 0;
}