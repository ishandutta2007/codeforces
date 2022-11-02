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

const int MAXN = 3e5 + 5;
int n;char str[MAXN];
int f[MAXN][2],g[MAXN][2];

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);scanf("%s",str+1);
        FOR(i,0,n+2) FOR(j,0,1) f[i][j] = g[i][j] = 0;
        f[0][0] = f[0][1] = 0;
        FOR(i,1,n){
            int o = (str[i] == 'R');
            f[i][o] = f[i-1][!o]+1;
        }
        g[n+1][0] = g[n+1][1] = 0;
        ROF(i,n,1){
            int o = (str[i] == 'R');
            g[i][o] = g[i+1][!o]+1;
        }
        FOR(i,0,n){
            printf("%d%c",1+std::max(f[i][0],0)+std::max(g[i+1][1],0)," \n"[i==n]);
        }
    }
    return 0;
}