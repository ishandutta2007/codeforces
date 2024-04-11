/*
 * sto Qingyu orz
 * sqysqy,
 * 
 * sqy
 * Author: RainAir
 * Time: 2019-10-18 20:01:04
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

const int MAXN = 1e6 + 5;
int k;
std::vector<int> G[MAXN];
std::vector<int> a,b,c,d;
int n,m,l,r;
int du[MAXN];

inline void add(int u,int v){
    G[u].pb(v);++m;
}

int main(){
    scanf("%d",&k);
    if(!(k&1)){
        puts("NO");
        return 0;
    }
    puts("YES");
    l = 1;r = 2;n = 2;
    add(1,2);int t = k-1;
    int tot = 2;
    FOR(i,1,t) a.pb(++tot),b.pb(++tot),c.pb(++tot),d.pb(++tot);
    n = tot;
    FOR(i,1,t-1) add(b[i],b[i-1]),add(d[i],d[i-1]),++i;
    FOR(i,0,t-1) add(a[i],1),add(c[i],2);
    FOR(i,0,t-1) FOR(j,0,t-1) add(a[i],b[j]),add(c[i],d[j]);
    printf("%d %d\n",n,m);
    FOR(i,1,n){
        for(auto x:G[i]) printf("%d %d\n",i,x),++du[i],++du[x];
    }
    return 0;
}