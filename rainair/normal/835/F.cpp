/*
 * Author: RainAir
 * Time: 2019-08-30 19:33:54
 */
#include <unordered_map>
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
#define P std::pair<LL,LL>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 2e5 + 5;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];

int head[MAXN],n,m,cnt,du[MAXN];
std::unordered_map<LL,int> S;

inline void add(int u,int v,int w){
    if(u > v) std::swap(u,v);
    if(!S[1ll*u*n+v]) S[1ll*u*n+v] = w;
    else S[1ll*u*n+v] = std::min(S[1ll*u*n+v],w);
    du[u]++;du[v]++;
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

inline int calc(int u,int v){
    if(u > v) std::swap(u,v);
    return S[u*n+v];
}

bool circled[MAXN];
std::vector<int> circle;

inline void topsort(){
    std::queue<int> q;
    FOR(i,1,n) if(!du[i]) q.push(i);
    while(!q.empty()){
        int v = q.front();q.pop();circled[v] = false;
        for(int i = head[v];i;i = e[i].nxt){
            if(!--du[e[i].to]) q.push(e[i].to);
        }
    }
    FOR(i,1,n) if(circled[i]) m++;
}

int f[MAXN][2],ans = LLONG_MAX,len = 0;
int dis[MAXN],val[MAXN];

inline void dp(int v,int fa=0){
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa || circled[e[i].to]) continue;
        dp(e[i].to,v);int gx = f[e[i].to][0]+e[i].w;
        if(gx > f[v][0])
            f[v][1] = f[v][0],
            f[v][0] = gx;
        else if(gx > f[v][1]) f[v][1] = gx;
    }
    len = std::max(len,f[v][1]+f[v][0]);
}

int sm = 0;
std::set<P> s1,s2;
// s1:val-dis s2: val+dis

inline void Solve(){
    if(m == 2){ // force
        ans = val[1]+val[2]+calc(circle[0],circle[1]);
        return;
    }
    FOR(i,1,m) s1.insert(MP(val[i]-dis[i],i)),s2.insert(MP(val[i]+dis[i],i));
    FOR(i,1,m){
        auto x = --s1.end(),y = --s2.end();
        if(x->se == y->se){
            int gx1 = (--x)->fi+y->fi;++x;
            int gx2 = x->fi+(--y)->fi;++y;
            ans = std::min(ans,std::max(gx1,gx2)); // FIX
        }
        else ans = std::min(ans,x->fi+y->fi);
        s1.erase(MP(val[i]-dis[i],i));
        s2.erase(MP(val[i]+dis[i],i));
        s1.insert(MP(val[i]-dis[i]-sm,i));
        s2.insert(MP(val[i]+dis[i]+sm,i));
    }
}

bool vis[MAXN];

inline void getcircle(){
    if(m == 2){ // force
        FOR(i,1,n) if(circled[i]) circle.pb(i);
        return;
    }
    FOR(i,1,n) if(!circled[i]) vis[i] = true; // bord
    int v,t;
    ROF(i,n,1) if(circled[i]) v = i;
    t = v;//vis[v] = true;
    int pre = -1;
    do{
        circle.pb(t);
        for(int i = head[t];i;i = e[i].nxt){
            if(e[i].to == pre) continue;
            if(!vis[e[i].to]){
                vis[e[i].to] = true;
                pre = t;
                t = e[i].to;
                break;
            }
        }
    }while(t != v);
}

signed main(){
 //   freopen("a.in","r",stdin);
    scanf("%lld",&n);
    std::fill(circled+1,circled+n+1,true);
    std::fill(du+1,du+n+1,-1);
    FOR(i,1,n){
        int u,v,w;scanf("%lld%lld%lld",&u,&v,&w);
        add(u,v,w);
    }
    topsort();getcircle();
    assert(m == (int)circle.size());
    FOR(i,0,m-1){
        dp(circle[i]);val[i+1] = f[circle[i]][0];
        if(i > 0) dis[i+1] = calc(circle[i-1],circle[i]),sm += dis[i+1];
    }
    //dis[m] = calc(circle[0],circle[m-1]);
    sm += calc(circle[0],circle[m-1]);
    FOR(i,1,m) dis[i] += dis[i-1];
    Solve();
    printf("%lld\n",std::max(len,ans));
    return 0;
}