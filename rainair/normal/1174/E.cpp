/*
 * Author: RainAir
 * Time: 2019-10-09 14:27:36
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

const int MAXN = 1e6 + 6;
const int MAXL = 20 + 2;
const int ha = 1e9 + 7;

int n,f[MAXN][MAXL][2];

inline int N(int x,int y){
    return (1<<x)*(y?3:1);
}

int main(){
    scanf("%d",&n);int lg = log2(n);
    if(n == 1){
        puts("1");
        return 0;
    }
    f[1][lg][0] = 1;
    if((1<<(lg-1))*3 <= n) f[1][lg-1][1] = 1;
    FOR(i,1,n-1){
        FOR(j,0,lg){
            FOR(k,0,1){
                (f[i+1][j][k] += 1ll*f[i][j][k]*(n/N(j,k)-i)%ha) %= ha;
                (f[i+1][j-1][k] += 1ll*f[i][j][k]*(n/N(j-1,k)-n/N(j,k))%ha) %= ha;
                if(k) (f[i+1][j][k-1] += 1ll*f[i][j][k]*(n/N(j,k-1)-n/N(j,k))%ha)%=ha;
            }
        }
    }
    printf("%d\n",f[n][0][0]);
    return 0;
}