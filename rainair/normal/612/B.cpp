#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 5e5 + 5;
int n,a[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n){
        int x;scanf("%d",&x);a[x] = i;
    }
    LL ans = 0;
    FOR(i,2,n) ans += std::abs(a[i]-a[i-1]);
    printf("%lld\n",ans);
    return 0;
}