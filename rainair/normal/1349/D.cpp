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

const int MAXN = 3e5 + 5;
const int ha = 998244353;
int a[MAXN],n,m;
int f[MAXN];
int inv[MAXN];

inline void prework(){
    inv[1] = 1;
    FOR(i,2,MAXN-1) inv[i] = 1ll*(ha-ha/i)*inv[ha%i]%ha;
}

int main(){prework();
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),m += a[i];
    f[0] = n-1;
    FOR(i,1,m){
        f[i] = (1ll*m*(n-1)%ha+1ll*(n-1)*i%ha*f[i-1]%ha)%ha;
        f[i] = 1ll*f[i]*inv[m-i]%ha;
    }
    ROF(i,m-1,0) (f[i] += f[i+1]) %= ha;
    int ans = 0;
    FOR(i,1,n) (ans += f[a[i]]) %= ha;
    (ans += ha-1ll*(n-1)*f[0]%ha) %= ha;
    ans = 1ll*ans*inv[n]%ha;
    printf("%d\n",ans);
    return 0;
}