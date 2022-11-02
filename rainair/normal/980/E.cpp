#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
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
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;

std::vector<int> G[MAXN];
int f[MAXN][26];

void dfs(int v){
    FOR(i,1,20){
        f[v][i] = f[f[v][i-1]][i-1];
    }
    for(auto x:G[v]){
        if(x == f[v][0]) continue;
        f[x][0] = v;dfs(x);
    }
}
int n,k;
bool vis[MAXN];
int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    int res = n-k;
    f[n][0] = n;
    dfs(n);
    vis[n] = true;res--;
    ROF(i,n-1,1){
        if(vis[i]) continue;
        int len = 1,v = i;
        ROF(j,20,0){
            if(vis[f[v][j]]) continue;
            v = f[v][j];
            len += (1<<j);
        }
        if(len <= res){
            res -= len;int x = i;
            while(true){
                if(vis[x]) break;
                vis[x] = 1;x = f[x][0];
            }
        }
    }
    FOR(i,1,n) if(!vis[i]) printf("%d ",i);
    puts("");
    return 0;
}