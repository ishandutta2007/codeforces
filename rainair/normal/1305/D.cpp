/*
 * Author: RainAir
 * Time: 2020-03-03 22:56:10
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
#define P std::pair<int,int>
#define LL long long
#define pb push_back
#define MP std::make_pair
#define all(x) x.begin(),x.end()
#define CLR(i,a) memset(i,a,sizeof(i))
#define FOR(i,a,b) for(int i = a;i <= b;++i)
#define ROF(i,a,b) for(int i = a;i >= b;--i)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

const int MAXN = 1000+5;
int n;
std::vector<int> G[MAXN];
int du[MAXN];
bool del[MAXN];

inline void query(int u,int v){
    printf("? %d %d\n",u,v);std::fflush(stdout);
}

int main(){
    scanf("%d",&n);
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);
        G[u].pb(v);G[v].pb(u);
        du[u]++;du[v]++;
    }
    int ans = 0;
    FOR(i,1,n/2){
        int x=-1,y=-1;
        FOR(j,1,n){
            if(del[j]) continue;
            if(du[j] == 1){
                if(x == -1) x = j;
                else if(y == -1) y = j;
            }
        }
        int t;query(x,y);scanf("%d",&t);
        if(t == x || t == y){
            printf("! %d\n",t);std::fflush(stdout);
            return 0;
        }
        for(auto to:G[x]){
            if(du[to]) du[to]--;
        }
        for(auto to:G[y]){
            if(du[to]) du[to]--;
        }
        du[x]--;du[y]--;del[x] = 1;del[y] = 1;
    }
    FOR(i,1,n){
        if(!del[i]){
            printf("! %d\n",i);std::fflush(stdout);
            return 0;
        }
    }
    return 0;
}