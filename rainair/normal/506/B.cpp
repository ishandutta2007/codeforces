#include <bits/stdc++.h>

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

std::vector<int> G[MAXN],GG[MAXN];
int n,m;
bool vis[MAXN];
std::vector<int> S;

inline void dfs(int v){
    vis[v] = 1;S.pb(v);
    for(auto x:GG[v]){
        if(vis[x]) continue;
        dfs(x);
    }
    for(auto x:G[v]){
        if(vis[x]) continue;
        dfs(x);
    }
}

int deg[MAXN];

inline int work(){
    if(S.size() == 1) return 0;
    std::queue<int> q;for(auto x:S) if(!deg[x]) q.push(x);
    int c = 0;
    while(!q.empty()){
        int v = q.front();q.pop();++c;
        for(auto x:G[v]){
            if(!--deg[x]) q.push(x);
        }
    }
    int ans = S.size();
    if(c == S.size()){
        ans = (int)S.size()-1;
    }
    return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);GG[v].pb(u);++deg[v];
    }
    int ans = 0;
    FOR(i,1,n) if(!vis[i]){
        S.clear();dfs(i);ans += work();
    }
    printf("%d\n",ans);
    return 0;
}