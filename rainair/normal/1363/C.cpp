/*
 * Author: RainAir
 * Time: 2020-06-01 15:04:25
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

const int MAXN = 1000+5;
int du[MAXN],sg[MAXN];

inline void Solve(){
    int n,x;scanf("%d%d",&n,&x);
    FOR(i,1,n) du[i] = 0;
    FOR(i,2,n){
        int u,v;scanf("%d%d",&u,&v);du[u]++;du[v]++;
    }
    if(du[x] <= 1){
        puts("Ayush");
        return;
    }
    if(n & 1){
        puts("Ashish");
        return;
    }
    puts("Ayush");
    return;
}

int main(){
    int T;scanf("%d",&T);
    while(T--) Solve();
    return 0;
}