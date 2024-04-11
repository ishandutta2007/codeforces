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

const int MAXN = 1000+5;
const int ha = 998244353;
int f[MAXN][MAXN][2][26];
char s[MAXN],t[MAXN];
int n,m;

inline void add(int &x,int y){
    x += y-ha;x += x>>31&ha;
}
int pre[MAXN];

int main(){
//    DEBUG(sizeof(f)/1024/1024);
    scanf("%s%s",s+1,t+1);
    n = strlen(s+1);m = strlen(t+1);
    f[1][1][0][0] = 1;
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            FOR(k,0,1){
                int up = k==0?1:25;
                FOR(c,0,up){
                    int gx = f[i][j][k][c];
                    if(!gx) continue;
                    if(k == 0){
                        if(c == 0) add(f[i+1][j][k][c],gx),add(f[i][j][k][1],gx);
                        if(c == 1) add(f[i][j+1][k][c],gx);
                        if(i <= n && c == 1) add(f[i+1][j][1][s[i]-'a'],gx);
                        if(j <= m && c == 1) add(f[i][j+1][1][t[j]-'a'],gx);
                    }
                    else{
                        if(i <= n && s[i]-'a' != c) add(f[i+1][j][1][s[i]-'a'],gx);
                        if(j <= m && t[j]-'a' != c) add(f[i][j+1][1][t[j]-'a'],gx);
                    }
                }
            }
        }
    }
//    DEBUG(f[3][3][1][0]);
//    exit(0);
/*    
    FOR(i,1,n+1){
        FOR(j,1,m+1){
            FOR(c,0,25){
                if(f[i][j][1][c]){
                    printf("%d %d %c %d\n",i,j,'a'+c,f[i][j][1][c]);
                }
            }
        }
    }*/
    int ans = 0;
    FOR(i,2,n+1) FOR(j,2,m+1) FOR(c,0,25) add(ans,f[i][j][1][c]);
    int c = 0;pre[1] = 1;
    FOR(i,2,n) pre[i] = s[i]==s[i-1]?i:pre[i-1];
    FOR(i,1,n) add(c,i-pre[i]+1);
    c = 1ll*c*m%ha;add(ans,ha-c);

    c = 0;
    FOR(i,2,m) pre[i] = t[i]==t[i-1]?i:pre[i-1];
    FOR(i,1,m) add(c,i-pre[i]+1);
    c = 1ll*c*n%ha;add(ans,ha-c);
    printf("%d\n",ans);
    return 0;
}