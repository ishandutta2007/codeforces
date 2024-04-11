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

const int MAXN = 1e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN<<1];
int head[MAXN],cnt;
std::vector<P> ans;
int mx=0;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
    e[++cnt] = (Edge){u,head[v]};head[v] = cnt;
}
int du[MAXN];
inline void dfs(int v,int ts=0,int fa=0){
    int now = ts;
    ans.pb(MP(v,ts));
    for(int i = head[v];i;i = e[i].nxt){
        if(e[i].to == fa) continue;
        if(now == mx) now -= du[v],ans.pb(MP(v,now));
        now++;
        dfs(e[i].to,now,v);
    }
    if(fa){
        if(now != ts-1) ans.pb(MP(v,ts-1));
        ans.pb(MP(fa,ts));
    }
}

int n;

int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        add(u,v);++du[u];++du[v];
    }
    FOR(i,1,n) mx = std::max(mx,du[i]);
    dfs(1);
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d %d\n",x.fi,x.se);
    return 0;
}