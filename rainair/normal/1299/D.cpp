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

const int MAXN = 2e5 + 5;
const int ha = 1e9 + 7;

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

int n,m;

std::unordered_map<int,int> S,iS;int tot = 0;
std::vector<P> G[MAXN]; 

struct Basis{
    int b[5];
    Basis(int seed=0){
        seed = iS[seed];
        ROF(i,4,0) b[i] = seed&31,seed >>= 5;
    }

    inline int seed(){
        int res = 0;
        FOR(i,0,4) res = (res<<5)|b[i];
        if(!S.count(res)) S[res] = ++tot,iS[tot] = res;
        return S[res];
    }

    inline bool insert(int x){
        if(!x) return 0;
        ROF(i,4,0){
            if((x>>i)&1){
                if(!b[i]){
                    b[i] = x;
                    ROF(j,i-1,0) if((b[i]>>j)&1) b[i] ^= b[j];
                    FOR(j,i+1,4) if((b[j]>>i)&1) b[j] ^= b[i];
                    return 1;
                }
                x ^= b[i];
            }
        }
        return 0;
    }
}now;

struct Node{
    int u,v,wu,wv,wuv;
    Node(int u=0,int wu=0,int v=0,int wv=0,int wuv=0) : u(u),wu(wu),v(v),wv(wv),wuv(wuv){}
};

int tag[MAXN];
int bas[MAXN],sm[MAXN];
bool vis[MAXN],dpt,used[MAXN];
std::vector<Node> adj;

inline void dfs(int v,int fa=0){
    vis[v] = 1;//DEBUG(v);
    for(auto x:G[v]){
        if(x.fi == fa || tag[x.fi] != -1 || !vis[x.fi]) continue;
        dpt &= now.insert(sm[v]^sm[x.fi]^x.se);
    }
    for(auto x:G[v]){
        if(x.fi == fa || tag[x.fi] != -1) continue;
        if(!vis[x.fi]) sm[x.fi] = sm[v]^x.se,dfs(x.fi,v);
    }
}

int f[2][423];
int res[505][505];

int main(){vis[1] = 1;tot = 1;S[0] = 1;iS[1] = 0;
    read(n);read(m);
    CLR(tag,-1);
    FOR(i,1,m){
        int u,v,w;read(u);read(v);read(w);
        if(u > v) std::swap(u,v);
        G[u].pb(MP(v,w));G[v].pb(MP(u,w));
        if(u == 1) tag[v] = w;
    }CLR(bas,-1);
    for(auto x:G[1]){
        now = Basis(1);dpt = 1;int t = tag[x.fi];tag[x.fi] = -1;
        dfs(x.fi,1);tag[x.fi] = t;
        if(dpt) bas[x.fi] = now.seed();
    }
    for(auto x:G[1]){
        if(used[x.fi]) continue;
        int ps = -1,w = -1;
        for(auto y:G[x.fi]){
            if(tag[y.fi] != -1) ps = y.fi,w = y.se;
        }
        if(ps == -1) adj.pb(Node(x.fi,x.se,-1,-1,-1));
        else adj.pb(Node(x.fi,x.se,ps,tag[ps],w)),used[ps] = 1;
        used[x.fi] = 1;
    }
    int now = 0;
    f[now][S[0]] = 1;
    for(auto x:adj){
        memcpy(f[now^1],f[now],sizeof(f[now]));
        FOR(i,1,376){
            if(!f[now][i]) continue;
            Basis t1(i);
            if(x.v == -1){
                if(bas[x.u] == -1) continue;
                Basis t2(bas[x.u]);bool fg = 1;
                FOR(j,0,4) if(t2.b[j]) fg &= t1.insert(t2.b[j]);
                if(!fg) continue;
                (f[now^1][t1.seed()] += f[now][i]) %= ha;
            }
            else{
                if(bas[x.u] == -1 || bas[x.v] == -1) continue;
                Basis tu(bas[x.u]),tv(bas[x.v]);bool fg = 1;
                FOR(j,0,4){
                    if(tu.b[j]) fg &= t1.insert(tu.b[j]);
                    if(tv.b[j]) fg &= t1.insert(tv.b[j]);
                }
                if(fg) (f[now^1][t1.seed()] += 2ll*f[now][i]%ha) %= ha;
                fg &= t1.insert(x.wu^x.wv^x.wuv);
                if(fg) (f[now^1][t1.seed()] += f[now][i]) %= ha;
            }
        }
        now ^= 1;
    }
    int ans = 0;
    FOR(i,0,376) (ans += f[now][i]) %= ha;
    printf("%d\n",ans);
    return 0;
}