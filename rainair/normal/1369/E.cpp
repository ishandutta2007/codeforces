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

const int MAXN = 5e5 + 5;
int n,m;
int w[MAXN];
int x[MAXN],y[MAXN],du[MAXN];
std::vector<int> G[MAXN];
int ans[MAXN];bool vis[MAXN],qd[MAXN];

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",w+i);int ts = 0;
    FOR(i,1,m){
        scanf("%d%d",x+i,y+i);
        du[x[i]]++;du[y[i]]++;
        G[x[i]].pb(i);G[y[i]].pb(i);
    }
    std::queue<int> q;
    FOR(i,1,n) if(du[i] <= w[i]) q.push(i),vis[i] = 1;
    while(!q.empty()){
        int v = q.front();q.pop();
        for(auto x:G[v]){
            if(qd[x]) continue;
            ans[++ts] = x;
//            ans[x] = ++ts;
//            DEBUG(x);DEBUG(ts);
            qd[x] = 1;
            int t = ::x[x];if(t == v) t = ::y[x];
            if(vis[t]) continue;
            --du[t];
            if(du[t] > w[t]) continue;
            vis[t] = 1;q.push(t);
        }
    }
    if(ts != m){
        puts("DEAD");return 0;
    }
    puts("ALIVE");
    ROF(i,m,1) printf("%d ",ans[i]);puts("");
    return 0;
}