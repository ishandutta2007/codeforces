#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 4e5 + 5;

int f[MAXN],sz[MAXN];

inline int find(int x){
    return x == f[x] ? x : find(f[x]);
}

struct Node{
    int x,y,fy;
};
std::vector<Node> opt;
int now;

inline void merge(int x,int y){
    x = find(x);y = find(y);
    if(x == y) return;
    if(sz[x] < sz[y]) std::swap(x,y);
    opt.pb({x,y,f[y]});
    now -= sz[x]&1;now -= sz[y]&1;
    f[y] = x;sz[x] += sz[y];
    now += sz[x]&1;
}

inline void undo(){
    Node v = opt.back();opt.pop_back();
    now -= sz[v.x]&1;
    f[v.y] = v.fy;sz[v.x] -= sz[v.y];
    now += sz[v.x]&1;now += sz[v.y]&1;
}

int ans[MAXN];

struct Edge{
    int u,v,w,id;

    inline bool operator < (const Edge &t) const {
        return w < t.w;
    }
}e[MAXN];

int n,m,ps[MAXN];

inline void work(int l,int r,int L,int R){
    if(l > r) return;
    int mid = (l + r) >> 1,ts = SZ(opt);
    FOR(i,l,mid) if(ps[i] < L) merge(e[ps[i]].u,e[ps[i]].v);
    ans[mid] = -1;
    FOR(i,L,R){
        if(e[i].id <= mid){
            merge(e[i].u,e[i].v);
            if(!now) {ans[mid] = i;break;}
        }
    }
//    if(l == 1 && r == 5){
//        DEBUG(mid);DEBUG(ans[mid]);
//    }
    while(SZ(opt) != ts) undo();
    if(ans[mid] == -1) FOR(i,l,mid) ans[i] = -1;
    else{
        FOR(i,L,ans[mid]-1) if(e[i].id < l) merge(e[i].u,e[i].v);
        work(l,mid-1,ans[mid],R);
        while(SZ(opt) != ts) undo();
    }
    FOR(i,l,mid) if(ps[i] < L) merge(e[ps[i]].u,e[ps[i]].v);
    work(mid+1,r,L,ans[mid]==-1?R:ans[mid]);
    while(SZ(opt) != ts) undo();
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w),e[i].id = i;
    std::iota(f+1,f+n+1,1);std::fill(sz+1,sz+n+1,1);now = n;
    std::sort(e+1,e+m+1);
    FOR(i,1,m) ps[e[i].id] = i;
    work(1,m,1,m);
    FOR(i,1,m) printf("%d\n",ans[i]==-1?-1:e[ans[i]].w);
    return 0;
}