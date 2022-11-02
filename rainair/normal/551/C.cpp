/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-18 16:30:09
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
const int MAXN = 1e5 + 5;
int a[MAXN],b[MAXN];
int n,m;

inline bool chk(int k){
    FOR(i,1,n) b[i] = a[i];
    int now = 1;
    FOR(i,1,m){
        int t = k,ps = 0;
        while(t){
            while(now <= n && !b[now]) ++now;
            if(now > n) return true;
            t -= now-ps;ps = now;
            if(t <= 0) break;
            if(t > b[now]){
                t -= b[now];b[now] = 0;
            }
            else{
                b[now] -= t;t = 0;
            }
        }
    }
    while(now <= n && !b[now]) ++now;
    return now > n;
}

signed main(){
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n) scanf("%lld",a+i);
//    DEBUG(chk(3));
//    exit(0);
    int l = 0,r = 1e15,ans = -1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(chk(mid)) ans = mid,r = mid-1;
        else l = mid+1;
    }
    printf("%lld\n",ans);
    return 0;
}