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
int n,m,a[MAXN];
int f[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

std::vector<int> G[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i),f[i] = i;
    FOR(i,1,m){
        int u,v;scanf("%d%d",&u,&v);
        u = find(u);v = find(v);f[u] = v;
    }
    FOR(i,1,n) G[find(i)].pb(i);
    FOR(i,1,n) if(i == find(i)){
        std::vector<int> vec;
        for(auto x:G[i]) vec.pb(a[x]);
        std::sort(all(vec));std::reverse(all(vec));
        std::sort(all(G[i]));
        FOR(j,0,SZ(vec)-1) a[G[i][j]] = vec[j];
    }
    FOR(i,1,n) printf("%d%c",a[i]," \n"[i==n]);
    return 0;
}