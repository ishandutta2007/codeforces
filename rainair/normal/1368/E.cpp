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

const int MAXN = 5e5 + 5;

struct Edge{
    int to,nxt;
}e[MAXN];
int head[MAXN],cnt;

inline void add(int u,int v){
    e[++cnt] = (Edge){v,head[u]};head[u] = cnt;
}

int n,m;
int du[MAXN],f[MAXN];

inline void Solve(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) head[i] = du[i] = f[i] = 0;cnt = 0;
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);add(u,v);++du[v];
    }
    std::vector<int> ans;
    FOR(v,1,n){
        if(f[v] >= 2){
            ans.pb(v);
            continue;
        }
        for(int i = head[v];i;i = e[i].nxt){
            f[e[i].to] = std::max(f[e[i].to],f[v]+1);
        }
    }
    printf("%d\n",(int)ans.size());
    for(auto x:ans) printf("%d ",x);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}