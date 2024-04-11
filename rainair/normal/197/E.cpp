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

const int MAXN = 2000+5;
const double EPS = 1e-6;

inline int sgn(double x){
    return std::fabs(x) < EPS ? 0 : (x > 0 ? 1 : -1);
}

struct pt{
    double x,y;
    int num,pos;
    pt(){}
    pt(double x,double y) : x(x),y(y) {
        num = 0;
    }

    inline pt operator - (const pt &t) const {
        return pt(x-t.x,y-t.y);
    }

    inline double operator * (const pt &t) const {
        return x*t.y-y*t.x;
    }

    inline bool operator < (const pt &t) const {
        return !sgn(x-t.x) ? y < t.y : x < t.x;
    }

    inline bool operator == (const pt &t) const {
        return !sgn(x-t.x) && !sgn(y-t.y);
    }

    inline double len(){
        return std::sqrt(x*x+y*y);
    }

    inline void print(){
        printf("%f %f\n",x,y);
    }
}p[MAXN],PP;
std::vector<pt> v;

inline bool cmp(const pt &a,const pt &b){
    return !sgn((a-PP)*(b-PP)) ? ((a-PP).len() < (b-PP).len()) : (a-PP)*(b-PP) > 0;
}

int n;
std::vector<int> G[MAXN];
int ans[MAXN],sz[MAXN];

inline void dfs(int v,int fa=0){
    sz[v] = 1;
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs(x,v);sz[v] += sz[x];
    }
}

inline void solve(int v,int fa,int l,int r){
    std::sort(p+l,p+r+1);
    PP = p[l];std::sort(p+l+1,p+r+1,cmp);
    ans[p[l].pos] = v;int t = l+1;
    for(auto x:G[v]){
        if(x == fa) continue;
        solve(x,v,t,t+sz[x]-1);
        t += sz[x];
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    FOR(i,1,n){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[i].pos = i;
    }
    dfs(1,0);
    solve(1,0,1,n);
    FOR(i,1,n) printf("%d ",ans[i]);
    return 0;
}