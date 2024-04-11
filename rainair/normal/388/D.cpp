/*
 * Author: RainAir
 * Time: 2019-10-08 10:02:13
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 40+5;
const int ha = 1e9 + 7;
int f[MAXN][MAXN][2],pw[MAXN];
//  i  j 
int a[MAXN],len;

inline int dfs(int i,int j,int lim){
    if(!i) return 1;
    if(f[i][j][lim] != -1) return f[i][j][lim];
    int ans = 0;
    if(!lim){
        (ans += 1ll*dfs(i-1,j,0)*pw[j]%ha) %= ha;
        (ans += dfs(i-1,j+1,0)) %= ha;
    }
    else{
        (ans += (1ll*dfs(i-1,j,!a[i])*(!j ? 1 : pw[j-1])%ha))%=ha;
        if(a[i]){
            (ans += dfs(i-1,j+1,1)) %= ha;
            (ans += (1ll*dfs(i-1,j,1)*(!j ? 0 : pw[j-1])%ha)) %= ha;
            //  0
        }
    }
    return f[i][j][lim] = ans;
}

int main(){
    CLR(f,-1);
    pw[0] = 1;
    FOR(i,1,MAXN-1) pw[i] = (pw[i-1]<<1)%ha;
    int x;scanf("%d",&x);
    while(x) a[++len] = x&1,x >>= 1;
    printf("%d\n",dfs(len,0,1));
    return 0;
}