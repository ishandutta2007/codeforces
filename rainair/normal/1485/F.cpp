#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
const int ha = 1e9 + 7;
int n,a[MAXN];
std::map<LL,int> S;

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    int sm = 1;S.clear();S[0] = 1;LL offset = 0;
    FOR(i,1,n){
        int t = sm;add(t,ha-S[-offset]);
        offset += a[i];
        add(S[a[i]-offset],t);
        add(sm,t);

        //for(auto x:S) printf("%lld %d\n",x.fi+offset,x.se);
        //DEBUG(sm);
        //puts("");
    }
    int ans = 0;
    for(auto &x:S) add(ans,x.se);
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}