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

const int MAXN = 400+5;
const int ha = 998244353;
int n,c[26];
int f[2][MAXN][MAXN][3][3];
int g[2][MAXN][2][2],pw[MAXN];
int F[MAXN][MAXN],G[MAXN];
// 0=a 1=b 2=oth

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int main(){
    pw[0] = 1;FOR(i,1,MAXN-1) pw[i] = 25ll*pw[i-1]%ha;
    scanf("%d",&n);
    FOR(i,0,25) scanf("%d",c+i);
    int now = 0;
    f[now][0][0][2][2] = 24*24;
    f[now][1][0][2][0] = f[now][1][0][0][2] = 24;
    f[now][0][1][2][1] = f[now][0][1][1][2] = 24;
    f[now][1][1][0][1] = f[now][1][1][1][0] = 1;
    f[now][2][0][0][0] = f[now][0][2][1][1] = 1;
    FOR(i,3,n){
        CLR(f[now^1],0);
        FOR(a,0,n){
            FOR(b,0,n){
                FOR(c,0,2){
                    FOR(d,0,2){
                        // cd?
                        int gx = f[now][a][b][c][d];
                        if(!gx) continue;
                        if(c != 0) add(f[now^1][a+1][b][d][0],gx);
                        if(c != 1) add(f[now^1][a][b+1][d][1],gx);
                        add(f[now^1][a][b][d][2],1ll*gx*(c==2?23:24)%ha);
                    }
                }
            }
        }
        now ^= 1;
    }
    FOR(i,0,n) FOR(j,0,n) FOR(x,0,2) FOR(y,0,2) add(F[i][j],f[now][i][j][x][y]);
    ROF(i,n,0) ROF(j,n,1) add(F[i][j],F[i+1][j]),add(F[i][j],F[i][j+1]),add(F[i][j],ha-F[i+1][j+1]);
    now = 0;
    g[now][0][1][1] = 25*25;
    g[now][1][0][1] = g[now][1][1][0] = 25;
    g[now][2][0][0] = 1;
    FOR(i,3,n){
        CLR(g[now^1],0);
        FOR(a,0,n){
            FOR(c,0,1){
                FOR(d,0,1){
                    int gx = g[now][a][c][d];
                    if(!gx) continue;
                    if(c != 0) add(g[now^1][a+1][d][0],gx);
                    add(g[now^1][a][d][1],1ll*gx*(c==1?24:25)%ha);
                }
            }
        }
        now ^= 1;
    }
//    DEBUG(g[now][3][0][1]);
    FOR(i,0,n) FOR(x,0,1) FOR(y,0,1) add(G[i],g[now][i][x][y]);
    ROF(i,n,0) add(G[i],G[i+1]);
    auto calc = [&](int n){
        return 26ll*pw[n-1]%ha;
    };
    int ans = 1ll*calc(n/2)*calc((n+1)/2)%ha;
    FOR(i,0,25) add(ans,ha-G[c[i]+1]);
    FOR(i,0,25) FOR(j,i+1,25) add(ans,F[c[i]+1][c[j]+1]);
    printf("%d\n",ans);
    return 0;
}