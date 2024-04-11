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

const int MAXN = 1000 + 5;
int a[MAXN],n;
std::vector<P<int,int> > G[MAXN];
bool vis[MAXN];

std::vector<int> tmp;

inline void dfs(int v){
    if(v != 1){
        printf("%d",tmp[0]);
        FOR(i,1,SZ(tmp)-1) printf(".%d",tmp[i]);
        puts("");
    }
    for(auto x:G[v]){
        tmp.pb(x.se);
        dfs(x.fi);
        tmp.pop_back();
    }
}

int main(){
    int T;scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        FOR(i,1,n) scanf("%d",a+i);
        int tot = 1;
        FOR(i,1,n){
            std::vector<int> vec;
            ROF(j,tot,1){
                if(vis[j]) continue;
                if(SZ(G[j])+1 == a[i]){
                    ++tot;G[j].pb(tot,a[i]);
                    for(auto x:vec) vis[x] = 1;
                    break;
                }
                vec.pb(j);
            }
        }
        dfs(1);
        FOR(i,1,tot) vis[i] = 0,G[i].clear();
    }
    return 0;
}