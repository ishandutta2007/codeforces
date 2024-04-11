/*
 * Author: RainAir
 * Time: 2019-10-09 15:00:30
 */
#include <algorithm>
#include <iostream>
#include <assert.h>
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

const int MAXN = 1e5 + 5;
std::vector<P> edge[MAXN];
std::map<P,int> mp;
int n,m,q,blo;
P query[MAXN];
int cnt[MAXN],ans[MAXN];
std::vector<int> S[MAXN];
int p[MAXN];

inline bool cmp(int x,int y){
    return S[x].size() < S[y].size();
}

int f[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline void Solve1(int xx){
    std::vector<int> opt;
    for(auto x:edge[xx]){
        int fx = find(x.fi),fy = find(x.se);
        f[fy] = fx;opt.pb(x.fi);opt.pb(x.se); //  Wrong Answer
    }
    std::sort(all(opt));
    opt.erase(std::unique(all(opt)),opt.end());
    int sz = opt.size();
    FOR(i,0,sz-1){
        int fx = find(opt[i]);
        FOR(j,i+1,sz-1){
            int fy = find(opt[j]);
            if(fx == fy) cnt[mp[MP(opt[i],opt[j])]]++;//,DEBUG(opt[i]),DEBUG(opt[j]);
        }
    }
    for(auto x:opt) f[x] = x;
}

inline void Solve2(int xx){
    FOR(i,1,n) f[i] = i;
    for(auto x:edge[xx]){
        int fx = find(x.fi),fy = find(x.se);
        f[fy] = fx;
    }
    FOR(i,1,q){
        int fx = find(query[i].fi),fy = find(query[i].se);
        ans[i] += fx == fy;
    }
}

int main(){
//    freopen("a.in","r",stdin);
//    freopen("a.out","w",stdout);
    scanf("%d%d",&n,&m);
    blo = std::sqrt(1.0*n);int mx = 0;
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        if(u > v) std::swap(u,v);
        edge[w].pb(MP(u,v));mx = std::max(mx,w);
        S[w].pb(u);S[w].pb(v);
    }
    FOR(i,1,mx) std::sort(all(S[i])),S[i].erase(std::unique(all(S[i])),S[i].end());
    scanf("%d",&q);
    FOR(i,1,q){
        scanf("%d%d",&query[i].fi,&query[i].se);
        if(query[i].fi > query[i].se) std::swap(query[i].fi,query[i].se);
        mp[MP(query[i].fi,query[i].se)] = i;
    }
    FOR(i,1,mx) p[i] = i;std::sort(p+1,p+mx+1,cmp);
    FOR(i,1,n) f[i] = i;
    int ps = mx;
    FOR(i,1,mx) if(S[p[i]].size() > blo) {ps = i;break;}
    FOR(i,1,n) assert(f[i] == i);
 //   FOR(i,1,n) f[i] = i;
    FOR(i,1,ps-1) Solve1(p[i]);
    FOR(i,ps,mx) Solve2(p[i]);
    FOR(i,1,q) ans[i] += cnt[mp[MP(query[i].fi,query[i].se)]];
    FOR(i,1,q) printf("%d\n",ans[i]);
    return 0;
}