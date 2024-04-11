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

const int MAXN = 3e5 + 5;
int n,m,p[MAXN],ps[MAXN];
int a[MAXN],b[MAXN];
std::vector<int> G[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",p+i),ps[p[i]] = i;
    FOR(i,1,m) scanf("%d%d",a+i,b+i);
    FOR(i,1,m) if(ps[a[i]] < ps[b[i]]) std::swap(a[i],b[i]);
    FOR(i,1,m) G[ps[a[i]]].pb(ps[b[i]]);
    LL ans = 0;int mx = 0;
    FOR(i,1,n){
        for(auto x:G[i]) mx = std::max(mx,x);
        ans += i-mx;
    }
    printf("%lld\n",ans);
    return 0;
}