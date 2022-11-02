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

const int MAXN = 2e5 + 5;
std::vector<int> G[MAXN];
int n;
int col[MAXN];
int cnt[2];

inline void dfs(int v,int fa=0){
    cnt[col[v]]++;
    for(auto x:G[v]){
        if(x == fa) continue;
        col[x] = col[v]^1;
        dfs(x,v);
    }
}

int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    dfs(1);
    printf("%d\n",std::min(cnt[0],cnt[1])-1);
    return 0;
}