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
#define U unsigned
#define P std::pair<int,int>
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1500 + 5;
char str[MAXN][MAXN];
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
P S;
const int MAX = 10;
int n,m;
bool vis[MAXN][MAXN];
P num[MAXN][MAXN];
inline void dfs(int x,int y){
    if(str[x%n][y%m] == '#') return;
    if(!num[x%n][y%m].fi && !num[x%n][y%m].se) num[x%n][y%m] = MP(x,y);
    else{
        if(MP(x,y) != num[x%n][y%m]){
            puts("Yes");
            exit(0);
        }
        else return;
    }
    dfs(x-1,y);dfs(x,y-1);dfs(x+1,y);dfs(x,y+1);
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,0,n-1) scanf("%s",str[i]);
    FOR(i,0,n-1) FOR(j,0,m-1) if(str[i][j] == 'S') S = MP(i,j);
    dfs(S.fi+n*1000,S.se+m*1000);
    puts("No");
    return 0;
}