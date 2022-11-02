/*
 * Author: RainAir
 * Time: 2019-08-07 22:03:27
 */
#include <unordered_map>
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

const int MAXN = 2e5 + 5;
int n,col[MAXN],f[MAXN];
std::vector<int> G[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline void merge(int x,int y){
    int fx = find(x),fy = find(y);
    if(fx == fy) return;
    f[fy] = fx;
}

int dis[MAXN];
inline int bfs(int s){
    std::queue<int> q;
    FOR(i,1,n) dis[i] = 0;
    dis[s] = 1;q.push(s);
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto x:G[v]){
            if(dis[x]) continue;
            dis[x] = dis[v] + 1;
            q.push(x);
        }
    }
    int ps = 0,max = 0;
    FOR(i,1,n) if(max < dis[i]) max = dis[i],ps = i;
    return ps;
}

int x[MAXN],y[MAXN];
int ff[MAXN];

int main(){
    scanf("%d",&n);FOR(i,1,n) f[i] = i;
    FOR(i,1,n) scanf("%d",col+i);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        if(col[find(u)] == col[find(v)]) merge(u,v);
        x[i] = u;y[i] = v;
    }
    FOR(i,1,n) f[i] = find(f[i]);
    FOR(i,1,n-1) if(col[f[x[i]]] != col[f[y[i]]]) G[f[x[i]]].pb(f[y[i]]),G[f[y[i]]].pb(f[x[i]]);

    printf("%d\n",dis[bfs(bfs(f[1]))]/2);
    return 0;
}