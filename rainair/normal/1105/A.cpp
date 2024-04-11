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

#define fi first
#define se second
#define U unsigned
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 10000+5;
int a[MAXN],N;
int ans1,ans2;

int main(){
    scanf("%d",&N);
    FOR(i,1,N) scanf("%d",a+i);
    ans2 = INT_MAX;
    FOR(t,1,100){
        int gx = 0;
        FOR(i,1,N){
            gx += std::min(std::abs((t-1)-a[i]),std::min(std::abs((t+1)-a[i]),std::abs(t-a[i])));
           // DEBUG(std::abs((t-1)-a[i]));
           // DEBUG(std::abs((t+1)-a[i]));
        }
        if(gx < ans2) ans2 = gx,ans1 = t;
    }
    printf("%d %d\n",ans1,ans2);
   // system("pause");
    return 0;
}