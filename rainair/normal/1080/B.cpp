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
int q,N;
signed main(){
    scanf("%I64d",&q);
    while(q--){
        int l,r,ans=0;
        scanf("%I64d%I64d",&l,&r);
        if(!(l & 1)){
            ans += l;
            l++;
        }
        if(r & 1){
            ans -= r;
            r--;
        }
        ans += (r-l+1)/2;
        printf("%I64d\n",ans);
    }
    return 0;
}