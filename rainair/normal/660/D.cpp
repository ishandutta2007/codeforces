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

const int MAXN = 2000+5;
int n;
LL x[MAXN],y[MAXN];
std::vector<P<LL,LL> > S;

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%lld%lld",x+i,y+i);
    FOR(i,1,n){
        FOR(j,i+1,n){
            S.pb(MP(x[i]+x[j],y[i]+y[j]));
        }
    }
    std::sort(all(S));
    LL ans = 0;
    for(int l = 0,r;l < SZ(S);l = r+1){
        r = l;while(r+1 < SZ(S) && S[r+1] == S[l]) ++r;
        LL c = 1ll*(r-l+1)*(r-l)/2;
        ans += c;
    }
    printf("%lld\n",ans);
    return 0;
}