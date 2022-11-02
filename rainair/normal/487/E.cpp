#include <algorithm>
#include <iostream>
//#include <mulitset>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define lc (x<<1)
#define rc (x<<1|1)
#define U unsigned
#define Re register
#define LL long long
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 300000+5;
struct Edge{
    int to,next;
}e1[MAXN<<1],e2[MAXN<<1];
int head1[MAXN],head2[MAXN],dfn[MAXN],low[MAXN],st[MAXN],top,cnt1,cnt2;
int dep[MAXN],size[MAXN],fa[MAXN],son[MAXN],tp[MAXN],idx[MAXN];
int bel[MAXN],tot,min[MAXN<<2],val[MAXN],N,M,Q;
std::multiset<int> S[MAXN];

inline void add1(int u,int v){
    e1[++cnt1] = (Edge){v,head1[u]};head1[u] = cnt1;
}

inline void add2(int u,int v){
    e2[++cnt2] = (Edge){v,head2[u]};head2[u] = cnt2;
}

void dfs1(int v){
    static int ts = 0;
    dfn[v] = low[v] = ++ts;st[++top] = v;
    for(int i = head1[v];i;i = e1[i].next){
        if(!dfn[e1[i].to]){
            dfs1(e1[i].to);
            low[v] = std::min(low[v],low[e1[i].to]);
            if(low[e1[i].to] >= dfn[v]){
                int r = -1;tot++;
                do{
                    r = st[top--];
                    add2(tot,r);add2(r,tot);
                }while(r != e1[i].to);
                add2(v,tot);add2(tot,v);
            }
        }
        else low[v] = std::min(low[v],dfn[e1[i].to]);
    }
}

void dfs2(int v,int faa){
    size[v] = 1;int max = 0;
    for(int i = head2[v];i;i = e2[i].next){
        if(e2[i].to != faa){
            dep[e2[i].to] = dep[v] + 1;
            dfs2(e2[i].to,v);size[v] += size[e2[i].to];
            fa[e2[i].to] = v;
            if(size[e2[i].to] > max){
                max = size[e2[i].to];
                son[v] = e2[i].to;
            }
        }
    }
}

void dfs3(int v,int t){
    static int ts = 0;
    dfn[v] = ++ts;tp[v] = t;idx[dfn[v]] = v;
    if(son[v]) dfs3(son[v],t);
    for(int i = head2[v];i;i = e2[i].next){
        if(e2[i].to != fa[v] && e2[i].to != son[v]){
            dfs3(e2[i].to,e2[i].to);
        }
    }
}

inline void pushup(int x){
    min[x] = std::min(min[lc],min[rc]);
}

inline void build(int x,int l,int r){
    //DEBUG(l);DEBUG(r);
    if(l == r){
        min[x] = val[idx[l]];
        return;
    }
    int mid = (l + r) >> 1;
    build(lc,l,mid);build(rc,mid+1,r);
    pushup(x);
}

void update(int x,int l,int r,int pos,int d){
    if(l == r){
        min[x] = d;return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(lc,l,mid,pos,d);
    else update(rc,mid+1,r,pos,d);
    pushup(x);
}

int query(int x,int l,int r,int L,int R){
    if(l == L && r == R) return min[x];
    int mid = (l + r) >> 1;
    if(R <= mid) return query(lc,l,mid,L,R);
    if(L > mid) return query(rc,mid+1,r,L,R);
    return std::min(query(lc,l,mid,L,mid),query(rc,mid+1,r,mid+1,R));
}

int calc(int u,int v){
    int res = INT_MAX;
    while(tp[u] != tp[v]){
        if(dep[tp[u]] < dep[tp[v]]) std::swap(u,v);
        res = std::min(res,query(1,1,tot,dfn[tp[u]],dfn[u]));
        u = fa[tp[u]];
    }
    if(dep[u] > dep[v]) std::swap(u,v);
    res = std::min(res,query(1,1,tot,dfn[u],dfn[v]));
    if(u > N) res = std::min(res,val[fa[u]]);
    return res;
}

int main(){
    scanf("%d%d%d",&N,&M,&Q);tot = N;
    FOR(i,1,N) scanf("%d",val+i);
    FOR(i,1,M){
        int u,v;scanf("%d%d",&u,&v);add1(u,v);add1(v,u);
    }
    FOR(i,1,N) if(!dfn[i]) dfs1(i);
    CLR(dfn,0);dfs2(1,0);dfs3(1,1);
    FOR(i,2,N) S[fa[i]-N].insert(val[i]);
    FOR(i,N+1,tot) val[i] = S[i-N].empty() ? INT_MAX : *S[i-N].begin();
    build(1,1,tot);
    while(Q--){
        char opt;scanf("%c",&opt);
        while(opt != 'C' && opt != 'A') scanf("%c",&opt);
        int u,v;scanf("%d%d",&u,&v);
        if(opt == 'C'){
            update(1,1,tot,dfn[u],v);
            if(u == 1) {val[u] = v;continue;}
            int o = fa[u];
            S[o-N].erase(S[o-N].find(val[u]));
            S[o-N].insert(v);
            int minv = *S[o-N].begin();
            if(minv == val[o]) {val[u] = v;continue;}
            update(1,1,tot,dfn[o],minv);
            val[o] = minv;val[u] = v;
        }
        else{
            printf("%d\n",calc(u,v));
        }
    }
    return 0;
}
/*
3 3 3
1
2
3
1 2
2 3
1 3
A 2 3
C 1 5
A 2 3
*/