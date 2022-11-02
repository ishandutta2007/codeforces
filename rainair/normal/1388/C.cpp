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
#define P std::pair<int,int>
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
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}

int n,m;
int p[MAXN],h[MAXN],a[MAXN],b[MAXN];
int sp[MAXN];
bool ans;

inline void dfs1(int v,int fa=0){
    sp[v] = p[v];
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to ==fa) continue;
        dfs1(e[i].to,v);
        sp[v] += sp[e[i].to];
    }
}

inline void dfs(int v,int fa=0){
    if(!ans) return;
    if(sp[v]+h[v] < 0){ans= 0 ;return;}
    if((sp[v]+h[v])%2){ans = 0;return;}
    a[v] = (sp[v]+h[v])/2;
    b[v] = sp[v]-a[v];
    if(b[v] < 0){ans = 0;return;}
    int sa=0,sb=0;
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        dfs(e[i].to,v);
        if(!ans) return;
        sa += a[e[i].to];sb += b[e[i].to];
    }
    if(sa > a[v]){ans=0;return;}
}

inline void Solve(){
    scanf("%lld%lld",&n,&m);
    FOR(i,1,n) head[i] = 0;cnt = 0;
    FOR(i,1,n) scanf("%lld",p+i);
    FOR(i,1,n) scanf("%lld",h+i);
    FOR(i,2,n){
        int u,v;scanf("%lld%lld",&u,&v);
        add(u,v);
    }ans = 1;
    dfs1(1);
    dfs(1);
    puts(ans?"YES":"NO");
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--) Solve();
    return 0;
}