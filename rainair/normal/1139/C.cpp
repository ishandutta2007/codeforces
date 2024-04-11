/*
 * Author: RainAir
 * Time: 2019-10-09 16:35:47
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

const int MAXN = 1e5 + 5;
int sz[MAXN],f[MAXN],n,k;

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline void Union(int x,int y){
    int fx = find(x),fy = find(y);
    if(fx == fy) return;
    if(sz[fx] < sz[fy]) std::swap(fx,fy);
    f[fy] = fx;sz[fx] += sz[fy];
}
bool vis[MAXN];

const int ha = 1e9 + 7;

inline int qpow(int a,int n){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) f[i] = i,sz[i] = 1;
    FOR(i,1,n-1){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        if(!w) Union(u,v);
    }
    int ans = 0;
    FOR(i,1,n){
        if(vis[find(i)]) continue;
        vis[find(i)] = true;
        (ans += qpow(sz[find(i)],k)) %= ha;
    }
    printf("%d\n",(qpow(n,k)-ans+ha)%ha);
    return 0;
}