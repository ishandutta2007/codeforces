/*
 * Author: RainAir
 * Time: 2019-08-28 09:35:37
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
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e7 + 5;
const int ha = 1e9 + 7;

int f[MAXN],pc[MAXN],pw2[MAXN];
int n;

inline int qpow(int a,int n){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

inline void FMT(){
    FOR(i,0,20){
        FOR(S,0,(1<<20)-1){
            if(!(S&(1<<i))) f[S] += f[S|(1<<i)];
        }
    }
}

signed main(){
    FOR(i,1,MAXN-1) pc[i] = pc[i>>1]+(i&1);pw2[0] = 1;
    scanf("%lld",&n);
    FOR(i,1,n){
        int x;scanf("%lld",&x);
        f[x]++;
    }
    FMT();int ans = 0;
    FOR(S,0,(1<<20)-1){
        ans = (ans+qpow(2,f[S])*(pc[S]&1?-1:1)+ha)%ha;
    }
    printf("%lld\n",ans);
    return 0;
}