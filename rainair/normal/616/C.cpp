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

const int MAXN = 1000+5;
int id[MAXN][MAXN],tot;
char str[MAXN][MAXN];
int sz[MAXN*MAXN],n,m;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};

inline void dfs(int i,int j){
    id[i][j] = tot;++sz[tot];
    FOR(k,0,3){
        int ii = i+dx[k],jj = j+dy[k];
        if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && str[ii][jj] == '.' && !id[ii][jj]) dfs(ii,jj);
    }
}
bool vis[MAXN*MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%s",str[i]+1);
    FOR(i,1,n){
        FOR(j,1,m){
            if(str[i][j] == '*' || id[i][j]) continue;
            ++tot;dfs(i,j);
        }
    }
    int mx = 0;
    FOR(i,1,tot) mx = std::max(mx,sz[i]);
    FOR(i,1,n){
        FOR(j,1,m){
            if(str[i][j] == '*'){
                int sm = 1;
                FOR(k,0,3){
                    int ii = i+dx[k],jj = j+dy[k];
                    if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && str[ii][jj] == '.' && !vis[id[ii][jj]]) vis[id[ii][jj]] = 1,sm += sz[id[ii][jj]];
                }
                printf("%d",sm%10);
                FOR(k,0,3){
                    int ii = i+dx[k],jj = j+dy[k];
                    if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && str[ii][jj] == '.') vis[id[ii][jj]] = 0;
                }
            }
            else putchar('.');
        }
        puts("");
    }
    return 0;
}