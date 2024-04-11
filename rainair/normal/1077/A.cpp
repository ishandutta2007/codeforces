#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define CLR(a,b) memset(a,b,sizeof(a))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

inline void Solve(){
    LL a,b,k;
    scanf("%I64d%I64d%I64d",&a,&b,&k);
    LL t = k/2;
    LL ans = (a-b)*t;
    if(k & 1) ans += a;
    printf("%I64d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--)Solve();
    return 0;
}