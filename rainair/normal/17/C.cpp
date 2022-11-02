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

const int MAXN = 150+5;
const int ha = 51123987;

int n;
char str[MAXN];

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}

int f[2][MAXN][MAXN][MAXN];
// i,j,a,b
int nxt[MAXN][3];

int main(){
    scanf("%d%s",&n,str+1);
    int now = 0;f[0][0][0][0] = 1;
    nxt[n+1][0] = nxt[n+1][1] = nxt[n+1][2] = n+1;
    ROF(i,n,0){
        FOR(j,0,2) nxt[i][j] = nxt[i+1][j];
        if(i)nxt[i][str[i]-'a'] = i;
    }
    FOR(i,1,n){
        CLR(f[now^1],0);
        FOR(j,0,n){
            FOR(a,0,i-1){
                FOR(b,0,i-1-a){
                    if(!f[now][j][a][b]) continue;
                    int nj = nxt[j][0];
                    if(nj <= n) add(f[now^1][nj][a+1][b],f[now][j][a][b]);
                    nj = nxt[j][1];
                    if(nj <= n) add(f[now^1][nj][a][b+1],f[now][j][a][b]);
                    nj = nxt[j][2];
                    if(nj <= n) add(f[now^1][nj][a][b],f[now][j][a][b]);
                }
            }
        }
        now ^= 1;
    }
    int ans = 0;
    FOR(a,0,n){
        FOR(b,0,n-a){
            int c = n-a-b;
            if(std::abs(std::max({a,b,c})-std::min({a,b,c})) <= 1) FOR(k,1,n) add(ans,f[now][k][a][b]);
        }
    }
    printf("%d\n",ans);
    return 0;
}