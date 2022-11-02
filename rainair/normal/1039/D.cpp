/*
 * Author: RainAir
 * Time: 2019-08-02 19:57:33
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

const int MAXN = 200000 + 5;
std::vector<int> G[MAXN],gg;
int mx[MAXN],fa[MAXN],n,sz;

inline void dfs(int v,int faa=0){
    for(auto x:G[v]){
        if(x == faa) continue;
        fa[x] = v;dfs(x,v);
    }
    gg.pb(v);
}

inline int solve(int k){
    int ans = 0;
    FOR(i,1,n) mx[i] = 1;
    for(auto x:gg){
        if(fa[x] && mx[fa[x]] != -1 && mx[x] != -1){
            if(mx[x] + mx[fa[x]] >= k) mx[fa[x]] = -1,ans++;
            else mx[fa[x]] = std::max(mx[fa[x]],mx[x]+1);
        }
    }
    return ans;
}

int ans[MAXN];

int main(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    dfs(1);sz = std::min(400,n);
    ans[1] = n;FOR(i,2,sz+1) ans[i] = solve(i);
    for(int i = sz+1,j = i;i <= n;i = j+1,j = i){
        int l = i,r = n,t = solve(i);
        while(l < r){
            //DEBUG(l);DEBUG(r);
            int mid = (l + r + 1) >> 1;
            if(solve(mid) == t) l = mid;
            else r = mid-1;
        }
        j = l;
        FOR(k,i,j) ans[k] = t;
    }
    FOR(i,1,n) printf("%d\n",ans[i]);
    return 0;
}