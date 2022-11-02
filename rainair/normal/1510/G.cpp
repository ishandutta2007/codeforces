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

const int MAXN = 100+5;
int n,m;
std::vector<int> G[MAXN];

struct Node{
    int i,j,k;
    Node(int i=0,int j=0,int k=0) : i(i),j(j),k(k) {}
}pre[MAXN][MAXN][MAXN];

bool f[MAXN][MAXN][MAXN];
int dfn[MAXN],sz[MAXN],nfd[MAXN],ts,dep[MAXN],fa[MAXN];
bool vis[MAXN];

inline void dfs(int v,int fa=0){
    dfn[v] = ++ts;nfd[ts] = v;sz[v] = 1;dep[v] = dep[fa]+1;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);sz[v] += sz[x];
    }
}

std::vector<int> res;
int son[MAXN];

inline void dfs2(int v,int fa=0){
    res.pb(v);
    for(auto x:G[v]){
        if(x == fa || !vis[x] || x == son[v]) continue;
        dfs2(x,v);
        res.pb(v);
    }
    if(son[v]) dfs2(son[v],v);
}

inline void Solve(){
    scanf("%d%d",&n,&m);ts = 0;
    FOR(i,1,n) G[i].clear();
    FOR(i,2,n){
        scanf("%d",fa+i);G[fa[i]].pb(i);
    }
    dfs(1);
    CLR(f,0);FOR(i,0,n+1) FOR(j,0,n+1) FOR(k,0,n+1) pre[i][j][k] = Node(0,0,0);
    f[1][0][1] = 1;
    FOR(i,1,n){
        FOR(j,0,i){
            FOR(k,1,i){
                int c = f[i][j][k];
                if(!c) continue;
                if(!f[i+1][j+1][std::max(k,dep[nfd[i]])]){
                    f[i+1][j+1][std::max(k,dep[nfd[i]])] = 1;
                    pre[i+1][j+1][std::max(k,dep[nfd[i]])] = Node(i,j,k);
                }
                if(!f[i+sz[nfd[i]]][j][k]){
                    f[i+sz[nfd[i]]][j][k] = 1;
                    pre[i+sz[nfd[i]]][j][k] = Node(i,j,k);
                }
            }
        }
    }
    int ni = -1,nj = -1,nk = -1,ans = 1e9;
    FOR(k,1,n){
        if(f[n+1][m][k] && 2*(m-1)-k+1 <= ans){
            ans = 2*(m-1)-k+1;
            ni = n+1;nj = m;nk = k;
        }
    }
    FOR(i,1,n) vis[i] = 0;
    while(ni){
        Node t = pre[ni][nj][nk];
        if(t.i >= 1 && t.j < nj) vis[nfd[t.i]] = 1;
        ni = t.i;nj = t.j;nk = t.k;
    }
//    FOR(i,1,n) DEBUG(vis[i]);
    int ps = 1;
    FOR(i,2,n) if(vis[i] && dep[i] > dep[ps]){ps = i;}
    FOR(i,1,n) son[i] = 0;
    printf("%d\n",ans);res.clear();
    while(ps != 1){
        son[fa[ps]] = ps;
        ps = fa[ps];
    }
    dfs2(1);
//    assert(SZ(res)==ans+1);
    for(auto x:res) printf("%d ",x);puts("");
}

int main(){
//    freopen("A.in","r",stdin);
//    freopen("A.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}