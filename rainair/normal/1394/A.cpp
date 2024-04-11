/*
 * Author: RainAir
 * Time: 2020-05-29 15:55:28
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
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 5e5 + 5;
int n,d,m;
int a[MAXN];
int sm[MAXN];

signed main(){
    scanf("%lld%lld%lld",&n,&d,&m);
    FOR(i,1,n) scanf("%lld",a+i);
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
    int ans = 0;FOR(i,1,n) if(a[i] <= m) ans += a[i];
    FOR(i,1,n) sm[i] = sm[i-1]+a[i];
    int p = 0;FOR(i,1,n) if(a[i] > m) p = i;
    FOR(i,1,p){
        if(n-i < (i-1)*d) break;
        int now = sm[i],req = (i-1)*d;
        if(req < p-i){
            now += sm[n]-sm[p];
        }
        else{
            req -= p-i;
            now += sm[n-req]-sm[p];
        }
        ans = std::max(ans,now);
    }
    printf("%lld\n",ans);
    return 0;
}