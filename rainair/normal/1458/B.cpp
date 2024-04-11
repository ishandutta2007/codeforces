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

const int MAXN = 100+5;
int a[MAXN],b[MAXN];
int n;
int f[2][MAXN][MAXN*MAXN],now;

inline void upmax(int &x,int y){
    if(x < y) x = y;
}

int main(){
    scanf("%d",&n);
    int sm = 0,s2 = 0;
    FOR(i,1,n) scanf("%d%d",a+i,b+i),sm += a[i],s2 += b[i];
    CLR(f[now],-0x3f);f[now][0][0] = 0;
    FOR(i,1,n){
        CLR(f[now^1],-0x3f);
        FOR(j,0,i-1){
            FOR(k,0,sm){
                if(f[now][j][k] == -0x3f3f3f3f) continue;
                upmax(f[now^1][j][k],f[now][j][k]);
                upmax(f[now^1][j+1][k+a[i]],f[now][j][k]+b[i]);
            }
        }
        now ^= 1;
    }
    FOR(k,1,n){// f[now][i]
        double ans = 0;
        FOR(x,0,sm){
            if(f[now][k][x] == -0x3f3f3f3f) continue;
            ans = std::max(ans,std::min(1.0*x,f[now][k][x]+(s2-f[now][k][x])/2.0));
        }
        printf("%.10f ",ans);
    }
    puts("");
    return 0;
}