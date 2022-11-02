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

const int MAXN = 2e5 + 5;
std::vector<int> G[MAXN];
int n,B;
int dep[MAXN],f[2][MAXN];

inline void bfs(int tp,int vv){
    std::queue<int> q;q.push(vv);
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto x:G[v]){
            if(x == vv || f[tp][x]) continue;
            f[tp][x] = f[tp][v] + 1;
            q.push(x);
        }
    }
}

int main(){
    scanf("%d%d",&n,&B);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    bfs(0,1);bfs(1,B);
    int ans = 0;
    FOR(i,1,n){
        if(G[i].size() == 1 && f[0][i] > f[1][i]) ans = std::max(ans,f[0][i]*2);
    }
    printf("%d\n",ans);
    return 0;
}