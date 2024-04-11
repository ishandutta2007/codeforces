/*
 * Author: RainAir
 * Time: 2019-10-08 17:19:02
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

const int MAXN = 1000+5;
const int MAXM = 8+1;
int f[MAXN][(1<<MAXM)+3];
int a[MAXN],n;
std::vector<int> G[MAXN];
int nxt[MAXN][MAXN];
int head[MAXN];

inline int chk(int l){
    FOR(i,0,n) FOR(j,0,(1<<8)-1) f[i][j] = -1e9;
    FOR(i,0,7) head[i] = 0;
    f[0][0] = 0;
    FOR(i,0,n-1){
        FOR(S,0,(1<<8)-1){
            if(f[i][S] == -1e9) continue;
            FOR(k,0,7){
                if(S&(1<<k)) continue;
                int t = head[k] + l - 1;
                if(t >= G[k].size()) continue;
                //if(i == 22 && S == 127 && k == 7) DEBUG(G[k][t]+1);
                f[G[k][t]+1][S|(1<<k)] = std::max(f[G[k][t]+1][S|(1<<k)],f[i][S]);
                ++t;
               // if(i == 22 && S == 127) DEBUG(t);
                if(t >= G[k].size()) continue;
                //if(i == 22 && S == 127) DEBUG(G[k][t]);
                f[G[k][t]+1][S|(1<<k)] = std::max(f[G[k][t]+1][S|(1<<k)],f[i][S]+1);
            }
        }
        head[a[i]]++;
    }
//    DEBUG(f[22][127]);
    int ans = -1e9;
    FOR(i,0,n) ans = std::max(ans,f[i][(1<<8)-1]);
    if(ans == -1e9) return -1;
    return ans*(l+1)+(8-ans)*l;
}

int main(){
    scanf("%d",&n);
    FOR(i,0,n-1) scanf("%d",a+i),a[i]--,G[a[i]].pb(i);
    int l = 1,r = n,ans = -1;
//    DEBUG(chk(2));exit(0);
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid) != -1) ans = mid,l = mid+1;
        else r = mid-1;
    }
    ans = std::max(chk(ans),std::max(chk(ans-1),chk(ans+1)));
    if(ans == -1){
        ans = 0;
        FOR(i,0,7) if(G[i].size()) ans++;
    }
    printf("%d\n",ans);
    return 0;
}