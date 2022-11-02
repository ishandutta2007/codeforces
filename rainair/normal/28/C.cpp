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

const int MAXN = 50+5;
int a[MAXN],n,m;
double f[MAXN][MAXN][MAXN],C[MAXN][MAXN];
double x[MAXN],y[MAXN];

inline void work(){
    FOR(i,1,m){
        FOR(j,0,n){
            FOR(u,0,j){
                FOR(k,0,n){
                    int t = std::ceil(1.0*u/a[i]);
                    if(t > k) f[i][j-u][t] += f[i-1][j][k]*C[j][u]*x[u];
                    else f[i][j-u][k] += f[i-1][j][k]*C[j][u]*x[u];
                }
            }
        }
    }
}

int main(){
    FOR(i,0,50) C[i][0] = 1,C[i][1] = i;
    FOR(i,1,50) FOR(j,2,i) C[i][j] = C[i-1][j]+C[i-1][j-1];
    scanf("%d%d",&n,&m);FOR(i,1,m) scanf("%d",a+i);
    f[0][n][0] = 1.0;
    x[0] = 1;FOR(i,1,n) x[i] = x[i-1]/m;
    work();
    double ans = 0;
    FOR(i,1,n) ans += 1.0*f[m][0][i]*i;//DEBUG(f[m][0][i]);
    printf("%.20f\n",ans);
    return 0;
}