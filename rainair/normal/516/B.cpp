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

const int MAXN = 2000+5;
char str[MAXN][MAXN];
int n,m;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
int deg[MAXN][MAXN];
char ans[MAXN][MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%s",str[i]+1);
    FOR(i,1,n){
        FOR(j,1,m){
            if(str[i][j] == '*'){
                ans[i][j] = '*';continue;
            }
            FOR(k,0,3){
                int ii = i+dx[k],jj = j+dy[k];
                if(ii >= 1 && ii <= n && jj >= 1 && jj <= m && str[ii][jj] != '*') ++deg[i][j];
            }
        }
    }
    std::queue<P> q;
    FOR(i,1,n) FOR(j,1,m) if(deg[i][j]==1) q.push(MP(i,j));
    while(!q.empty()){
        P v = q.front();q.pop();
        if(!deg[v.fi][v.se]) continue;
        int x = v.fi,y = v.se,xx,yy;
        FOR(k,0,3){
            xx = x+dx[k],yy = y+dy[k];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !ans[xx][yy]){
                --deg[xx][yy];
                if(x == xx){
                    ans[x][std::min(y,yy)] = '<';
                    ans[x][std::max(y,yy)] = '>';
                }
                else{
                    ans[std::min(x,xx)][y] = '^';
                    ans[std::max(x,xx)][y] = 'v';
                }
                break;
            }
        }
        deg[x][y] = deg[xx][yy] = 0;
        FOR(k,0,3){
            x = xx+dx[k],y = yy+dy[k];
            if(x >= 1 && x <= n && y >= 1 && y <= m && !ans[x][y]){
                --deg[x][y];
                if(deg[x][y] == 1) q.push(MP(x,y));
            }
        }
    }
    bool flag = 1;
    FOR(i,1,n) FOR(j,1,m) flag &= (int)ans[i][j]>0;
    if(!flag){
        puts("Not unique");
        return 0;
    }
    FOR(i,1,n){
        FOR(j,1,m) putchar(ans[i][j]);
        puts("");
    }
    return 0;
}