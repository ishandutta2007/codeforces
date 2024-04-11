/*
 * Author: RainAir
 * Time: 2019-09-08 08:37:49
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
bool vis[123];

inline void Solve(){
    LL n,m;scanf("%lld%lld",&n,&m);
    int N = n/m;
    FOR(i,0,10) vis[i] = false;
    int sm = 0,cnt = -1;
    while(true){
        cnt++;
        int x = (cnt+1)*m%10;
        if(vis[x]) break;
        vis[x] = true;
        sm += x;
    }
    LL ans = (N/cnt)*sm;
    LL st = (N/cnt)*cnt+1;
    FOR(i,st,N) ans += 1ll*i*m%10;
    printf("%lld\n",ans);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}