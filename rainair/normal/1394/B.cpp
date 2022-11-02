#include <bits/stdc++.h>

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
const int H = 4;
int n,m,k;
std::vector<P> G[MAXN];
const int mod[H+1] = {998244353,(int)1e9+7,(int)1e9+9,666623333,1004535809};
std::mt19937 rnd(time(NULL));

struct Node{
    int a[H+1];
    Node(){FOR(i,0,H) a[i] = 1;}
    inline void gen(){
        FOR(i,0,H) a[i] = rnd()%mod[i];
    }

    friend Node operator + (const Node &x,const Node &y){
        Node res;
        FOR(i,0,H) res.a[i] = 1ll*x.a[i]*y.a[i]%mod[i];
        return res;
    }

    inline bool operator == (const Node &t) const {
        FOR(i,0,H) if(a[i] != t.a[i]) return 0;
        return 1;
    }
}val[MAXN],g[11][11],all;
bool vis[11][MAXN];
int ans = 0;
int p[MAXN];

inline bool chk(){
    Node t;
    FOR(i,1,k) t = t+g[i][p[i]];
    return t == all;
}

inline void dfs(int step){
    if(step == k+1){
        ans += chk();
        return;
    }
    FOR(i,1,step) p[step] = i,dfs(step+1);
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        G[u].pb(MP(w,v));
    }
    FOR(i,1,n) std::sort(all(G[i]));
    FOR(i,1,n) val[i].gen(),all = all+val[i];
    FOR(deg,1,k){
        CLR(vis,0);
        FOR(i,1,n){
            if((int)G[i].size() != deg) continue;
            FOR(j,0,deg-1) vis[j+1][G[i][j].se] = 1;
        }
        FOR(i,1,deg){
            FOR(j,1,n){
                if(vis[i][j]) g[deg][i] = g[deg][i]+val[j];
            }
        }
    }
    dfs(1);
    printf("%d\n",ans);
    return 0;
}