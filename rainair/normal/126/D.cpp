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
const int MAXN = 90+5;
int fib[MAXN],cnt;
int f[MAXN][MAXN],n,c[MAXN];

inline void Solve(){
    scanf("%lld",&n);cnt = 0;CLR(f,0);
    for(int p = std::lower_bound(fib+1,fib+MAXN,n)-fib;p;p--){
        if(n >= fib[p]){
            n -= fib[p];c[++cnt] = p;
        }
    }
    std::reverse(c+1,c+cnt+1);
    f[1][0] = 1;f[1][1] = (c[1]-1)/2;
    FOR(i,2,cnt){
        f[i][0] = f[i-1][0] + f[i-1][1];
        f[i][1] = (c[i]-c[i-1]-1)/2*f[i-1][0] + (c[i]-c[i-1])/2 * f[i-1][1];
    }
    printf("%lld\n",f[cnt][0]+f[cnt][1]);
}

signed main(){
    fib[0] = 0;fib[1] = 1;fib[2] = 2;
    FOR(i,3,MAXN-1) fib[i] = fib[i-1] + fib[i-2];
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}