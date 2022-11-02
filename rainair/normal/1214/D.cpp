/*
 * Author: RainAir
 * Time: 2019-09-04 18:00:02
 */
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1e6 + 5;
const int dx[] = {1,0};
const int dy[] = {0,1};
int n,m;
char str[MAXN];
int now = 0;
std::vector<int> G[MAXN],vis[MAXN],used[MAXN];
std::vector<P> pre[MAXN];
P nil = MP(-1,-1);

inline bool bfs(){
    std::queue<P> q;
    FOR(i,1,n) FOR(j,1,m) pre[i][j] = nil,used[i][j] = false;
    q.push(MP(1,1));used[1][1] = true;
    while(!q.empty()){
        P v = q.front();q.pop();
        int x = v.fi,y = v.se;
        if(x == n && y == m) return true;
        if(G[x][y] == '#') continue;
        if(vis[x][y]) continue;
        FOR(i,0,1){
            int xx = x+dx[i],yy = y+dy[i];
            if(xx >= 1 && xx <= n && yy >= 1 && yy <= m && !vis[xx][yy] && !G[xx][yy] && !used[xx][yy]){
                pre[xx][yy] = MP(x,y);
                used[xx][yy] = true;
                q.push(MP(xx,yy));
            }
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) G[i].resize(m+5),vis[i].resize(m+5),pre[i].resize(m+5),used[i].resize(m+5);
    FOR(i,1,n){
        scanf("%s",str+1);
        FOR(j,1,m) G[i][j] = str[j] == '#';
    }
    bool flag1 = bfs();
    if(!flag1){
        puts("0");
        return 0;
    }
    P v = MP(n,m);
    while(v != nil){
        v = pre[v.fi][v.se];
        if(v == nil) break;
        if(v.fi == v.se && v.fi == 1) break;
        vis[v.fi][v.se] = true;
    }
//    FOR(i,1,n) FOR(j,1,m) printf("%d%c",vis[i][j],(j == m) ? '\n' : ' ');
    if(flag1 && bfs()){
        puts("2");
    }
    else{
        puts("1");
    }
    return 0;
}