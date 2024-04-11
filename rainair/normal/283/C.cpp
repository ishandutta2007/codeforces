/*
 * Author: RainAir
 * Time: 2019-07-12 10:46:26
 */
#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <assert.h>
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
const int MAXN = 1000 + 5;
const int MAXM = 2e5 + 5;
const int ha = 1e9 + 7;
std::vector<int> G[MAXN],wp;
int f[MAXM<<2],n,q,t,a[MAXN],b[MAXN],vis[MAXN],du[MAXN];

inline void topsort(){
    std::queue<int> q;int cnt = 0;
    FOR(i,1,n) if(!du[i]) q.push(i);
    while(!q.empty()){
        int v = q.front();q.pop();
        ++cnt;if(vis[v] > 0) t -= a[v]-b[v];
        if(a[v] <= t) wp.pb(a[v]);
        for(auto x:G[v]){
            a[x] += a[v];
            if(!--du[x]) q.push(x);
        }
    }
    f[0] = 1;
    for(auto x:wp){
       // assert(x >= 0);
        FOR(j,x,t){
            (f[j] += f[j-x]) %= ha;
        }
    }
    if(cnt == n && t >= 0) printf("%d\n",f[t]);
    else puts("0");
}

signed main(){
    scanf("%lld%lld%lld",&n,&q,&t);
    FOR(i,1,n) scanf("%d",a+i),b[i] = a[i];
    FOR(i,1,q){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);du[v]++;vis[v]++;vis[u]++;
    }
    topsort();
    return 0;
}