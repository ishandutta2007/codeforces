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

const int MAXN = 1000+5;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int n,m;
char str[MAXN][MAXN];
bool vis[MAXN][MAXN];

inline void dfs(int x,int y){
    if(vis[x][y]) return;
    vis[x][y] = 1;
    FOR(i,0,3){
        int xx = x+dx[i],yy = y+dy[i];
        if(xx >= 1 && xx <= n && yy >= 1 && yy <= m) dfs(xx,yy);
    }
}

bool r[MAXN],c[MAXN],rr[MAXN],cc[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    if((n == 1)^(m == 1)){
        puts("-1");
        return 0;
    }
    FOR(i,1,n) scanf("%s",str[i]+1);
    FOR(i,1,n) str[i][0] = str[i][m+1] = '.';
    FOR(i,1,m) str[0][i] = str[n+1][i] = '.';
    FOR(i,1,n) FOR(j,1,m) if(str[i][j] == '#') r[i] = c[j] = 1;
    FOR(i,1,n){
        int t = 0;
        FOR(j,1,m+1) if(str[i][j] != str[i][j-1]) t++;
        if(t > 2){
            puts("-1");
            exit(0);
        }
    }
    FOR(i,1,m){
        int t = 0;
        FOR(j,1,n+1) if(str[j][i] != str[j-1][i]) ++t;
        if(t > 2){
            puts("-1");
            exit(0);
        }
    }
    FOR(i,1,n){
        FOR(j,1,m){
            if(str[i][j]=='#' || (!r[i]&&!c[j])){
                rr[i] = cc[j] = 1;
            }
        }
    }
    FOR(i,1,n) if(!rr[i]) {puts("-1");return 0;}
    FOR(i,1,m) if(!cc[i]) {puts("-1");return 0;}
    FOR(i,1,n) FOR(j,1,m) if(str[i][j] == '.') vis[i][j] = 1;
    int res = 0;
    FOR(i,1,n) FOR(j,1,m) if(!vis[i][j]) ++res,dfs(i,j);
    printf("%d\n",res);
    return 0;
}