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
int n,a[MAXN];

inline void trans(){
    int mx = -1e18;
    FOR(i,1,n) mx = std::max(mx,a[i]);
    FOR(i,1,n) a[i] = mx-a[i];
}

inline void Solve(){
    LL k;scanf("%lld%lld",&n,&k);
    FOR(i,1,n) scanf("%lld",a+i);
    k--;trans();
    k %= 2;
    if(k == 1) trans();
    FOR(i,1,n) printf("%lld ",a[i]);puts("");
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}