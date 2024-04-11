/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-21 17:49:52
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

const int MAXN = 1500+5;
const double EPS = 1e-8;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int n,head[MAXN],x0,y00,cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

inline int sgn(double x){
    if(std::abs(x) <= EPS) return 0;
    return x > 0 ? 1 : -1;
}

struct Point{
    double x,y;int id;
    Point(int x=0,int y=0) : x(x),y(y) {}

    Point operator - (const Point &t) const {
        return Point(x-t.x,y-t.y);
    }

    double operator * (const Point &t) const {
        return x*t.y-y*t.x;
    }

    inline bool operator < (const Point &t) const {
        return !sgn(x-t.x) ? sgn(y-t.y)<0 : sgn(x-t.x)<0;
    }

    inline bool operator == (const Point &t) const {
        return !sgn(x-t.x) && !sgn(y-t.y);
    }

    inline double len(){
        return std::sqrt(x*x+y*y);
    }
}p[MAXN],p0;

inline bool cmp(const Point &a,const Point &b){
    return !sgn((a-p0)*(b-p0)) ? sgn((a-p0).len()-(b-p0).len()) < 0 : sgn((a-p0)*(b-p0)) < 0;
}

int ans[MAXN],sz[MAXN];

inline void dfs1(int v,int fa=0){
    sz[v] = 1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs1(e[i].to,v);sz[v] += sz[e[i].to];
    }
}

inline void dfs(int v,int fa,int l,int r){
    int ps = l;
    FOR(i,l+1,r){
        if(p[i] < p[ps]) ps = i;
    }
    std::swap(p[l],p[ps]);p0 = p[l];
    ans[p[l].id] = v;
    std::sort(p+l+1,p+r+1,cmp);
    int now = l+1;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v,now,now+sz[e[i].to]-1);
        now = now+sz[e[i].to];
    }
}

signed main(){
//    freopen("test.in","r",stdin);
//    freopen("test.out","w",stdout);
    scanf("%d",&n);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);
    }
    FOR(i,1,n){
        scanf("%lf%lf",&p[i].x,&p[i].y);
        p[i].id = i;
    }
    dfs1(1);
    dfs(1,0,1,n);
    FOR(i,1,n) printf("%d ",ans[i]);puts("");
    return 0;
}