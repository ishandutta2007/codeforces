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
#define U unsigned
#define P std::pair<int,LL>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
int n;LL a[MAXN];
std::vector<P> G[MAXN]; //<point,weight>
bool vis[MAXN];

inline void add(int u,int v,LL w){
    G[u].pb(MP(v,w));G[v].pb(MP(u,w));
}

inline void dfs(int v,int fa,LL sum){
    vis[v] = true;//DEBUG(v);DEBUG(sum);
    for(auto x:G[v]){
        int to = x.fi;LL w = x.se;
        if(to == fa) continue;
        if(sum + w <= a[to]) dfs(to,v,std::max(0ll,sum+w));
    }
}

int ans = 0;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,n-1){
        int p;LL w;scanf("%d%lld",&p,&w);
        add(i+1,p,w);
    }
    dfs(1,0,0);
    FOR(i,1,n) ans += !vis[i];
    printf("%d\n",ans);
    return 0;
}