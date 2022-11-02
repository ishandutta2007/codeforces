#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e5 + 5;
int a[MAXN],n;LL sm;

int main(){
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i),sm += a[i];
    LL d = sm/n,r = sm%n;
    std::sort(a+1,a+n+1);std::reverse(a+1,a+n+1);
    LL res = 0;
    FOR(i,1,r) res += std::abs(a[i]-(d+1));
    FOR(i,r+1,n) res += std::abs(a[i]-d);
    res >>= 1;printf("%lld\n",res);
    return 0;
}