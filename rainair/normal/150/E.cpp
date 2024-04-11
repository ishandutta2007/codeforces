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

const int MAXN = 1e5 + 5;

inline char nc(){
    #define SIZE 1000000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
    #undef SIZE
}

template <typename T>
inline void read(T &x){
    x = 0;int flag = 0;char ch = nc();
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

struct Edge{
    int u,v,w;
}e[MAXN];

int n,L,R;
std::vector<P<int,int> > G[MAXN];
int mx[MAXN],sz[MAXN],rt;
bool vis[MAXN];
int sx=-1,sy=-1;

inline void getroot(int v,int fa=0){
    sz[v] = 1;mx[v] = 0;
    for(auto x:G[v]){
        if(vis[x.fi] || x.fi == fa) continue;
        getroot(x.fi,v);
        sz[v] += sz[x.fi];
        mx[v] = std::max(mx[v],sz[x.fi]);
    }
    mx[v] = std::max(mx[v],mx[0]-sz[v]);
    if(mx[v] < mx[rt]) rt = v;
}

std::vector<P<int,int> > S[MAXN];

inline void dfs(int v,int rt,int dep,int dis,int fa=0){
    while(SZ(S[rt]) < dep+1) S[rt].pb(-1e9,-1);
    S[rt][dep] = std::max(S[rt][dep],MP(dis,v));
    for(auto x:G[v]){
        if(x.fi == fa || vis[x.fi]) continue;
        dfs(x.fi,rt,dep+1,dis+x.se,v);
    }
}

bool flag = 0;
std::vector<int> rr[MAXN];

inline void work(int v){
    vis[v] = 1;std::vector<int> vec;
    for(auto x:G[v]){
        if(vis[x.fi]) continue;
        S[x.fi].clear();
        dfs(x.fi,x.fi,1,x.se);
//        FOR(i,1,SZ(S[x.fi])-1) DEBUG(S[x.fi][i].se);
        FOR(i,1,SZ(S[x.fi])-1) if(L <= i && i <= R && S[x.fi][i].fi >= 0){
            sx = v;sy = S[x.fi][i].se;
        }
        vec.pb(x.fi);
    }
    if(vec.empty()) return;
    std::sort(all(vec),[&](int x,int y){return SZ(S[x]) < SZ(S[y]);});
    std::vector<P<int,int> > now = S[vec[0]];
    auto merge = [&](std::vector<P<int,int> >&A,std::vector<P<int,int> > &B){
        std::deque<int> q;
        int nr = -1;
        ROF(i,SZ(B)-1,1){
            int ll = std::max(1,L-i),rr = std::min(SZ(A)-1,R-i);
            if(ll > rr) continue;
            while(nr != rr){
                ++nr;
                while(!q.empty() && A[q.back()].fi <= A[nr].fi) q.pop_back();
                q.push_back(nr);
            }
            while(!q.empty() && q.front() < ll) q.pop_front();
            if(q.empty()) continue;
            if(A[q[0]].fi+B[i].fi >= 0){
                sx = B[i].se;
                sy = A[q[0]].se;
            }
        }
        FOR(i,0,SZ(A)-1) A[i] = std::max(A[i],B[i]);
        FOR(i,SZ(A),SZ(B)-1) A.pb(B[i]);
    };
    FOR(i,1,SZ(vec)-1) merge(now,S[vec[i]]);
    int t = 0;
    for(auto x:G[v]){
        if(vis[x.fi]) continue;
        if(!flag){
            mx[rt = 0] = sz[x.fi];getroot(x.fi);
            rr[v].pb(rt);
        }
        work(rr[v][t++]);
    }
}

int RR;

inline bool chk(int k){// check median >= k?
    // >= k -> 1
    // < k  -> 0
    // sm >= 0
    FOR(i,1,n-1) [&](int u,int v,int w){G[u].pb(v,w),G[v].pb(u,w);}(e[i].u,e[i].v,e[i].w>=k?1:-1);
    sx = sy = -1;
    if(!RR){
        mx[rt = 0] = n;getroot(1);
        RR = rt;
    }
    work(RR);
    FOR(i,1,n) G[i].clear(),vis[i] = 0;
    flag = 1;
    return sx != -1;
}

int main(){
    read(n);read(L);read(R);
    FOR(i,1,n-1) read(e[i].u),read(e[i].v),read(e[i].w);
    int l = 0,r = 1e9,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,l = mid+1;
        else r = mid-1;
    }
    chk(ans);
    printf("%d %d\n",sx,sy);
    return 0;
}