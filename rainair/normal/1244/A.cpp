/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-13 17:05:55
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
inline void Solve(){
    int a,b,c,d,k;
    scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
    FOR(i,1,k-1){
        int j = k-i;
        if(i*c >= a && j*d >= b){
            printf("%lld %lld\n",i,j);
            return;
        }
    }
    puts("-1");
}
 
signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}