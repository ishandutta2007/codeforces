/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-13 17:47:34
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
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define int LL
const int MAXN = 1e5 + 5;
int c[MAXN][3];
int n;
int du[MAXN];
 
std::vector<int> G[MAXN];
 
bool inq[MAXN];
std::queue<int> q;
std::vector<int> v;
 
inline void bfs(int rt){
    q.push(rt);v.pb(rt);inq[rt] = 1;
    while(!q.empty()){
        int vv = q.front();q.pop();
        for(auto x:G[vv]){
            if(inq[x]) continue;
            inq[x] = true;q.push(x);v.pb(x);
        }
    }
}
 
int f[MAXN],anss[MAXN];
 
signed main(){
    scanf("%lld",&n);
    FOR(i,1,3) FOR(j,1,n) scanf("%lld",&c[j][i]);
    FOR(i,1,n-1){
        int u,v;scanf("%lld%lld",&u,&v);
        G[u].pb(v);G[v].pb(u);
    }
    int rt = 0;
    FOR(i,1,n){
        if(G[i].size() >= 3){
            puts("-1");
            return 0;
        }
        if(G[i].size() == 1) rt = i;
    }
    bfs(rt);
    int ans = 1e18,col1,col2;
    FOR(i,1,3){
        FOR(j,1,3){
            if(i == j) continue;
            f[1] = i;f[2] = j;int res = 0;
            FOR(k,3,n){
                int x = f[k-1],y = f[k-2];
                if(x > y) std::swap(x,y);
                if(x == 1 && y == 2) f[k] = 3;
                if(x == 1 && y == 3) f[k] = 2;
                if(x == 2 && y == 3) f[k] = 1;
            }
            FOR(k,1,n) res += c[v[k-1]][f[k]];
            if(res < ans){
                ans = res;col1 = i;col2 = j;
            }
        }
    }
    f[1] = col1;f[2] = col2;
    FOR(i,3,n){
        int x = f[i-1],y = f[i-2];
        if(x > y) std::swap(x,y);
        if(x == 1 && y == 2) f[i] = 3;
        if(x == 1 && y == 3) f[i] = 2;
        if(x == 2 && y == 3) f[i] = 1;
    }
    FOR(i,1,n) anss[v[i-1]] = f[i];
    printf("%lld\n",ans);
    FOR(i,1,n) printf("%lld ",anss[i]);
    puts("");
    return 0;
}