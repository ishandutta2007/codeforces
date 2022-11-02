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

const int MAXN = 2e5 + 5;

int a[MAXN],n;
std::vector<P> G[MAXN];
int s[MAXN],top=0;
int cf[MAXN],dep[MAXN],fa[MAXN];
LL sum[MAXN];

inline LL dis(int u,int v){
    if(dep[u] > dep[v]) std::swap(u,v);
    return sum[v]-sum[u];
}

inline int calc(int x,int v){
    int l = 1,r = top,ans = v;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(dis(s[mid],v) <= a[v]) ans = s[mid],r = mid-1;
        else l = mid+1;
    }
    return ans;
}

inline void dfs1(int v){
    int t = calc(a[v],v);//DEBUG(v);DEBUG(t);
    s[++top] = v;//cf[t]--;cf[v]++;
    if(t != v){
        //cf[t]++;cf[fa[v]]++;cf[fa[t]] -= 2;
        //cf[t++];
        cf[fa[v]]++;cf[fa[t]]--;
    }
    for(auto x:G[v]){
        if(x.fi == fa[v]) continue;
        sum[x.fi] = sum[v] + x.se;
        dep[x.fi] = dep[v] + 1;fa[x.fi] = v;
        dfs1(x.fi);
    }
    --top;
}

int ans[MAXN];

inline void dfs2(int v){
    ans[v] = cf[v];//DEBUG(v);DEBUG(ans[v]);
    for(auto x:G[v]){
        if(x.fi == fa[v]) continue;
        dfs2(x.fi);
        ans[v] += ans[x.fi];
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",a+i);
    FOR(i,2,n){
        int u,w;scanf("%d%d",&u,&w);
        G[u].pb(MP(i,w));G[i].pb(MP(u,w));
    }
    dep[1] = 1;
    dfs1(1);dfs2(1);
    FOR(i,1,n) printf("%d ",ans[i]);
    return 0;
}