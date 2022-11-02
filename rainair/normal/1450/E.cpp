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

const int MAXN = 200+5;

int G[MAXN][MAXN],dis[MAXN][MAXN];
int n,m;
bool flag=1;
int col[MAXN];
bool vis[MAXN];

inline void dfs(int v){
    vis[v] = 1;
    FOR(i,1,n){
        if(G[v][i] == 1e8 || v == i) continue;
        if(vis[i]) flag &= (col[v]^col[i]);
        else col[i] = col[v]^1,dfs(i);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) FOR(j,1,n) G[i][j] = 1e8;
    FOR(i,1,n) G[i][i] = 0;
    while(m--){
        int i,j,w;scanf("%d%d%d",&j,&i,&w);
        if(!w){
            G[j][i] = std::min(G[j][i],1);
            G[i][j] = std::min(G[i][j],1);
        }
        else{
            G[j][i] = std::min(G[j][i],1);
            G[i][j] = std::min(G[i][j],-1);
        }
    }
    dfs(1);
    if(!flag){
        puts("NO");
        return 0;
    }
    FOR(i,1,n) FOR(j,1,n) dis[i][j] = G[i][j];
    int cir = 1e9;
    FOR(k,1,n){
        FOR(i,1,k-1){
            FOR(j,1,k-1){
                if(i == j) continue;
                cir = std::min(cir,G[k][i]+G[j][k]+dis[i][j]);
            }
        }
        FOR(i,1,n){
            FOR(j,1,n){
                dis[i][j] = std::min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
//    FOR(i,1,n) FOR(j,1,n) if(G[i][j] != 1e9 && i != j) printf("%d %d %d\n",i,j,G[i][j]);
    if(cir < 0){
        puts("NO");
        return 0;
    }
    int mx = 0,ps = -1;
    FOR(i,1,n){
        int c = -1e9;
        FOR(j,1,n) c = std::max(c,dis[i][j]);
        if(mx < c){
            mx = c;ps = i;
        }
    }
    puts("YES");
    printf("%d\n",mx);
    FOR(i,1,n) printf("%d%c",dis[ps][i]," \n"[i==n]);
    return 0;
}