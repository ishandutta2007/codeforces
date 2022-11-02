/*
 * Author: RainAir
 * Time: 2020-07-10 09:47:41
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

const int MAXN = 1e6 + 5;
LL a[MAXN];
int n;

inline LL get(LL d){
    LL ans = 0;
    FOR(i,1,n) ans += std::min(a[i]%d,d-a[i]%d);
    return ans;
}

int main(){
    scanf("%d",&n);LL sm = 0,mn = 1e18;
    FOR(i,1,n) scanf("%lld",a+i),sm += a[i];
    FOR(i,1,n) if(a[i]) mn = std::min(mn,a[i]);
    if(sm == 1){
        puts("-1");return 0;
    }
    FOR(i,2,n) a[i] += a[i-1];
    LL q = std::sqrt(1.0*sm),ans = 1e18;
    FOR(i,2,q){
        if(!(sm%i)){
            while(!(sm%i)) sm /= i;
            ans = std::min(ans,get(i));
        }
    }
    if(sm > 1) ans = std::min(ans,get(sm));
    printf("%lld\n",ans);
    return 0;
}