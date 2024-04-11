#include<bits/stdc++.h>

#define fi first
#define se second
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

const int MAXN = 3e5 + 5;

std::vector<int> G[MAXN];
int in[MAXN],out[MAXN],dep[MAXN],id[MAXN],ts;
int n;

inline void dfs(int v,int d){
    in[v] = ++ts;id[ts] = v;dep[ts] = d;
    for(auto x:G[v]) dfs(x,d+1);
    out[v] = ++ts;id[ts] = v;dep[ts] = d;
}

int f[MAXN],mn[MAXN],mx[MAXN],tag[MAXN],ch[MAXN][2],sz[MAXN];
#define lc (ch[x][0])
#define rc (ch[x][1])

inline void pushup(int x){
    if(!x) return;
    mn[x] = std::min(dep[x],std::min(mn[lc],mn[rc]));
    mx[x] = std::max(dep[x],std::max(mx[lc],mx[rc]));
    sz[x] = sz[lc]+sz[rc]+1;
}

inline void cover(int x,int d){
    mn[x] += d;mx[x] += d;tag[x] += d;dep[x] += d;
}

inline void pushdown(int x){
    if(tag[x]){
        if(lc) cover(lc,tag[x]);
        if(rc) cover(rc,tag[x]);
        tag[x] = 0;
    }
}

inline void rotate(int x){
    int y = f[x],z = f[y],k = ch[y][1]==x,w = ch[x][!k];
    ch[z][ch[z][1]==y] = x;f[x] = z;
    ch[x][!k] = y;f[y] = x;
    ch[y][k] = w;if(w) f[w] = y;
    pushup(y);pushup(x);
}

int rt;
int st[MAXN];

inline void splay(int x,int v=0){
    int y = x,z;
    st[z = 1] = y;
    while(f[y] != v) st[++z] = y = f[y];
    while(z) pushdown(st[z--]);
    while((y=f[x]) != v){
        if((z=f[y]) != v) rotate((ch[z][1]==y)^(ch[y][1]==x) ? x : y);
        rotate(x);
    }
    if(!v) rt = x;
    pushup(x);
}

inline int getk(int k){
    int x = rt;
    while(true){
        pushdown(x);
        if(k <= sz[lc]) x = lc;
        else if(k == sz[lc]+1) return splay(x),x;
        else k -= sz[lc]+1,x = rc;
    }
}

inline int pre(int x){
    splay(x);x = lc;while(rc) x = rc;return x;
}

inline int suf(int x){
    splay(x);x = rc;while(lc) x = lc;return x;
}

inline int split(int x,int y){
    x = pre(x);y = suf(y);
    splay(x);splay(y,x);return ch[y][0];
}

inline int find(int x,int k){
    pushdown(x);
    if(mn[rc] <= k && k <= mx[rc]) return find(rc,k);
    if(dep[x] == k) return splay(x),x;
    return find(lc,k);
}

inline void build(int f,int &x,int l,int r){
    if(l > r) return;
    x = (l+r)>>1;mn[x] = mx[x] = dep[x];sz[x] = 1;tag[x] = 0;::f[x] = f;
    if(l == r) return;
    build(x,lc,l,x-1);build(x,rc,x+1,r);
    pushup(x);
}

inline void dfs(int x){
    pushdown(x);
    if(lc) dfs(lc);
    printf("(%d,%d)",id[x],dep[x]);
    if(rc) dfs(rc);
    pushup(x);
}

int main(){
    mn[0] = 1e9;int m;scanf("%d%d",&n,&m);
    FOR(i,1,n){
        int k;scanf("%d",&k);
        while(k--) {int x;scanf("%d",&x);G[i].pb(x);}
    }
    dfs(1,1);build(0,rt,1,ts);
    while(m--){
        int opt;scanf("%d",&opt);
        if(opt == 1){
            int u,v;scanf("%d%d",&u,&v);int res = 0;
            splay(in[u]);int rku = sz[ch[in[u]][0]]+1;res += dep[in[u]];//splay 
            splay(in[v]);int rkv = sz[ch[in[v]][0]]+1;res += dep[in[v]];
//            DEBUG(res);
            if(rku > rkv) std::swap(u,v);
            int t = split(suf(in[u]),pre(out[v]));res -= 2*(mn[t]-1);// [in[u],out[v]]lca
            printf("%d\n",res);
        }
        if(opt == 2){
            int v,h;scanf("%d%d",&v,&h);
            splay(in[v]);int fa = id[find(ch[in[v]][0],dep[in[v]]-h)];
            int t = split(in[v],out[v]);pushdown(f[t]);ch[f[t]][0] = 0;pushup(f[t]);pushup(f[f[t]]);f[t] = 0;
            cover(t,1-h);int tt = pre(out[fa]);splay(tt);splay(out[fa],tt);
            pushdown(out[fa]);ch[out[fa]][0] = t;f[t] = out[fa];pushup(out[fa]);pushup(tt);
        }
        if(opt == 3){
            int k;scanf("%d",&k);splay(1);++k;
            printf("%d\n",id[find(1,k)]);
        }//dfs(rt);puts("");
    }
    return 0;
}