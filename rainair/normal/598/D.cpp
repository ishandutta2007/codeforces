#include <bits/stdc++.h>

#define fi first
#define se second
#define db double
#define U unsigned
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define SZ(x) ((int)x.size())
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
int n,m,k;
char str[MAXN][MAXN];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int tot;
int id[MAXN][MAXN],ans[MAXN*MAXN];
bool vis[MAXN][MAXN];

inline void dfs(int i,int j){
    id[i][j] = tot;vis[i][j] = 1;
    FOR(k,0,3){
        int ii = i+dx[k],jj = j+dy[k];
        if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && !vis[ii][jj]){
            if(str[ii][jj] == '*') ++ans[tot];
            else dfs(ii,jj);
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%s",str[i]+1);
    FOR(i,1,n) FOR(j,1,m) if(str[i][j] == '.' && !vis[i][j]){
        ++tot;dfs(i,j);
    }
    FOR(i,1,k){
        int x,y;scanf("%d%d",&x,&y);printf("%d\n",ans[id[x][y]]);
    }
    return 0;
}