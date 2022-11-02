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

int N,M;
int pos = 1;
LL ans = 0ll;

int main(){
    scanf("%d%d",&N,&M);
    while(M--){
        int x;scanf("%d",&x);
        ans += x-pos;
        if(x < pos) ans += N;
        pos = x;
    }
    printf("%lld\n",ans);
    return 0;
}