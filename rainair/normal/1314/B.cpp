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

const int MAXN = 4e5 + 5;
int f[MAXN][4];
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    int N = (1<<(n-1));
    FOR(i,0,MAXN-1) FOR(j,1,3) f[i][j] = -1e9;
    FOR(i,1,k){
        int x;scanf("%d",&x);
        x = N+((x-1)>>1);
        f[x][3] = f[x][1];f[x][1] = f[x][2] = 1;
    }
    ROF(i,N-1,1){
        FOR(x,0,3){
            FOR(y,0,3){
                f[i][x|y] = std::max(f[i][x|y],f[i*2][x]+f[i*2+1][y]+(x|y));
            }
        }
    }
    printf("%d\n",std::max({f[1][1],f[1][2],f[1][3],-1})+1);
    return 0;
}