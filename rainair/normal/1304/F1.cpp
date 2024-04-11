/*
 * Author: RainAir
 * Time: 2020-03-03 11:01:39
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

const int MAXN = 2e4 + 332;
int f[2][MAXN],now;
int n,m,k;
int pre[MAXN],suf[MAXN];
int a[51][MAXN];
int sm[51][MAXN];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) FOR(j,1,m) scanf("%d",&a[i][j]);
    FOR(i,1,n) FOR(j,1,m) sm[i][j] = sm[i][j-1]+a[i][j];
    FOR(i,1,m-k+1) f[now][i] = sm[1][i+k-1]-sm[1][i-1];
    FOR(i,2,n){
        now ^= 1;
        FOR(j,0,m+23) pre[j] = suf[j] = 0;
        FOR(j,1,m-k+1) pre[j] = std::max(pre[j-1],f[now^1][j]+sm[i][j+k-1]-sm[i][j-1]);
        ROF(j,m-k+1,0) suf[j] = std::max(suf[j+1],f[now^1][j]+sm[i][j+k-1]-sm[i][j-1]);
        FOR(j,1,m-k+1){
            f[now][j] = std::max(pre[std::max(0,j-k)],suf[j+k])+sm[i][j+k-1]-sm[i][j-1];
            FOR(k,std::max(1,j-::k+1),std::min(m-::k+1,j+::k-1)){ // [k,k+]
                int l = std::min(k,j),r = std::max(k+::k-1,j+::k-1);
                f[now][j] = std::max(f[now][j],f[now^1][k]+sm[i][r]-sm[i][l-1]);
            }
        }
    }
    int ans = 0;
    FOR(i,1,m) ans = std::max(ans,f[now][i]);
    printf("%d\n",ans);
    return 0;
}
/*
 * f[i][j]   i   i%2   j
 * f[i][j] = f[i-1][k]+cost(j,k)
 * [j,j+l-1] [k,k+l-1]  
 * O(nm^2)
*/