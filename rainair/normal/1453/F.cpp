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

const int MAXN = 3000+5;
int a[MAXN],f[MAXN][MAXN],n;
int cf[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,0,n+2) FOR(j,0,n+2) f[i][j] = 1e9;
    f[n][n] = f[n][n+1] = 0;
    ROF(i,n-1,1){
        CLR(cf,0);int now = 0;
        FOR(j,i+1,i+a[i]){
            now += cf[j];
            f[i][j] = std::min(f[i][j],f[j][i+a[i]+1]+now);
            now++;cf[j+a[j]+1]--;
        }
        ROF(j,n,i+1) f[i][j] = std::min(f[i][j],f[i][j+1]);
    }
    int ans = 1e9;
    FOR(i,2,1+a[1]) ans = std::min(ans,f[1][i]);
    printf("%d\n",ans);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}