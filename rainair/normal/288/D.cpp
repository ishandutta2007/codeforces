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
#define int LL
const int MAXN = 80000+5;
std::vector<int> G[MAXN];
int n;
int sz[MAXN],fa[MAXN];

inline void dfs1(int v,int faa=0){
    sz[v] = 1;fa[v] = faa;
    for(auto x:G[v]){
        if(x == faa) continue;
        dfs1(x,v);sz[v] += sz[x];
    }
}
LL ans = 0ll;

inline LL C(LL x){
    return 1ll*x*(x-1)/2;
}

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n-1){
        int u,v;scanf("%lld%lld",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }dfs1(1);ans = C(n)*C(n);
    FOR(i,1,n){
        LL num2 = C(sz[i]),num1 = C(n);
        for(auto x:G[i]){
            if(x == fa[i]){
                num1 -= C(n-sz[i]);continue;
            }
            num2 -= C(sz[x]);num1 -= C(sz[x]);
        }
        ans -= (2ll*num1*num2-num2*num2);
       // ans -= 2ll*num1*num2-num2*num2;// (num1- num2)*num2 + num2*num2;
    }
    std::cout << ans << std::endl;
    return 0;
}