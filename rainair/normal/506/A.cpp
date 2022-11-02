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

const int MAXN = 30000+5;
const int MAXM = 300;
int n,d,a[MAXN];
int f[MAXN][MAXM*2+3];

inline void upmax(int &x,int y){
    if(x < y) x = y;
}

int main(){
    scanf("%d%d",&n,&d);
    FOR(i,1,n){
        int x;scanf("%d",&x);++a[x];
    }
    CLR(f,-0x3f);
    f[d][MAXM] = a[0]+a[d];
    FOR(i,d,30000){
        FOR(j,std::max(-MAXM,-d+1),MAXM){
            if(f[i][j+MAXM] == -0x3f3f3f3f) continue;
            if(i+d+j <= 30000) upmax(f[i+d+j][j+MAXM],f[i][j+MAXM]+a[i+d+j]);
            if(i+d+j+1 <= 30000) upmax(f[i+d+j+1][j+MAXM+1],f[i][j+MAXM]+a[i+d+j+1]);
            if(d+j-1 > 0 && i+d+j-1 <= 30000 && j+MAXM-1 >= 0){
                upmax(f[i+d+j-1][j+MAXM-1],f[i][j+MAXM]+a[i+d+j-1]);
            }
        }
    }
   // DEBUG(f[29889][-243+MAXM]);
    //DEBUG(a[29890]);
    int ans = 0;
    FOR(i,d,30000) FOR(j,0,2*MAXM) ans = std::max(ans,f[i][j]);
    printf("%d\n",ans);
    return 0;
}