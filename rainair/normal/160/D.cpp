#include <unordered_map>
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

int f[MAXN];

struct Edge{
    int u,v,w,ans,pos;

    inline bool operator == (const Edge &t) const {
        return w == t.w;
    }
    
    inline bool operator < (const Edge &t) const {
        return w < t.w;
    }
}p[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

int n,m;

struct E{
    int to,w,next,num;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v,int w,int t){
    e[++cnt] = (E){v,w,head[u],t};head[u] = cnt;
}

int tot;
std::unordered_map<int,int> S;

inline int get(int x){
    if(!S[x]) return S[x] = ++tot;
    return S[x];
}

int dfn[MAXN],low[MAXN],ts;

inline void dfs(int v,int efa=0){
    int fan = 0;
    dfn[v] = low[v] = ++ts;//DEBUG(v);
    int t = 0;
    for(int i = head[v];i;i = e[i].next){
        if((i+1)/2 == efa){
            fan = e[i].num;
            continue;
        }
        if(dfn[e[i].to]) 
            low[v] = std::min(low[v],dfn[e[i].to]);
        else dfs(e[i].to,(i+1)/2),low[v] = std::min(low[v],low[e[i].to]);
    }
   // DEBUG(dfn[v]);DEBUG(low[v]);DEBUG(p[fan].pos);
    if(dfn[v] == low[v]) p[fan].ans = 3;
}

inline bool cmp(const Edge &a,const Edge &b){
    return a.pos < b.pos;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m) scanf("%d%d%d",&p[i].u,&p[i].v,&p[i].w),p[i].pos = i;
    std::sort(p+1,p+m+1);
    FOR(i,1,n) f[i] = i;
    FOR(i,1,m){
        int l = i,r = i;//DEBUG(i);
        while(p[r+1] == p[r]) r++;
        FOR(j,l,r){
            int u = p[j].u,v = p[j].v,w = p[j].w;
            int fu = find(u),fv = find(v);
            if(fu == fv){
                p[j].ans = 1; // none
                continue;
            }
            u = get(fu),v = get(fv);
            add(u,v,w,j);add(v,u,w,j);
 //           printf("%d %d %d\n",u,v,w);
        }
        ts = 0;
        FOR(j,1,tot) if(!dfn[j]) dfs(j);
        FOR(j,l,r) if(!p[j].ans) p[j].ans = 2; // some
        FOR(j,l,r){
            int u = p[j].u,v = p[j].v;
            int fu = find(u),fv = find(v);
            if(fu != fv) f[fv] = fu;
        }
        FOR(i,1,tot) dfn[i] = low[i] = head[i] = 0;
        cnt = tot = 0;S.clear();
        i = r;
    }
    std::sort(p+1,p+m+1,cmp);//DEBUG(p[5].ans);DEBUG(p[5].pos);
    FOR(i,1,m) puts(p[i].ans == 1 ? "none" : (p[i].ans == 2 ? "at least one" : "any"));
    return 0;
}