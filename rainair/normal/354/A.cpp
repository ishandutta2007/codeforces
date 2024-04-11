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
#define int LL
const int MAXN = 1e5 + 5;
int l,r,ql,qr,n;
int w[MAXN];

signed main(){
    scanf("%lld%lld%lld%lld%lld",&n,&l,&r,&ql,&qr);
    FOR(i,1,n) scanf("%lld",w+i),w[i] += w[i-1];
    LL ans = r*w[n]+(n-1)*qr;
    FOR(i,1,n){
        LL gx = w[i]*l+(w[n]-w[i])*r;
        if(i > n-i) gx += std::max(0ll,ql*(i-(n-i)-1));
        else gx += std::max(0ll,qr*((n-i)-i-1));
        ans = std::min(ans,gx);
    }
    printf("%lld\n",ans);
    return 0;
}