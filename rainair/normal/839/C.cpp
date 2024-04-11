/*
 * Author: RainAir
 * Time: 2019-08-24 16:29:45
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

std::vector<int> G[MAXN];
int n,du[MAXN];
double ans;

inline void dfs(int v,int fa=-1,int d=0,double p=1.0){
    if(du[v] == 1 && v != 1) ans += p*d;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v,d+1,1.0*p/(v==1 ? du[v] : (du[v]-1)));
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
        du[u]++;du[v]++;
    }
    dfs(1);
    printf("%.10f\n",ans);
    return 0;
}