#include <bits/stdc++.h>

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

const int MAXN = 3e5 + 5;

int a[MAXN];
LL f[MAXN][2];

inline void Solve(){
    int n,q;scanf("%d%d",&n,&q);
    FOR(i,1,n) scanf("%d",a+i),f[i][0] = f[i][1] = -1e18;
    f[0][1] = 0;f[0][0] = -1e18;
    LL ans = -1e18;
    FOR(i,1,n){
        FOR(j,0,1){
            if(f[i-1][j] == -1e18) continue;
            f[i][j] = std::max(f[i][j],f[i-1][j]);
            f[i][j^1] = std::max(f[i][j^1],f[i-1][j]+a[i]*((j==0)?-1:1));
        }
        ans = std::max(ans,f[i][0]);ans = std::max(ans,f[i][1]);
    }
    printf("%lld\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}