#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb emplace_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;

int n,a[MAXN];
std::vector<int> G[MAXN];
int deg[MAXN];

inline void Solve(){
    scanf("%d",&n);
    FOR(i,1,n) G[i].clear(),deg[i] = 0;
    FOR(i,1,n) scanf("%d",a+i),G[i].pb(i-a[i]),++deg[i-a[i]];
    std::queue<int> q;
    FOR(i,1,n) if(!deg[i]) q.push(i);
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto x:G[v]){
            if(!--deg[x]) q.push(x);
        }
    }
    std::vector<int> res;FOR(i,1,n) if(deg[i]) res.pb(i);
    printf("%d\n",SZ(res));
    for(auto x:res) printf("%d ",x);puts("");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}