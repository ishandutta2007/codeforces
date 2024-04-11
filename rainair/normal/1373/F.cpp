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

const int MAXN = 2e6 + 5;
LL n,a[MAXN],b[MAXN],c[MAXN],pre[MAXN],suf[MAXN];

inline void Solve(){
    scanf("%lld",&n);LL sm0=0,sm1=0;
    FOR(i,0,n-1) scanf("%lld",a+i),sm0 += a[i];
    FOR(i,0,n-1) scanf("%lld",b+i),sm1 += a[i];
    if(sm0 > sm1){
        puts("NO");return;
    }
    FOR(i,0,n-1) c[i] = b[i]-a[(i+1)%n];c[n] = 0;
    FOR(i,1,n-1) c[i] += c[i-1];
    if(c[n-1] < 0){
        puts("NO");return;
    }
    pre[0] = c[0];
    FOR(i,1,n-1) pre[i] = std::max(pre[i-1],c[i]);
    suf[n] = 1e18;
    ROF(i,n-1,1) suf[i] = std::min(suf[i+1],c[n-1]-c[i-1]);
    suf[0] = std::min(suf[1],c[n-1]);
    ROF(i,n-1,0){
        LL now = a[(i+1)%n]+c[i]-std::max(0ll,pre[i]);
 //       if(i == n-1) DEBUG(suf[i]);
        if(now < 0){
            puts("NO");return;
        }
        now = a[(i+1)%n]+c[i]+std::min(0ll,suf[i+1]);
        if(now < 0){
            puts("NO");return;
        }
    }
    puts("YES");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}