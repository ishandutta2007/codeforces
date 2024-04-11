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
const int MAXN = 2e5 + 5;
int n,m,x,k,y;
int a[MAXN],b[MAXN];
bool is[MAXN];
std::vector<P> S;
std::vector<int> ps;

signed main(){
    scanf("%lld%lld%lld%lld%lld",&n,&m,&x,&k,&y);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,m) scanf("%lld",b+i);
    int now = 1;
    FOR(i,1,m){
        while(now <= n && a[now] != b[i]) now++;
        if(now > n){
            puts("-1");return 0;
        }
        ps.pb(now);
    }
    if(ps[0] != 1) S.pb(MP(1,ps[0]-1));
    FOR(i,1,(int)ps.size()-1) S.pb(MP(ps[i-1]+1,ps[i]-1));
    if(ps[(int)ps.size()-1] != n) S.pb(MP(ps[(int)ps.size()-1]+1,n));
    LL ans = 0;
    for(auto x:S){
        if(x.fi > x.se) continue;
        int len = x.se-x.fi+1,mx = 0;
        int v = std::max(a[x.fi-1],a[x.se+1]);
        FOR(i,x.fi,x.se) mx = std::max(mx,a[i]);
        if(len < k){
            if(mx > v){
                puts("-1");return 0;
            }
            ans += 1ll*len*y;
            continue;
        }
        if(::x > k*y){
            if(mx < v) ans += 1ll*len*y;
            else ans += ::x+(len-k)*y;
        }
        else{
            ans += 1ll*(len%k)*y+(LL)(len/k)*::x;
        }
    }
    printf("%lld\n",ans);
    return 0;
}