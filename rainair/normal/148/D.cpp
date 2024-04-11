/*
 * Author: RainAir
 * Time: 2019-07-12 14:17:32
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

const int MAXN = 1000+5;
int w,b;
double f[MAXN][MAXN];

inline double dfs(int w,int b){
    if(w <= 0) return 0;
    if(b <= 0) return 1;
    if(f[w][b]) return f[w][b];
    double &ans = f[w][b];
    double all = w+b;ans += w*1.0/all;
    if(all > 2) ans += 1.0* b/all * (b-1)/(all-1) * (1.0*w/(all-2)*dfs(w-1,b-2));
    if(all > 2 && b >= 3) ans += 1.0*b/all * (b-1)/(all-1) * (1.0*(b-2)/(all-2)*dfs(w,b-3));
    return ans;
}

int main(){
    scanf("%d%d",&w,&b);
    printf("%.9f\n",dfs(w,b));
    return 0;
}