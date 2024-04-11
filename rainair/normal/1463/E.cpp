#include <bits/stdc++.h>

#define fi first
#define se second
#define DB double
#define U unsigned
#define P std::pair
#define LL long long
#define LD long double
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 3e5 + 5;
int n,k;
std::vector<int> G[MAXN];
int p[MAXN],deg[MAXN];
int tot = 0,bel[MAXN],pos[MAXN];
std::vector<int> chain[MAXN];
int to[MAXN],ans[MAXN];

int main(){
    scanf("%d%d",&n,&k);
    FOR(i,1,n) scanf("%d",p+i);
    FOR(i,1,k){
        int x,y;scanf("%d%d",&x,&y);
        to[x] = y;++deg[y];
    }
    FOR(i,1,n){
        if(!deg[i]){
            int t = 1;
            ++tot;bel[i] = tot;chain[tot].pb(i);
            if(!to[i]) continue;
            int v = to[i];pos[i] = t;
            while(v){
                bel[v] = tot;chain[tot].pb(v);
                pos[v] = ++t;
                v = to[v];
            }
        }
    }
    FOR(i,1,n) if(!bel[i]){puts("0");return 0;}
    CLR(deg,0);
    FOR(i,1,n){
        if(p[i]){
            if(bel[i] == bel[p[i]] && pos[p[i]] > pos[i]){
                puts("0");
                return 0;
            }
            if(bel[i] != bel[p[i]]) G[bel[p[i]]].pb(bel[i]),++deg[bel[i]];
        }
    }
    std::queue<int> q;
    FOR(i,1,tot) if(!deg[i]) q.push(i);
    int id = 0;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto x:chain[v]) ans[++id] = x;
        for(auto x:G[v]){
            if(!--deg[x]){
                q.push(x);
            }
        }
    }
    if(id != n){
        puts("0");
        return 0;
    }
    FOR(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}