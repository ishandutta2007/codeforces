/*
 * Author: RainAir
 * Time: 2019-10-08 08:53:11
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
#define int LL
const int MAXN = 1e5 + 5;

int n,m,G,S;

struct Edge{
    int u,v,g,s;
    bool operator < (const Edge &t) const {
        return g < t.g;
    }
}e[MAXN];

int f[MAXN];
std::vector<Edge> edge,t;
int mxg,mxs;

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline int Kruskal(){
    std::sort(all(edge),[](const Edge &x,const Edge &y)->bool{
              return x.s < y.s;
              });
    int cnt = 0;mxs = 0;
    FOR(i,1,n) f[i] = i;t.clear();
    for(auto x:edge){
        int u = x.u,v = x.v;
        int fu = find(u),fv = find(v);
        if(fu == fv) continue;
        f[fv] = fu;mxs = std::max(mxs,x.s);
        t.pb(x);
        if(++cnt == n-1) break;
    }
    edge.clear();edge = t;
    return cnt == n-1 ? mxs*S+mxg*G : LLONG_MAX;
}

signed main(){
    scanf("%lld%lld%lld%lld",&n,&m,&G,&S);
    FOR(i,1,m) scanf("%lld%lld%lld%lld",&e[i].u,&e[i].v,&e[i].g,&e[i].s);
    std::sort(e+1,e+m+1);int ans = LLONG_MAX;
    FOR(i,1,m){
        mxg = e[i].g;
        edge.pb(e[i]);
        ans = std::min(ans,Kruskal());
    }
    printf("%lld\n",ans==LLONG_MAX ? -1 : ans);
    return 0;
}