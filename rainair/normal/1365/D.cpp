#include <algorithm>
#include <iostream>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>

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

const int MAXN = 100+5;
int n,m;
char a[MAXN][MAXN];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
bool vis[MAXN][MAXN];
inline void Solve(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%s",a[i]+1);
    FOR(i,1,n){
        FOR(j,1,m){vis[i][j] = 0;
            if(a[i][j] == 'B'){
                FOR(k,0,3){
                    int ii = i+dx[k],jj = j+dy[k];
                    if(ii >= 1 && ii <= n && jj >= 1 && jj <= m){
                        if(a[ii][jj] == 'G'){
                            puts("No");return;
                        }
                        if(a[ii][jj] == '.') a[ii][jj] = '#';
                    }
                }
            }
        }
    }
    std::queue<P> q;
    if(a[n][m] != '#')q.push(MP(n,m)),vis[n][m] = 1;
    while(!q.empty()){
        P v = q.front();q.pop();
        FOR(i,0,3){
            int xx = v.fi+dx[i],yy = v.se+dy[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy] && a[xx][yy] != '#'){
                q.push(MP(xx,yy)) ;vis[xx][yy] = 1;               
            }
        }
    }
    FOR(i,1,n){
        FOR(j,1,m){
            if(a[i][j] == 'B' && vis[i][j]){puts("No");return;}
            if(a[i][j] == 'G' && !vis[i][j]){puts("No");return;}
        }
    }
    puts("Yes");
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}