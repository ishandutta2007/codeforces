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

const int MAXN = 1000000+5;
int n;bool rev;
int a[MAXN],b[MAXN];
LL sa[MAXN],sb[MAXN];
std::pair<int,int> p[MAXN];

signed main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i),sa[i] = sa[i-1]+a[i];
    FOR(i,1,n) scanf("%d",b+i),sb[i] = sb[i-1]+b[i];
    if(sa[n] < sb[n]) std::swap(sa,sb),rev = true;
    int tot = 0,i;LL t;
    FOR(i,0,n) p[i] = std::make_pair(-1,-1);
    for(i = 0;i <= n;++i){
        while(sa[i] >= sb[tot+1] && tot+1 <= n) ++tot;
        t = sa[i] - sb[tot];
        if(p[t].first == -1) p[t] = std::make_pair(i,tot);
        else break;
    }
    if(rev){
        std::swap(p[t].first,p[t].second);std::swap(sa,sb);
        std::swap(i,tot);
    }
    printf("%d\n",i-p[t].first);
    FOR(j,p[t].first+1,i) printf("%d ",j);puts("");
    printf("%d\n",tot-p[t].second);
    FOR(j,p[t].second+1,tot) printf("%d ",j);puts("");
    return 0;
}//