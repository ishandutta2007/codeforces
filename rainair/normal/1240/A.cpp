/*
 * Author: RainAir
 * Time: 2019-10-06 23:12:15
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

int n,p[MAXN];
int gx[MAXN];
int x,a,y,b,k;
std::vector<int> t;

inline bool chk(int k){
    t.clear();
    FOR(i,1,k) t.pb(gx[i]);
    std::sort(all(t));std::reverse(all(t));
    int ans = 0;
    FOR(i,1,k) ans += t[i-1]*p[i];
    return ans >= ::k;
}

inline void Solve(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",p+i);std::sort(p+1,p+n+1);std::reverse(p+1,p+n+1);
    FOR(i,1,n) p[i] /= 100;
    scanf("%lld%lld%lld%lld%lld",&x,&a,&y,&b,&k);
    FOR(i,1,n) gx[i] = 0;
    FOR(i,1,n) if(!(i%a)) gx[i] += x;
    FOR(i,1,n) if(!(i%b)) gx[i] += y;
    int l = 1,r = n,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%lld\n",ans);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}