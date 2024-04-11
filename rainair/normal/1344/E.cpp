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
#define db double
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

const int MAXN = 1e5 + 5;

int n,m;

struct Edge{
    int to,w,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w){
    e[++cnt] = (Edge){v,w,head[u]};head[u] = cnt;
}

LL dis[MAXN];

inline void dfs(int v){
    for(int i = head[v];i;i = e[i].nxt){
        dis[e[i].to] = dis[v] + e[i].w;
        dfs(e[i].to);
    }
}

int ch[MAXN][2],fa[MAXN];LL tag[MAXN],ts[MAXN];

inline bool nroot(int x){
    return ch[fa[x]][0] == x || ch[fa[x]][1] == x;
}

inline void rotate(int x){
    int y = fa[x],z = fa[y],k = ch[y][1]==x,w = ch[x][!k];
    if(nroot(y)) ch[z][ch[z][1]==y] = x;fa[x] = z;
    ch[x][!k] = y;fa[y] = x;
    ch[y][k] = w;if(w) fa[w] = y;
}

inline void pushdown(int x){
    if(tag[x] != -1){
        if(ch[x][0]) tag[ch[x][0]] = ts[ch[x][0]] = tag[x];
        if(ch[x][1]) tag[ch[x][1]] = ts[ch[x][1]] = tag[x];
        tag[x] = -1;
    }
}

int st[MAXN];

inline void splay(int x){
    int y = x,z;st[z = 1] = y;
    while(nroot(y)) st[++z] = y = fa[y];
    while(z) pushdown(st[z--]);
    while(nroot(x)){
        y = fa[x],z = fa[y];
        if(nroot(y)) rotate((ch[z][1]==y)^(ch[y][1]==x) ? x : y);
        rotate(x);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,2,n){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        add(u,v,w);ch[u][1] = v;fa[v] = u;
    }
    dfs(1);
    FOR(i,1,n) tag[i] = -1,ts[i] = -dis[i];
    std::vector<P> S;
    while(m--){
        int s,t;scanf("%d%d",&s,&t);
        splay(s);//  ch[s][1] = 0, access 
        for(int x=fa[s],y=s;x;y=x,x=fa[x]){
            splay(x);ch[x][1] = y;
            S.pb(MP(ts[x]+dis[x]+1,t+dis[x]));
        }
        splay(s);
        if(ch[s][0]) tag[ch[s][0]] = ts[ch[s][0]] = t;
    }
    std::sort(all(S));
    LL now = 0;int cnt = 0;
    std::priority_queue<LL,std::vector<LL>,std::greater<LL> > q;
    FOR(i,0,(int)S.size()-1){
        while(!q.empty() && now < S[i].fi){
            LL r = q.top();q.pop();
            if(now > r){
                FOR(j,0,i-1) cnt -= (S[j].se >= r);
                while(!q.empty()) cnt += (q.top() >= r),q.pop();
                printf("%lld %d\n",r,cnt+1);
                return 0;
            }
            now++;++cnt;
        }
        if(now < S[i].fi) now = S[i].fi;
        q.push(S[i].se);
    }
    while(!q.empty()){
        LL r = q.top();q.pop();
        if(now > r){
            for(auto x:S) cnt -= (x.se >= r);
            while(!q.empty()) cnt += (q.top() >= r),q.pop();
            printf("%lld %d\n",r,cnt+1);
            return 0;
        }
        ++now;++cnt;
    }
    printf("-1 %d\n",cnt);
    return 0;
}