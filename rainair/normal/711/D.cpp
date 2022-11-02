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
#define P std::pair
#define Re register
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(Re int i = a;i <= b;++i)
#define ROF(i,a,b) for(Re int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 2e5 + 5;
std::vector<int> G[MAXN];
int n,f[MAXN],in[MAXN];
bool del[MAXN];

const int ha = 1e9 + 7;

inline int qpow(int a,int n){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

int pre[MAXN],vis[MAXN],cnt,num;
inline void dfs(int v,int fa,int dep){
    ++num;vis[v] = true;pre[v] = dep;
    for(auto x:G[v]){
        if(!vis[x]) dfs(x,v,dep+1);
        else if(x != fa) cnt = std::abs(pre[x]-pre[v])+1;
    }
}
LL ans = 1;
int main(){
    scanf("%d",&n);int remain = n;
    FOR(i,1,n) scanf("%d",f+i),G[i].pb(f[i]),G[f[i]].pb(i);
    FOR(i,1,n){
        if(vis[i]) continue;
        cnt = num = 0;
        dfs(i,0,0);remain -= cnt;
        ans = 1ll*ans*(qpow(2,cnt)-2+ha)%ha;
    }
    ans = 1ll*ans*qpow(2,remain)%ha;
    printf("%lld\n",ans);
    return 0;
}