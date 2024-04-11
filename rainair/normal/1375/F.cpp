#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

LL a[4];

inline int getmax(){
    LL t = std::max(a[1],std::max(a[2],a[3]));
    if(t == a[1]) return 1;
    if(t == a[2]) return 2;
    if(t == a[3]) return 3;
}

int main(){
    FOR(i,1,3) scanf("%lld",a+i);
    int ps = getmax();
    puts("First");std::fflush(stdout);LL t=0;
    printf("%lld\n",(LL)(2e9));std::fflush(stdout);
    scanf("%d",&ps);
    a[ps] += 2e9;
    printf("%lld\n",t=3*a[ps]-a[1]-a[2]-a[3]);std::fflush(stdout);
    scanf("%d",&ps);
    a[ps] += t;
    LL mx = 0;
    FOR(i,1,3) if(ps != i) mx = std::max(mx,a[i]);
    printf("%lld\n",a[ps]-mx);std::fflush(stdout);
    int x;scanf("%d",&x);
    return 0;
}