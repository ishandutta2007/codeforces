/*
 * Author: RainAir
 * Time: 2019-08-02 18:52:07
 */
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

const int MAXN = 2e5 + 5;
int a[MAXN],f[MAXN][304],n;
std::vector<int> G[MAXN],pr[MAXN];

inline void split(int t,int x){
    pr[t].clear();
    int q = std::sqrt(1.0*x);
    FOR(i,2,q){
        if(x%i) continue;
        pr[t].pb(i);
        while(!(x%i)) x /= i;
    }
    if(x > 1) pr[t].pb(x);
    FOR(i,0,(int)pr[t].size()-1) f[t][i] = 1;
}

int ans = 1;

inline void dfs(int v,int fa=0){
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);
        FOR(i,0,(int)pr[v].size()-1){
            FOR(j,0,(int)pr[x].size()-1){
                if(pr[v][i] != pr[x][j]) continue;
                ans = std::max(ans,f[v][i]+f[x][j]);
                f[v][i] = std::max(f[v][i],f[x][j]+1);
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    bool flag = true;
    FOR(i,1,n) scanf("%d",a+i),split(i,a[i]),flag = flag&&(a[i]==1);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    if(flag){
        puts("0");return 0;
    }
    dfs(1);//DEBUG(f[1][0]);
    printf("%d\n",ans);
    return 0;
}