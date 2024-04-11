/*
 * Author: RainAir
 * Time: 2019-08-03 20:00:00
 */
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
#define U unsigned
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;
const int ha = 1e9 + 7;

std::vector<int> G[MAXN];
int n,K;
int fac[205],S[205][205];
int f[MAXN][205],sz[MAXN],ans[MAXN];

inline void dfs(int v,int fa=0){
    sz[v] = 1;f[v][0] = 1;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);
        static int tmp[500+5];CLR(tmp,0);
        FOR(i,0,(int)sz[v]-1){
            if(i > K) break;
            FOR(j,0,(int)sz[x]-1){
                if(i+j > K) break;
                (tmp[i+j] += f[v][i]*f[x][j]%ha) %= ha;
                (tmp[i+j+1] += f[v][i]*f[x][j]%ha) %= ha;
                (ans[i+j] += f[v][i]*f[x][j]%ha) %= ha;
                (ans[i+j+1] += f[v][i]*f[x][j]%ha) %= ha;
            }
        }
        FOR(i,0,K) f[v][i] = (f[v][i] + tmp[i] + f[x][i] + ((i == 0) ? 0 : f[x][i-1]))%ha;
        sz[v] += sz[x]; 
    }
}

signed main(){
    scanf("%lld%lld",&n,&K);
    FOR(i,1,n-1){
        int u,v;scanf("%lld%lld",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    S[0][0] = 1;fac[0] = 1;
    FOR(i,1,K){
        fac[i] = 1ll*fac[i-1]*i%ha;
        FOR(j,1,K){
            S[i][j] = (1ll*S[i-1][j]*j%ha+S[i-1][j-1]) % ha;
        }
    }
    dfs(1);int res = 0;
    FOR(i,0,K){
        (res += 1ll*fac[i]*S[K][i]%ha*ans[i]%ha) %= ha;
    }
    printf("%lld\n",res);
    return 0;
}