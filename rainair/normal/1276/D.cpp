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

const int MAXN = 2e5 + 5;
const int ha = 998244353;

std::vector<int> G[MAXN];
int n;
int f[MAXN][4];
// 0: 
// 1: 
// 2: 
// 3: 

int a[MAXN],b[MAXN],c[MAXN];

inline void dfs(int v,int fa=0){
    bool fg = 0;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);fg = 1;
    }
    if(!fg && v != 1){
        f[v][0] = f[v][2] = 1;
        return;
    }
    int m = 0,fe = 0;
    for(auto x:G[v]){
        if(x == fa) fe = m;
        else{
            a[++m] = (f[x][1]+f[x][2])%ha;
            b[m] = (f[x][0]+f[x][3])%ha;
            c[m] = (0ll+f[x][0]+f[x][1]+f[x][3])%ha;
        }
    }
    a[0] = c[m+1] = 1;
    FOR(i,1,m) a[i] = 1ll*a[i-1]*a[i]%ha;
    ROF(i,m,1) c[i] = 1ll*c[i+1]*c[i]%ha;
    FOR(i,1,m){
        if(i <= fe){
            (f[v][1] += 1ll*a[i-1]*b[i]%ha*c[i+1]%ha)%=ha;
        }
        else{
//            DEBUG(a[i-1]);DEBUG(b[i]);DEBUG(c[i+1]);
            (f[v][3] += 1ll*a[i-1]*b[i]%ha*c[i+1]%ha)%=ha;
        }
    }
    f[v][2] = 1ll*a[fe]*c[fe+1]%ha;f[v][0] = a[m];
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    dfs(1);
    int ans = ((f[1][0]+f[1][1])%ha+f[1][3])%ha;
    printf("%d\n",ans);
    return 0;
}