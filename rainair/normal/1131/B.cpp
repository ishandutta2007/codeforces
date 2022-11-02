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
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define CLR(i,a) memset(i,a,sizeof(i))
#define BR printf("--------------------\n")
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
int N;
//[a,b] [c,d]
signed main(){
    scanf("%I64d",&N);
    int lx=0,ly=0,ans = 1;
    for(int i = 1;i <= N;i++){
        int x,y;scanf("%I64d%I64d",&x,&y);
        // [x,lx] [y,ly]
        ans += std::max(std::min(x,y)-std::max(lx,ly)+(lx!=ly),0ll);
        lx = x;ly = y;
        //DEBUG(ans);
    }
    printf("%I64d\n",ans);
    return 0;
}