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
int n,g,b;
inline void Solve(){
    scanf("%lld%lld%lld",&n,&g,&b);
    int tmp = n;
    int t = 0,ans = 0;n = (n+1)/2;
    t = (n%g) ? std::max(0ll,(n-(n%g))/g) : std::max(0ll,(n-g)/g);
    ans = (n%g) ? t*(g+b)+(n%g) : t*(g+b)+g;
    printf("%lld\n",std::max(ans,tmp));
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
}