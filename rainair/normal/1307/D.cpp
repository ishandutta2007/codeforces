/*
 * Author: RainAir
 * Time: 2020-03-02 08:52:42
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
struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int dis[2][MAXN];
int n;

inline void bfs(int S,int dis[]){
    std::queue<int> q;q.push(S);dis[S] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(int i = head[v];i;i = e[i].nxt){
            if(!dis[e[i].to]){
                dis[e[i].to] = dis[v] + 1;
                q.push(e[i].to);
            }
        }
    }
    FOR(i,1,n) dis[i]--;
}

int m,k;
int a[MAXN];
std::vector<P> S,rS;

inline bool cmp(int x,int y){
    return dis[0][x] > dis[0][y];
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,k) scanf("%d",a+i);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);add(u,v);
    }
    bfs(1,dis[0]);bfs(n,dis[1]);
    std::sort(a+1,a+k+1,cmp);
    int mx = -1e9,ans = 0;
    FOR(i,1,k){
        ans = std::max(ans,dis[0][a[i]]+mx+1);
        mx = std::max(mx,dis[1][a[i]]);
    }
    ans = std::min(ans,dis[0][n]);
    printf("%d\n",ans);
    return 0;
}

// max dis[x]+rdis[y]+1