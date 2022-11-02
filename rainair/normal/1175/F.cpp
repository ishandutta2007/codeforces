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
std::mt19937 g(time(NULL));
int n,a[MAXN];
unsigned val[MAXN],sm[MAXN],len[MAXN];

int main(){
    LL ans = 0;
    scanf("%d",&n);FOR(i,1,n) scanf("%d",a+i),ans += (a[i]==1);
    FOR(i,1,n) val[i] = g(),len[i] = len[i-1]^val[i];
    auto work = [&](){
        FOR(i,1,n) sm[i] = sm[i-1]^val[a[i]];
        LL ans = 0;
        FOR(i,1,n){
            if(a[i] != 1) continue;
            int mx = 0;
            FOR(r,i+1,n){
                if(a[r] == 1) break;
                mx = std::max(mx,a[r]);
                int l = r-mx+1;
                ans += (l <= i && (sm[r]^sm[l-1])==len[r-l+1]);
            }
        }
        return ans;
    };
    ans += work();
    std::reverse(a+1,a+n+1);
    ans += work();
    printf("%lld\n",ans);
    return 0;
}