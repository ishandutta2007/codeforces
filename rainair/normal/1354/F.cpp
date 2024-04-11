#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

const int MAXN = 75+5;

int n,k,a[MAXN],b[MAXN],id[MAXN];
LL f[MAXN][MAXN][MAXN][2];
int opt[MAXN];
std::tuple<int,int,int> p[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n){
        int x,y;scanf("%d%d",&x,&y);
        p[i] = std::tie(y,x,i);
    }
    std::sort(p+1,p+n+1);
    FOR(i,1,n) std::tie(b[i],a[i],id[i]) = p[i];
    CLR(f,-0x3f);f[0][0][0][0] = 0;
    FOR(i,1,n){
        FOR(j,0,n){
            FOR(k,0,n-j){
                FOR(l,0,1){
                    if(f[i-1][j][k][l] == -0x3f3f3f3f) continue;
                    f[i][j+1][k][l] = std::max(f[i][j+1][k][l],f[i-1][j][k][l]+a[i]+b[i]*j);
                    f[i][j][k+1][l] = std::max(f[i][j][k+1][l],f[i-1][j][k][l]+(::k-1)*b[i]);
                    if(!l) f[i][j][k][l+1] = std::max(f[i][j][k][l+1],f[i-1][j][k][l]+a[i]+(::k-1)*b[i]);
                }
            }
        }
    }
    CLR(opt,0);
    int nowa=k-1,nowb=n-k,nowc=1;
    ROF(i,n,1){
        LL w = f[i][nowa][nowb][nowc];
        if(nowa > 0 && f[i-1][nowa-1][nowb][nowc]+a[i]+b[i]*(nowa-1) == w){
            opt[i] = 1;
            nowa--;
        }
        else if(nowb > 0 && f[i-1][nowa][nowb-1][nowc]+(::k-1)*b[i] == w){
            opt[i] = 2;
            nowb--;
        }
        else if(nowc > 0 && f[i-1][nowa][nowb][nowc-1]+a[i]+(::k-1)*b[i] == w){
            opt[i] = 3;
            nowc--;
        }
        else{
            puts("ERR");
            return;
        }
    }
    printf("%d\n",k+(n-k)*2);
    FOR(i,1,n) if(opt[i] == 1) printf("%d ",id[i]);
    FOR(i,1,n) if(opt[i] == 2) printf("%d %d ",id[i],-id[i]);
    FOR(i,1,n) if(opt[i] == 3) printf("%d\n",id[i]);
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}