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

const int MAXN = 1e6 + 5;
int n,m,a,b;
int sm1,sm2;
bool vis[MAXN],fg1,fg2;
int sz;
std::vector<int> G[MAXN];

inline void dfs(int v){
    vis[v] = 1;sz++;
    for(auto x:G[v]){
        if(vis[x]) continue;
        if(x == a){
            fg1 = 1;continue;
        }
        if(x == b){
            fg2 = 1;continue;
        }
        dfs(x);
    }
}

inline void Solve(){
    scanf("%d%d%d%d",&n,&m,&a,&b);
    FOR(i,1,n) vis[i] = 0,G[i].clear();
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);G[u].pb(v);G[v].pb(u);
    }
    sm1=sm2=0;
    FOR(i,1,n){
        fg1=fg2=0;sz=0;
        if(i!=a&&i!=b&&!vis[i]) dfs(i);
        if(fg1&&fg2) continue;
        if(fg1) sm1 += sz;
        else sm2 += sz;
    }
    printf("%lld\n",1ll*sm1*sm2);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}