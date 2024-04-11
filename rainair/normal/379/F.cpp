/*
 * Author: RainAir
 * Time: 2019-08-09 22:16:54
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

const int MAXN = 2e6 + 5;
int f[21][MAXN],dep[MAXN],mx,pos,cnt = 1;

inline void add(int fa){
    int v = ++cnt;f[0][v] = fa;
    FOR(i,1,20) f[i][v] = f[i-1][f[i-1][v]];
    dep[v] = dep[fa] + 1;
}

inline int lca(int x,int y){
    if(dep[x] != dep[y]){
        if(dep[x] < dep[y]) std::swap(x,y);
        int d = dep[x] - dep[y];
        FOR(i,0,20) if((1<<i)&d) x = f[i][x];
    }
    if(x == y) return x;
    ROF(i,20,0){
        if(f[i][x] == f[i][y]) continue;
        x = f[i][x],y = f[i][y];
    }
    return f[0][x];
}

inline int calc(int x,int y){
    int l = lca(x,y);
    return dep[x]+dep[y]-2*dep[l];
}

int main(){
    int n;scanf("%d",&n);
    FOR(i,1,3) add(1);mx = 1;pos = 2;int ans = 2;
    FOR(i,1,n){
        int x;scanf("%d",&x);
        add(x);add(x);
        if(dep[x] == mx){
            mx++;pos = cnt;ans++;
        }
        else{
            ans = std::max(ans,calc(cnt,pos));
        }
        printf("%d\n",ans);
    }
    return 0;
}