/*
 * Author: RainAir
 * Time: 2020-05-28 22:46:54
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
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(LL i = a;i <= b;++i)
#define ROF(i,a,b) for(LL i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
int h,c,t;
long double f(LL n){
    return 1.0*(h*(n+1)+c*n)/(2*n+1);
}

inline void Solve(){
    scanf("%lld%lld%lld",&h,&c,&t);
    int l = 0,r = 1e9,ans = -1;long double ans1 = std::fabs(1.0*(h+c)/2-t);
    while(l <= r){
        LL mid = (l + r) >> 1;
        if(f(mid) <= t) ans = mid,r = mid-1;
        else l = mid+1;
    }
    int res=0;
    if(ans != -1){
        long double mn = 1e9;int ps = 0;
        FOR(i,std::max(0ll,ans-23),ans+23){
            if(std::fabs(f(i)-t) < mn) mn = std::fabs(f(i)-t),ps = i;
        }
        if(mn < ans1) res = 2*ps+1;
    }
    else res = 2;
    printf("%lld\n",res);
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}