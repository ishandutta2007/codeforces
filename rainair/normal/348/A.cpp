#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define Re register
#define LL long long
#define U unsigned
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define RFOR(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

int N;
LL sum,max;

int main(){
    scanf("%d",&N);
    FOR(i,1,N){
        LL x;scanf("%lld",&x);
        sum += x;max = std::max(max,x);
    }
    LL k = ceil((double)sum/(double)(N-1));
    printf("%lld\n",std::max(max,k));
    return 0;
}