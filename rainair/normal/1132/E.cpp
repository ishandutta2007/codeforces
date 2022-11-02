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
const int MAXN = 11+5;
LL m,a[MAXN],f[MAXN][10000];

signed main(){
    scanf("%lld",&m);
    FOR(i,1,8) scanf("%lld",a+i);
    CLR(f,-1);f[0][0] = 0;
    FOR(i,0,7){
        FOR(j,0,840*8){
            if(f[i][j] != -1){
                LL t = 840/(i+1);
                t = std::min(t,a[i+1]);
                FOR(k,0,t){
                    f[i+1][j+k*(i+1)] = std::max(f[i+1][j+k*(i+1)],f[i][j]+(a[i+1]-k)/(840/(i+1)));
                }
            }
        }
    }
    LL ans = 0;
    FOR(i,0,840*8){
        if(i > m || f[8][i] == -1) continue;
        ans = std::max(ans,i+840*std::min(f[8][i],(m-i)/840));
    }
    printf("%lld\n",ans);
    return 0;
}
// FAFQAFQ