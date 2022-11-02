/*
 * Author: RainAir
 * Time: 2020-07-10 12:04:47
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
const int ha = 998244353;

inline int qpow(int a,int n=ha-2){
	int res = 1;
	while(n){
		if(n & 1) res = 1ll*res*a%ha;
		a = 1ll*a*a%ha;
		n >>= 1;
	}
	return res;
}

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int sz[MAXN],son[MAXN],fa[MAXN],dep[MAXN],dfn[MAXN],tp[MAXN];

inline void dfs1(int v){
    sz[v] = 1;dep[v] = dep[fa[v]]+1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa[v]) continue;
        fa[e[i].to] = v;dfs1(e[i].to);
        sz[v] += sz[e[i].to];
        if(sz[e[i].to] > sz[son[v]]) son[v] = e[i].to;
    }
}

inline void dfs2(int v,int tp=1){
    ::tp[v] = tp;static int ts = 0;dfn[v] = ++ts;
    if(son[v]) dfs2(son[v],tp);
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa[v] || e[i].to == son[v]) continue;
        dfs2(e[i].to,e[i].to);
    }
}

int sm[MAXN<<2],tag[MAXN<<2];
#define lc ((x)<<1)
#define rc ((x)<<1|1)

inline void cover(int x,int l,int r,int d){
    (sm[x] += 1ll*(r-l+1)*d%ha) %= ha;(tag[x] += d) %= ha;
}

inline void pushdown(int x,int l,int r){
    if(tag[x]){
        int mid = (l + r) >> 1;
        cover(lc,l,mid,tag[x]);
        cover(rc,mid+1,r,tag[x]);
        tag[x] = 0;
    }
}

inline void modify(int x,int l,int r,int L,int R,int d){
    if(l == L && r == R){cover(x,l,r,d);return;}
    int mid = (l + r) >> 1;pushdown(x,l,r);
    if(R <= mid) modify(lc,l,mid,L,R,d);
    else if(L > mid) modify(rc,mid+1,r,L,R,d);
    else modify(lc,l,mid,L,mid,d),modify(rc,mid+1,r,mid+1,R,d);
    sm[x] = (sm[lc]+sm[rc])%ha;
}

inline int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return sm[x];
    int mid = (l + r) >> 1;pushdown(x,l,r);
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return (query(lc,l,mid,L,mid)+query(rc,mid+1,r,mid+1,R))%ha;
}

int n,q;
int mod[MAXN];

inline int query(int v){
    int ans = query(1,1,n,dfn[v],dfn[v]);
    while(tp[v] != tp[1]){
        (ans += 1ll*mod[fa[tp[v]]]*(n-sz[tp[v]])%ha) %= ha;
        v = fa[tp[v]];
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&q);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    dfs1(1);dfs2(1);
    int invn = qpow(n);
    FOR(i,1,q){
        int opt,v;scanf("%d%d",&opt,&v);
        if(opt == 1){
            int d;scanf("%d",&d);
            int gx=0;
            if(son[v]){
                gx = 1ll*(n-sz[son[v]])*d%ha;
                modify(1,1,n,dfn[son[v]],dfn[son[v]]+sz[son[v]]-1,gx);
            }
            gx = 1ll*sz[v]*d%ha;
            modify(1,1,n,1,n,gx);
            modify(1,1,n,dfn[v],dfn[v]+sz[v]-1,ha-gx);
            (mod[v] += d) %= ha;
            gx = 1ll*n*d%ha;
            modify(1,1,n,dfn[v],dfn[v],gx);
        }
        else{
            int ans = 1ll*query(v)*invn%ha;
            printf("%d\n",ans);
        }
    }
    return 0;
}