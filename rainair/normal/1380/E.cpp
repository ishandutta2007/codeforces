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
int n,m;
std::vector<int> G[MAXN];
int a[MAXN],now;
int f[MAXN];

inline int find(int x){
    return x == f[x] ? x : f[x] = find(f[x]);
}

inline void merge(int x,int y){
    x = find(x);y = find(y);
    if(G[x].size() < G[y].size()) std::swap(x,y);
    f[y] = x;
    for(auto v:G[y]){
        G[x].pb(v);
        if(a[v] != a[v-1]) now--;
        if(a[v] != a[v+1]) now--;
        a[v] = x;
        if(a[v] != a[v-1]) now++;
        if(a[v] != a[v+1]) now++;
    }
    G[y].clear();
}

int main(){
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",a+i),G[a[i]].pb(i),f[i] = i;
    FOR(i,2,n) if(a[i] != a[i-1]) now++;
    printf("%d\n",now);
    FOR(i,2,m){
        int x,y;scanf("%d%d",&x,&y);
//        DEBUG(G[x].size());DEBUG(G[y].size());
        merge(x,y);
        printf("%d\n",now);
//        FOR(i,1,n) printf("%d ",a[i]);puts("");
    }
    return 0;
}