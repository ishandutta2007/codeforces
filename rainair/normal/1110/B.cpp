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

const int MAXN = 100000+5;
int n,m,k;
int a[MAXN];
std::vector<int> SS;

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,2,n) SS.push_back(a[i]-a[i-1]+1);
    int ans = 0;std::sort(SS.begin(),SS.end());
    FOR(i,0,n-k-1) ans += SS[i];
    ans += n-2*(n-k);
    printf("%d\n",ans);
    return 0;
}
//2 3 57 18