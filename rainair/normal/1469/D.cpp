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
std::vector<P<int,int> > S;
const int MAXN = 2e5 + 5;
int a[MAXN];

inline void Solve(){
    int n;scanf("%d",&n);S.clear();
    int tt = n;
    while(n > 2){
        int q = std::max(2,(int)std::sqrt(1.0*n));
        ROF(i,n-1,q+1) S.pb(MP(i,n));
        int t = n;
        while(t != 1){
            S.pb(MP(n,q));
            t = (t+q-1)/q;
        }
        n = q;
    }
    printf("%d\n",SZ(S));
//    FOR(i,1,tt) a[i] = i;
//    for(auto x:S) a[x.fi] = (a[x.fi]+a[x.se]-1)/a[x.se];
//    int cnt = 0;
//    FOR(i,1,tt){
//        if(a[i] > 2) assert(0);
//        if(a[i] == 1) ++cnt;
//    }    assert(cnt==tt-1);
    for(auto x:S) printf("%d %d\n",x.fi,x.se);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}