/*
 * Author: RainAir
 * Time: 2019-10-07 10:38:42
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

const int MAXN = 5000+5;
const int MAXM = 1e5 + 5;

int n,m,k;

struct Edge{
    int u,v,w,id;
    bool operator < (const Edge &t) const {
        return w == t.w ? u < t.u : w < t.w;
    }
}e[MAXM];

int f[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline void Union(int x,int y){
    int fx = find(x),fy = find(y);
    f[fx] = fy;
}

std::vector<int> ans;

inline int Kruskal(int k){
    ans.clear();
    FOR(i,1,n) f[i] = i;int cnt = 0,du = 0;
    FOR(i,1,m) if(e[i].u == 1 || e[i].v == 1) e[i].w += k;
    std::sort(e+1,e+m+1);
    FOR(i,1,m){
        int u = e[i].u,v = e[i].v,w = e[i].w;
        int fu = find(u),fv = find(v);
        if(fu == fv) continue;
        f[fv] = fu;if(u == 1 || v == 1) du++;
        ans.pb(e[i].id);
        if(++cnt == n-1) break;
    }
    FOR(i,1,m) if(e[i].u == 1 || e[i].v == 1) e[i].w -= k;
    return du;
}

inline int calc(int k){
    ans.clear();
    FOR(i,1,n) f[i] = i;int cnt = 0,du = 0;
    FOR(i,1,m) if(e[i].u == 1 || e[i].v == 1) e[i].w += k;
    std::sort(e+1,e+m+1);
    FOR(i,1,m){
        int u = e[i].u,v = e[i].v,w = e[i].w;
        int fu = find(u),fv = find(v);
        if(fu == fv) continue;
        if(e[i].u == 1 && du == ::k) continue;
        f[fv] = fu;if(u == 1 || v == 1) du++;
        cnt++;
        ans.pb(e[i].id);//tot += e[i].u == 1;
    }
    FOR(i,1,m) if(e[i].u == 1 || e[i].v == 1) e[i].w -= k;
//    DEBUG(cnt);DEBUG(du);
    if(cnt != n-1 || du != ::k){
        puts("-1");exit(0);
    }
    printf("%d\n",n-1);
    for(auto x:ans) printf("%d ",x);
    puts("");exit(0);
    return du;
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,m) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w),e[i].id = i;
    FOR(i,1,m) if(e[i].u > e[i].v) std::swap(e[i].u,e[i].v);
    int l = -1e5,r = 1e5,ans = -1e9;
    while(l <= r){
        int mid = (l + r) >> 1;
        int d = Kruskal(mid);
        if(d < k) r = mid-1;
        else l = mid+1,ans = mid;
    }
    calc(ans);
    return 0;
}