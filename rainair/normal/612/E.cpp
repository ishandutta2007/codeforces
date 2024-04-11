#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
int p[MAXN];
std::vector<int> c[MAXN];int tot;
std::vector<int> G[MAXN];
int id[MAXN];bool vis[MAXN];int n;
int ans[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",p+i);
    FOR(i,1,n){
        if(!vis[i]){
            int v = p[i];++tot;
            vis[i] = 1;id[i] = tot;c[tot].pb(i);
            while(v != i){
                vis[v] = 1;
                id[v] = tot;c[tot].pb(v);
                v = p[v];
            }
            G[SZ(c[tot])].pb(tot);
        }
    }
    for(int i = 2;i <= n;i += 2){
        if(SZ(G[i])&1){
            puts("-1");
            return 0;
        }
        for(int j = 0;j < SZ(G[i]);j += 2){
            int lst = -1;
            FOR(k,0,i-1){
                if(lst != -1) ans[lst] = c[G[i][j]][k];
                lst = c[G[i][j]][k];
                if(lst != -1) ans[lst] = c[G[i][j+1]][k];
                lst = c[G[i][j+1]][k];
            }
            ans[lst] = c[G[i][j]][0];
        }
    }
    FOR(i,1,tot) if(SZ(c[i]) == 1) ans[c[i][0]] = c[i][0];
    for(int i = 3;i <= n;i += 2){
        FOR(j,0,SZ(G[i])-1){
            int p1 = 0,p2 = (i+1)/2;
            int lst = -1;
            while(p2 < i){
                if(lst != -1) ans[lst] = c[G[i][j]][p1];
                lst = c[G[i][j]][p1];++p1;
                if(lst != -1) ans[lst] = c[G[i][j]][p2];
                lst = c[G[i][j]][p2];++p2;
            }
            ans[lst] = c[G[i][j]][p1];lst = c[G[i][j]][p1];++p1;
            ans[lst] = c[G[i][j]][0];
        }
    }
    FOR(i,1,n) printf("%d%c",ans[i]," \n"[i==n]);
    return 0;
}