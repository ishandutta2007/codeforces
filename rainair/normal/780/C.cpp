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
int n,ans[MAXN],size[MAXN];
int lim;

void dfs1(int v,int fa){
    size[v] = 1;if(fa) size[v]++;
    for(auto x:G[v]){
        if(x == fa) continue;
        size[v]++;dfs1(x,v);
    }
}

void dfs2(int v,int fa){
    int t = 1;
    for(auto x:G[v]){
        if(x == fa) continue;
        while(t == ans[v] || t == ans[fa]) t++;
      //  if(v == 3) DEBUG(t),DEBUG(ans[v]),DEBUG(ans[fa]);
        ans[x] = t++;
        //DEBUG(ans[3]);
        //dfs2(x,v);
    }
    for(auto x:G[v]){
        if(x == fa) continue;
        dfs2(x,v);
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,1,n-1){
        int x,y;scanf("%d%d",&x,&y);
        G[x].pb(y);G[y].pb(x);
    }
    dfs1(1,0);FOR(i,1,n) lim = std::max(lim,size[i]);
    ans[1] = 1;dfs2(1,0);
    printf("%d\n",lim);
    FOR(i,1,n) printf("%d ",ans[i]);
    return 0;
}