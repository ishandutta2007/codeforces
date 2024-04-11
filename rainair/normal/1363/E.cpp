/*
 * Author: RainAir
 * Time: 2020-06-01 15:34:39
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
#define int LL
const int MAXN = 2e5 + 5;
int a[MAXN],b[MAXN],c[MAXN];
std::vector<int> G[MAXN];
int n,ans;

inline P dfs(int v,int fa=0){
    a[v] = std::min(a[v],a[fa]);
    P res = MP(0,0);
    if(b[v] == 1 && c[v] == 0) res.fi++;
    if(b[v] == 0 && c[v] == 1) res.se++;
    for(auto x:G[v]){
        if(x == fa) continue;
        P t = dfs(x,v);
        res.fi += t.fi;res.se += t.se;
    }
    if(std::min(res.fi,res.se)){
        int t = std::min(res.fi,res.se);
        ans += 2*t*a[v];
        res.fi -= t;res.se -= t;
    }
    return res;
}

signed main(){
    scanf("%lld",&n);a[0] = 1e18;
    int b0=0,c0=0;
    FOR(i,1,n) scanf("%lld%lld%lld",a+i,b+i,c+i);
    FOR(i,1,n){
        if(b[i] == 0) b0++;
        if(c[i] == 0) c0++;
    }
    if(b0 != c0){
        puts("-1");return 0;
    }
    FOR(i,2,n){
        int u,v;scanf("%lld%lld",&u,&v);G[u].pb(v);G[v].pb(u);
    }
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}