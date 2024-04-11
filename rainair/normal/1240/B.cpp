/*
 * Author: RainAir
 * Time: 2019-10-07 00:06:11
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

const int MAXN = 3e5 + 5;
int n,a[MAXN],ps[MAXN],sp[MAXN];
int pre[MAXN],suf[MAXN];
int pe[MAXN],sf[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),ps[a[i]] = 192;
    int ans = 1e9,cnt = 0;
    FOR(i,1,n) if(ps[i] == 192) sp[i] = ++cnt;
    FOR(i,1,n){
        a[i] = sp[a[i]];
        if(!pre[a[i]]) pre[a[i]] = i;
        suf[a[i]] = i;
    }
    pe[1] = 1;
    FOR(i,2,cnt) pe[i] = (pre[i] > suf[i-1]) ? pe[i-1]+1 : 1;
    sf[cnt] = 1;
    ROF(i,cnt-1,1) sf[i] = (suf[i] < pre[i+1]) ? sf[i+1]+1 : 1;
    sf[cnt+1] = 0;
    FOR(i,0,cnt) ans = std::min(ans,suf[i] < pre[i+1] ? cnt-pe[i]-sf[i+1] : std::min(cnt-pe[i],cnt-sf[i+1]));
    printf("%d\n",ans);
    FOR(i,1,n) ps[i] = sp[i] = pre[i] = suf[i] = pe[i] = sf[i] = 0;
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}