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

const int MAXN = 600+5;
LL d[MAXN][MAXN],mp[MAXN][MAXN];
int n,m,k;

struct Node{
    int u,v;LL w;
}q[MAXN*MAXN];
LL lim[MAXN];
bool ok[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,n) d[i][j] = (i!=j)*1e18;
    FOR(i,1,m){
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        d[u][v] = d[v][u] = mp[u][v] = mp[v][u] = w;
    }
    FOR(k,1,n) FOR(i,1,n) FOR(j,1,n) d[i][j] = std::min(d[i][j],d[i][k]+d[k][j]);
    scanf("%d",&k);
    FOR(i,1,k) scanf("%d%d%lld",&q[i].u,&q[i].v,&q[i].w);
    FOR(i,k+1,2*k) q[i] = q[i-k],std::swap(q[i].u,q[i].v);
    k <<= 1;int ans = 0;
    FOR(a,1,n){
        FOR(i,1,k) q[i].w -= d[q[i].u][a];
        FOR(i,1,n) lim[i] = -1e18,ok[i] = 0;
        FOR(i,1,k) lim[q[i].v] = std::max(lim[q[i].v],q[i].w);
        FOR(v,1,n){
            FOR(b,1,n){
                if(!mp[a][b]) continue;
                ok[b] |= (d[v][b]+mp[a][b] <= lim[v]);
            }
        }
        FOR(i,1,n) ans += ok[i];
        FOR(i,1,k) q[i].w += d[q[i].u][a];
    }
    ans >>= 1;
    printf("%d\n",ans);
    return 0;
}