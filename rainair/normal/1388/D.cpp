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
#define int LL
const int MAXN = 2e5 + 5;
int a[MAXN],b[MAXN],n;
std::vector<int> G[MAXN];
int dep[MAXN];

inline void dfs(int v,int fa=0){
    dep[v] = dep[fa]+1;
    for(auto x:G[v]){
        dfs(x,v);
    }
}
std::vector<int> opt;
int ans = 0;

inline bool cmp1(int x,int y){
    return dep[x] > dep[y];
}

inline bool cmp2(int x,int y){
    return dep[x] < dep[y];
}

struct Node{
    int x;
    Node(int x=0) : x(x) {}
    bool operator < (const Node &t) const {
        return dep[x] < dep[t.x];
    }
};

std::priority_queue<Node> q;
bool vis[MAXN];

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",a+i);
    FOR(i,1,n) scanf("%lld",b+i);
    FOR(i,1,n) if(b[i] != -1) G[b[i]].pb(i);
    FOR(i,1,n) if(b[i] == -1) dfs(i);
    FOR(i,1,n){
        if(a[i] >= 0) q.push(Node(i));
    }
    int ans = 0;std::vector<int> tt;
    while(!q.empty()){
        int v = q.top().x;q.pop();
        vis[v] = 1;ans += a[v];tt.pb(v);
        if(b[v] != -1){
            bool flag = (a[b[v]] < 0);
            a[b[v]] += a[v];
            if(flag && a[b[v]] >= 0){
                q.push(Node(b[v]));
            }
        }
    }
    std::vector<int> rem;
    FOR(i,1,n) if(!vis[i]) rem.pb(i);
    std::sort(all(rem),cmp2);
    for(auto x:rem){
        tt.pb(x);ans += a[x];
        if(b[x] != -1) a[b[x]] += a[x];
    }
    printf("%lld\n",ans);
    for(auto x:tt) printf("%lld ",x);puts("");
    return 0;
}