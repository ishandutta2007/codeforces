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

const int MAXN = 600+5;
int n,a[MAXN];
bool vis[MAXN];
int f[2][MAXN],now;

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",a+i);
        std::sort(a+1,a+n+1);
        CLR(f,0x3f);
        f[now = 0][0] = 0;
        FOR(i,1,n){
            CLR(f[now^1],0x3f);
            FOR(j,0,3*n){
                if(f[now][j] == 0x3f3f3f3f) continue;
                FOR(k,j+1,3*n){
                    f[now^1][k] = std::min(f[now^1][k],f[now][j]+std::abs(a[i]-k));
                }
            }
            now ^= 1;
        }
        int ans = 1e9;
        FOR(i,1,3*n) ans = std::min(ans,f[now][i]);
        printf("%d\n",ans);
    }
    return 0;
}