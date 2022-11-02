/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-17 16:52:35
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
#define P std::pair<LL,LL>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e6 + 5;
int n,m,a[MAXN],q;
int ans[MAXN],sm[MAXN];
std::vector<P> qq[MAXN];

signed main(){
    scanf("%lld",&n);q = std::sqrt(1.0*n);
    FOR(i,1,n) scanf("%lld",a+i);
    scanf("%lld",&m);
    FOR(i,1,m){
        int x,y;scanf("%lld%lld",&x,&y);
        if(y >= q){
            for(int k = x;k <= n;k += y) ans[i] += a[k];
        }
        else{
            qq[y].pb(MP(i,x));
        }
    }
    FOR(y,1,q){
        if(qq[y].empty()) continue;
        sm[n+1] = 0;
        ROF(i,n,1) sm[i] = sm[i+y]+a[i];
        for(auto x:qq[y]){
            ans[x.fi] = sm[x.se];
        }
    }
    FOR(i,1,m) printf("%lld\n",ans[i]);puts("");
    return 0;
}
// newer