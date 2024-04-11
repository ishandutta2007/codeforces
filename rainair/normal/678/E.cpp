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

const int MAXN = 18;
DB p[MAXN][MAXN];
int n;
DB f[(1<<MAXN)+3];

int main(){
    scanf("%d",&n);
    FOR(i,0,n-1) FOR(j,0,n-1) scanf("%lf",&p[i][j]);
    f[1] = 1;
    FOR(S,2,(1<<n)-1){
        FOR(i,0,n-1){
            if(!((S>>i)&1)) continue;
            FOR(j,i+1,n-1){
                if(!((S>>j)&1)) continue;
                f[S] = std::max(f[S],f[S^(1<<j)]*p[i][j]+f[S^(1<<i)]*p[j][i]);
            }
        }
    }
    printf("%.10f\n",f[(1<<n)-1]);
    return 0;
}