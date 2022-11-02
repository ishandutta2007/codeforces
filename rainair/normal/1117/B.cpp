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
int n,m,k;
int a[MAXN];

signed main(){
    scanf("%I64d%I64d%I64d",&n,&m,&k);
    FOR(i,1,n) scanf("%I64d",a+i);
    std::sort(a+1,a+n+1,std::greater<int>());
    LL ans = 0;
    ans += m/(k+1)*(k*a[1]+a[2]);
    LL res = m-(k+1)*(m/(k+1));
    ans += res*a[1];
    printf("%I64d\n",ans);
    return 0;
}