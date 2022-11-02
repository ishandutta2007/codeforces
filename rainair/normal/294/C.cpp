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
const int ha = 1e9 + 7;
const int MAXN = 1000+5;

int n,m;
int a[MAXN];

int C[1005][1005];

inline int qpow(int a,int n){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}
void prework(){
    FOR(i,0,1000) C[i][0]=1;
    FOR(i,1,1000)
        FOR(j,1,1000)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%ha;
}

signed main(){
    prework();
    scanf("%lld%lld",&n,&m);
    FOR(i,1,m) scanf("%lld",a+i);
    std::sort(a+1,a+m+1);
    int now = a[1]-1,res = n-m,ans = C[res][now];res -= now;
    FOR(i,2,m){
        now = a[i]-a[i-1]-1;
        if(!now) ans = 1ll*ans*C[res][now]%ha;
        else ans = 1ll*ans*qpow(2,now-1)%ha*C[res][now]%ha;
        res -= now;
    }
    ans = 1ll*ans*C[res][n-a[m]]%ha;
    printf("%lld\n",ans);
    return 0;
}