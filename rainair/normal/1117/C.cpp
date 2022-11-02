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
// zblzblSBSB
#define fi first
#define lc (x<<1)
#define se second
#define U unsigned
#define rc (x<<1|1)
#define Re register
#define LL long long
#define MP std::make_pair
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define SFOR(i,a,b,c) for(Re int i = a;i <= b;i+=c)
#define SROF(i,a,b,c) for(Re int i = a;i >= b;i-=c)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 2e5 + 5;

int N,x11,y11,x2,y2;
char str[MAXN];
int sumx[MAXN],sumy[MAXN];

LL myabs(LL x){
    if(x < 0) return -x;
    return x;
}

inline bool check(int k){
    // int aa = k/N,bb = k%N;
    // int dx = aa*sumx[N]+sumx[bb],dy = aa*sumy[N]+sumy[bb];
    // return (myabs(x11+dx-x2) + myabs(y11+dy-y2)) <= k;

    LL x = x11+sumx[N]*(k/N),y = y11+sumy[N]*(k/N);
    LL pos = k-N*(k/N);
    x += sumx[pos];y += sumy[pos];
    if(std::abs(x2-x)+std::abs(y2-y) <= k) return true;
    return false;
}

signed main(){
    sumx[0] = sumy[0] = 0ll;
    scanf("%I64d%I64d%I64d%I64d",&x11,&y11,&x2,&y2);
    scanf("%I64d",&N);
    scanf("%s",str+1);
    //FOR(i,1,99999) str[i] == 'L';str[N] = 'U';
    FOR(i,1,N){
        sumx[i] = sumx[i-1];sumy[i] = sumy[i-1];
        if(str[i] == 'U') sumy[i] = sumy[i-1] + 1;
        if(str[i] == 'D') sumy[i] = sumy[i-1] - 1;
        if(str[i] == 'L') sumx[i] = sumx[i-1] - 1;
        if(str[i] == 'R') sumx[i] = sumx[i-1] + 1;
    }
    int L = 0,R = 1e15,ans = -1;
    // -2 +1
    if(!check(R)){
        puts("-1");return 0;
    }
    while(L < R){
        int mid = (L+R)>>1;
        if(check(mid)) R = mid;
        else L = mid+1;
    }
    printf("%I64d\n",L);
    return 0;
}
/*

*/