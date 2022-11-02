/*
 * Author: RainAir
 * Time: 2019-08-19 18:29:22
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

const int MAXN = 1e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];

int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int dep[MAXN];

inline void dfs(int v,int fa=0){
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dep[e[i].to] = dep[v] + 1;dfs(e[i].to,v);
    }
}

int main(){
    int n;scanf("%d",&n);FOR(i,1,n-1) {int u,v;scanf("%d%d",&u,&v);add(u,v);}dfs(1);
    double ans = 0;
    FOR(i,1,n) ans += 1.0/(dep[i]+1);
    printf("%.20lf\n",ans);
    return 0;
}