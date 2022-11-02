/*
 * Author: RainAir
 * Time: 2019-10-09 10:35:18
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

const int MAXN = 2000+5;
const int ha = 1e9 + 7;

inline int qpow(int a,int n=ha-2){
    int res = 1;
    while(n){
        if(n & 1) res = 1ll*res*a%ha;
        a = 1ll*a*a%ha;
        n >>= 1;
    }
    return res;
}

int k,pa,pb;
int f[MAXN][MAXN];

inline int dfs(int i,int j){//   i  aj  ab
    if(i+j >= k) return ((i+j)%ha+1ll*pa*qpow(pb)%ha)%ha;
    if(f[i][j] != -1) return f[i][j];
    return f[i][j] = 1ll*(1ll*dfs(i+1,j)*pa%ha+1ll*dfs(i,i+j)*pb%ha)%ha;
}

int main(){
    scanf("%d%d%d",&k,&pa,&pb);CLR(f,-1);
    int t = pa+pb;t = qpow(t);
    pa = 1ll*pa*t%ha;pb = 1ll*pb*t%ha;
    printf("%d\n",dfs(1,0));
    return 0;
}