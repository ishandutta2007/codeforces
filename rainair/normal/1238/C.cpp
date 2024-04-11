/*
 * Author: RainAir
 * Time: 2019-10-11 07:44:29
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
const int MAXN = 2e5 + 5;

int a[MAXN],n;

inline void Solve(){
    scanf("%*lld%lld",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    int ans = 0,lst = 1;
    if(a[n] != 1) a[++n] = 0;
    FOR(i,2,n){
        int d = a[i]-a[i-1],dd = i-lst;
        d = -d;
        if(d == 1) continue;
        if(lst == 1) ans += !(dd&1);//
        else ans += dd&1;
        lst = i;
    }
    printf("%lld\n",ans);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}