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
const int MAXN = 200000+5;
int N,a[MAXN],t,l,max;

signed main(){
    scanf("%I64d",&N);
    FOR(i,1,N) scanf("%I64d",a+i),max = std::max(max,a[i]);
    FOR(i,1,N){
        t = std::max(t,l);
        if(a[i] == max && l) l++;
        if(a[i] == max && !l) l = 1;
        if(a[i] != max) l = 0;
        t = std::max(t,l);
    }
    printf("%I64d\n",t);
    return 0;
}