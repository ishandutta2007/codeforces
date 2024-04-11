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

const int MAXN = 1e5 + 5;
int n;LL a[MAXN];
int deg[MAXN];

inline void Solve(){
    scanf("%d",&n);FOR(i,1,n) scanf("%lld",a+i),deg[i]= 0;
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);++deg[u];++deg[v];
    }
    std::vector<P<int,int> > S;
    FOR(i,1,n) if(deg[i] > 1) S.pb(MP(a[i],deg[i]-1));
    std::sort(all(S));std::reverse(all(S));
    LL ans = 0;FOR(i,1,n) ans += a[i];
    printf("%lld ",ans);
    for(auto x:S){
        FOR(i,1,x.se){
            ans += x.fi;
            printf("%lld ",ans);
        }
    }
    puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}