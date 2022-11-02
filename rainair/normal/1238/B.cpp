/*
 * Author: RainAir
 * Time: 2019-10-11 07:34:05
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;
int n,x[MAXN],r;

inline void Solve(){
    scanf("%lld%lld",&n,&r);int ans = 0;
    FOR(i,1,n) scanf("%lld",x+i);
    std::sort(x+1,x+n+1);n = std::unique(x+1,x+n+1)-x-1;
    std::reverse(x+1,x+n+1);
    FOR(i,1,n){
        if(x[i]-r*ans <= 0) continue;
        ans++;continue;
    }
    printf("%lld\n",ans);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}