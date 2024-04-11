#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define R register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(R int i = a;i <= b;++i)
#define RFOR(i,a,b) for(R int i = a;i >= b;--i)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int ha = 1e9+9;

LL N,M,K;

LL qpow(LL a,LL n){
    LL ret = 1ll;
    while(n){
        if(n & 1) ret = (ret * a) % ha;
        a = (a * a) % ha;
        n >>= 1;
    }
    return ret%ha;
}

int main(){
    scanf("%lld%lld%lld",&N,&M,&K);
    LL wp = N-M; // wrong_problems
    LL k = N / K;
    if(wp >= k){
        printf("%lld\n",M%ha);
        return 0;
    }
    LL kk = k-wp;
    LL ans = (K*(qpow(2,kk+1)-2)%ha)%ha;
    ans = (ans + M - kk*K + ha) % ha;
    printf("%lld\n",ans);
    return 0;
}