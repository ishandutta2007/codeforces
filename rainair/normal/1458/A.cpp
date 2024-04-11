#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
LL a[MAXN],b[MAXN];
int n,m;

inline LL gcd(LL x,LL y){
    return !y ? x : gcd(y,x%y);
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,m) scanf("%lld",b+i);
    std::sort(a+1,a+n+1);
    LL g = 0;
    FOR(i,2,n) if(a[i] != a[1]) g = gcd(g,a[i]-a[1]);
    FOR(i,1,m){
        LL ans = gcd(g,a[1]+b[i]);
        printf("%lld ",ans);
    }
    puts("");
    return 0;
}