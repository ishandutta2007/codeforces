#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
int ch[MAXN][2],f[MAXN],sz[MAXN],tsz[MAXN],vsz[MAXN],a[MAXN];
LL vans[MAXN],tans[MAXN];
#define lc (ch[x][0])
#define rc (ch[x][1])
// t: tree 
// v: virtual

inline bool nroot(int x){
    return ch[f[x]][0]==x||ch[f[x]][1]==x;
}

inline void pushup(int x){
    sz[x] = sz[lc]+sz[rc]+1;
    tsz[x] = tsz[lc]+tsz[rc]+vsz[x]+1;
    tans[x] = vans[x]+tans[lc]+tans[rc]+1ll*(sz[lc]+1)*(tsz[rc]+vsz[x]+1);
//    tans[x] = vans[x]+tans[lc]+tans[rc]+tsz[x]-tsz[lc];
}

inline void rotate(int x){
    int y = f[x],z = f[y],k = ch[y][1]==x,w = ch[x][!k];
    if(nroot(y)) ch[z][ch[z][1]==y] = x;f[x] = z;
    ch[x][!k] = y;f[y] = x;
    ch[y][k] = w;if(w) f[w] = y;
    pushup(y);pushup(x);
}

inline void splay(int x,int v=0){
    while(nroot(x)){
        int y = f[x],z = f[y];
        if(nroot(y)) rotate((ch[z][1]==y)^(ch[y][1]==x)?x:y);
        rotate(x);
    }
}

inline void access(int x){
    for(int y = 0;x;x = f[y=x]){
        splay(x);
        vsz[x] += tsz[rc];
        vans[x] += tans[rc];
        rc = y;
        vsz[x] -= tsz[y];
        vans[x] -= tans[y];
        pushup(x);
    }
}

inline void cut(int v){// cut(v,fa[v])
    access(v);splay(v);
    f[ch[v][0]] = 0;
    ch[v][0] = 0;
    pushup(v);
}

inline void link(int u,int v){// set u as v's father
    access(u);splay(u);
    f[v] = u;ch[u][1] = v;
    pushup(u);
}

inline int findpre(int x,int v){//  > v 
    int ans = 0;
    while(x){
        if(a[x] > v) ans = x,x = rc;
        else x = lc;
    }
    return ans;
}

inline int findsuf(int x,int v){
    int ans = 0;
    while(x){
        if(a[x] < v) ans = x,x = lc;
        else x = rc;
    }
    return ans;
}

int n,ps[MAXN];
std::set<int> S;
int ls[MAXN],rs[MAXN];// for tree

inline void dfs(int x){
    if(ls[x]) dfs(ls[x]),vans[x] += tans[ls[x]],vsz[x] += tsz[ls[x]];
    if(rs[x]) dfs(rs[x]),vans[x] += tans[rs[x]],vsz[x] += tsz[rs[x]];
    pushup(x);
}

inline void print(int x,std::vector<int> &v){
    if(lc) print(lc,v);
    v.pb(x);
    if(rc) print(rc,v);
}

LL res[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),ps[a[i]] = i,S.insert(i),sz[i] = 1;
    static int st[MAXN],tp = 0;
    FOR(i,1,n){
        int k = tp;
        while(tp && a[st[tp]] < a[i]) --tp;
        if(tp) rs[st[tp]] = i,f[i] = st[tp];
        if(tp != k) ls[i] = st[tp+1],f[st[tp+1]] = i;
        st[++tp] = i;
    }
    assert(st[1] == ps[n]);
    dfs(ps[n]);
    ROF(i,n,2){
        int p = ps[i];
        access(p);splay(p);res[i] = tans[p];
        auto it = S.find(p);
        if(next(it) == S.end() || it == S.begin()){
            int y = ps[i-1];
            access(y);splay(y);
            cut(y);
        }
        else{
            int y = *prev(it),z = *next(it);
            access(y);splay(y);int sy = sz[y];
            access(z);splay(z);int sz = ::sz[z];
            // sy -> sx
            if(sy < sz) std::swap(y,z),std::swap(sy,sz);
            access(z);splay(z);
            std::vector<int> vec;print(z,vec);
            for(auto x:vec) if(x != p) cut(x);
            std::reverse(all(vec));
            // () 
            int now = y;
            for(auto x:vec){
                if(x == p) continue;
                access(now);splay(now);
                int pre = findpre(now,a[x]),suf = findsuf(now,a[x]);
                splay(pre);
                if(suf) splay(suf);
                // (pre,suf)
                if(suf) cut(suf);
                if(pre) link(pre,x);
                if(suf) link(x,suf);
                now = x;// finger search
            }
            now = y;
            access(now);splay(now);
            int t = findsuf(now,i);
            splay(t);
            cut(t);
        }
        S.erase(p);
    }
    res[1] = 1;
    FOR(i,1,n) printf("%lld\n",res[i]);
    return 0;
}