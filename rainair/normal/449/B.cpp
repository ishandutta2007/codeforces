/*
 * Author: RainAir
 * Time: 2019-10-04 20:02:30
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
#define P std::pair<LL,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
const int MAXN = 1e5 + 5;


inline char nc(){
    #define SIZE 300000+3
    static char buf[SIZE],*p1 = buf+SIZE,*p2 = buf+SIZE;
    if(p1 == p2){
        p1 = buf;p2 = buf+fread(buf,1,SIZE,stdin);
        if(p1 == p2) return -1;
    }
    return *p1++;
}

inline void read(int &x){
    char ch = nc();x = 0;int flag = 0;
    while(!isdigit(ch)){
        if(ch == '-') flag = 1;
        ch = nc();
    }
    while(isdigit(ch)){
        x = (x<<1) + (x<<3) + (ch^'0');
        ch = nc();
    }
    if(flag) x = -x;
}

struct Edge{
    int to,w,nxt;
}e[MAXN<<3];

int head[MAXN],ts[MAXN],cnt;
LL dis[MAXN];
bool used[MAXN];
int n,m,k;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,w,head[v]};head[v] = cnt;
}

inline void dij(){
    std::fill(dis,dis+n+1,1e18);
    std::priority_queue<P,std::vector<P>,std::greater<P> > q;
    q.push(MP(dis[1] = 0,1));ts[1] = 1;
    while(!q.empty()){
        int v = q.top().se;q.pop();
        if(used[v]) continue;
        used[v] = true;
        for(int i = head[v];i;i = e[i].nxt){
            if(dis[e[i].to] > dis[v] + e[i].w){
                dis[e[i].to] = dis[v] + e[i].w;
                ts[e[i].to] = ts[v];
                q.push(MP(dis[e[i].to],e[i].to));
            }
            else if(dis[e[i].to] == dis[v] + e[i].w) ts[e[i].to] += ts[v];
        }
    }
}

LL g[MAXN];

signed main(){
    read(n);read(m);read(k);
    FOR(i,1,m){
        int u,v,w;read(u);read(v);read(w);
        add(u,v,w);
    }
    int ans = k;
    FOR(i,1,n) g[i] = 1e18+1;
    FOR(i,1,k){
        int u,w;read(u);read(w);
        g[u] = std::min(g[u],(LL)w);
    }
    FOR(i,2,n) if(g[i] != 1e18+1) add(1,i,g[i]);
    dij();
    FOR(i,2,n){
        int s = i,y = g[i];
    //    if(i == 5) DEBUG(dis[s]);
        if(g[s] != 1e18+1 && ts[s] == 1 && dis[s] == y) ans--;
    }
    printf("%d\n",ans);
    return 0;
}