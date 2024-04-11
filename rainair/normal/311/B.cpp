/*
 * Author: RainAir
 * Time: 2019-08-07 09:37:00
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
#define int LL
const int MAXN = 2e5 + 5;
int d[MAXN],h[MAXN],t[MAXN];
int pre[MAXN],a[MAXN],sm[MAXN];
int n,m,p;
//LL f[1005][1005],g[MAXN][323];
LL f[2][MAXN];
//LL f[1000][1000];
int now;

#define Y(i) (f[now^1][i]+sm[i])
#define X(i) (i)

inline bool headpop(int a,int b,int x){
//   return Y(b) - Y(a) <= 2 * sum[x] * (X(b) - X(a));
    return Y(b) - Y(a) <= ::a[x]*(X(b)-X(a));
}
 
inline bool tailpop(int a,int b,int c){
    return (Y(b) - Y(a)) * (X(c) - X(b)) >= (Y(c) - Y(b)) * (X(b) - X(a));
}
 
int q[MAXN],head,tail;
signed main(){
 //   freopen("gg.in","r",stdin);
    scanf("%lld%lld%lld",&n,&m,&p);
    FOR(i,2,n) scanf("%lld",d+i);
    FOR(i,1,m) scanf("%lld%lld",h+i,t+i);
    FOR(i,2,n) pre[i] = pre[i-1]+d[i];
    FOR(i,1,m) a[i] = t[i]-pre[h[i]];
    std::sort(a+1,a+m+1);
    FOR(i,1,m) sm[i] = sm[i-1]+a[i];
    FOR(i,1,m) f[now][i] = 1e18,f[now^1][i] = 1e18;
    FOR(j,1,p){
        q[head = tail = 0] = 0;
        FOR(i,1,m){
            while(head < tail && headpop(q[head],q[head+1],i)) head++;
            LL c = i*a[i]-sm[i];int k = q[head];
            LL gx = 1ll*f[now^1][k]+sm[k]-k*a[i]+c;
            f[now][i] = gx;
            while(head < tail && tailpop(q[tail-1],q[tail],i)) tail--;
            q[++tail] = i;
          /*  FOR(k,0,i-1){
                LL c = i*a[i]-sm[i];
                LL gx = 1ll*f[now^1][k]+sm[k]-k*a[i]+c;
                f[now][i] = std::min(f[now][i],gx);
            }*/
        }
        now ^= 1;
    }
    printf("%lld\n",f[now^1][m]);
    return 0;
}