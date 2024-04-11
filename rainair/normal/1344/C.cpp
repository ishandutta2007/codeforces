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

const int MAXN = 2e5 + 5;

int n,m;
std::vector<int> G[MAXN];
int u[MAXN],v[MAXN],f[MAXN],deg[MAXN],g[MAXN];

inline void gao(){
    std::queue<int> q;
    FOR(i,1,n) g[i] = i;
    FOR(i,1,n) if(!deg[i]) q.push(i);
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto x:G[v]){
            g[x] = std::min(g[x],g[v]);
            if(!--deg[x]) q.push(x);
        }
    }
    bool flag = 1;
    FOR(i,1,n) flag &= deg[i]==0;
    if(!flag){puts("-1");exit(0);}
    FOR(i,1,n) f[i] = std::min(f[i],g[i]);
}

int main(){
    scanf("%d%d",&n,&m);FOR(i,1,n) f[i] = i;
    FOR(i,1,m) scanf("%d%d",u+i,v+i),G[u[i]].pb(v[i]),deg[v[i]]++;
    gao();
    FOR(i,1,n) G[i].clear(),deg[i] = 0;FOR(i,1,m) G[v[i]].pb(u[i]),deg[u[i]]++;
    gao();
    int res = 0;
    FOR(i,1,n) res += (f[i]==i);
    printf("%d\n",res);
    FOR(i,1,n) putchar(f[i]==i?'A':'E');
    puts("");
    return 0;
}