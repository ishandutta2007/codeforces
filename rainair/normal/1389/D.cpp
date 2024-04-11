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
inline void Solve(){
    int n,k,l1,r1,l2,r2;scanf("%lld%lld%lld%lld%lld%lld",&n,&k,&l1,&r1,&l2,&r2);
    if(!k){
        puts("0");return;
    }
    if(l1 > l2) std::swap(l1,l2),std::swap(r1,r2);
    if(l1 <= l2 && r2 <= r1){
        k -= n*(r2-l2);k = std::max(k,0ll);
        if(k == 0){
            puts("0");return;
        }
        int lim = n*(l2-l1+r1-r2);
        if(k <= lim) printf("%lld\n",k);
        else printf("%lld\n",lim+(k-lim)*2);
        return;
    }
    if(l1 <= l2 && r1 <= r2 && l2 <= r1){
        k -= n*(r1-l2);k = std::max(k,0ll);
        if(k == 0){
            puts("0");return;
        }
        int lim = (l2-l1 + r2-r1)*n;
        if(k <= lim){
            printf("%lld\n",k);
            return;
        }
        printf("%lld\n",lim+2*(k-lim));
        return;
    }
    int ans = 1e18;
    FOR(i,1,n){
        int now = i*(l2-r1),gx = i*(r2-l1);
        if(k <= gx) ans = std::min(ans,now+k);
        else ans = std::min(ans,now+gx+2*(k-gx));
    }
    printf("%lld\n",ans);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}