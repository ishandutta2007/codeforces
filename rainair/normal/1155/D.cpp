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
#define int LL
const int MAXN = 3e5 + 5;
int f[MAXN][3],n,a[MAXN],x;

signed main(){
    scanf("%lld%lld",&n,&x);
    FOR(i,1,n) scanf("%lld",a+i);
    LL ans = 0;
    FOR(i,1,n){
        f[i][0] = std::max(f[i-1][0],0ll)+a[i];
        ans = std::max(ans,f[i][0]);
    }
    FOR(i,1,n){
        f[i][1] = std::max(0ll,std::max(f[i-1][0],f[i-1][1]))+a[i]*x;
        ans = std::max(ans,f[i][1]);
    }
    FOR(i,1,n){
        f[i][2] = std::max(0ll,std::max(f[i-1][1],f[i-1][2]))+a[i];
        ans = std::max(ans,f[i][2]);
    }
    printf("%lld\n",ans);
    return 0;
}