/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-13 18:41:19
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
const int MAXN = 1e6 + 5;
int n,k;
int a[MAXN],b[MAXN];
int ans = 0;
 
signed main(){
    scanf("%lld%lld",&n,&k);
    FOR(i,1,n) a[i] = b[i] = i,ans += i;
    if(ans > k){
        puts("-1");return 0;
    }
    FOR(i,1,n){
        int gx = n-i+1-i;
        if(gx < 0) break;
//        DEBUG(i);DEBUG(ans);
        if(ans+gx == k){
            std::swap(b[i],b[n-i+1]);
            ans += gx;
            printf("%lld\n",ans);
            FOR(i,1,n) printf("%lld ",a[i]);puts("");
            FOR(i,1,n) printf("%lld ",b[i]);puts("");
            return 0;
        }
        if(ans+gx < k){
            ans += gx;
            std::swap(b[i],b[n-i+1]);
        }
        else{
            int d = ans+gx-k;
            std::swap(b[i],b[n-i-d+1]);
            break;
        }
        if(i > (n+1)/2){
            break;
        }
    }
    ans = 0;
    FOR(i,1,n) ans += std::max(a[i],b[i]);
    printf("%lld\n",ans);
    FOR(i,1,n) printf("%lld ",a[i]);puts("");
    FOR(i,1,n) printf("%lld ",b[i]);puts("");
    return 0;
}