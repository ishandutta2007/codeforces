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

const int MAXN = 2e7 + 5;

LL dis[MAXN];
bool vis[MAXN];
int n,m,g,r,d[MAXN];

inline int calc(int i,int j){
    return (i-1)*(g+1)+j+1;
}

std::deque<int> q;

inline void relax(int x,int y,int z){
    if(vis[y]) return;
    dis[y] = dis[x]+z;vis[y] = 1;
    if(z == 0) q.push_front(y);
    else q.push_back(y);
}

inline void bfs(){
    FOR(i,1,calc(m,g)) dis[i] = 1e18;
    dis[calc(1,g)] = 0;q.pb(calc(1,g));vis[calc(1,g)] = 1;
    while(!q.empty()){
        int v = q.front();q.pop_front();
        int q=1+v/(g+1),r = v%(g+1) - 1;
        if(r < 0){
            q--;(r += (g+1)) %= (g+1);
        }
        if(v != calc(q,r)){
            exit(-1);
        }
        if(r == 0) relax(calc(q,r),calc(q,g),1);
        FOR(i,std::max(1,q-1),std::min(m,q+1)){
            if(i == q) continue;
            int tor = r-std::abs(d[i]-d[q]);
            if(tor < 0) continue;
            else relax(calc(q,r),calc(i,tor),0);
        }
    }
}

int main(){
    //n = 1e6;m = 1e4;
    scanf("%d%d",&n,&m);
    ++n;
    FOR(i,1,m) scanf("%d",d+i),d[i]++;
    //FOR(i,1,m) d[i] = i;
    std::sort(d+1,d+m+1);
    //g = r = 1000;
    scanf("%d%d",&g,&r);
    bfs();
    LL ans = 1e18;
    FOR(i,1,m){
        FOR(j,0,g){
            if(dis[calc(i,j)] == 1e18) continue;
            if(n-d[i] <= j){
                ans = std::min(ans,1ll*dis[calc(i,j)]*(g+r)+g-j+n-d[i]);
            }
        }
    }
    printf("%lld\n",ans==1e18?-1:ans);
    return 0;
}