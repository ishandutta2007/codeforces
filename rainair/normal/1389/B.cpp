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
#define int LL
const int MAXN = 2e5 + 5;
int a[MAXN],n,k,z;
int f[MAXN][10];

inline void upd(int &x,int y){
    if(x < y) x = y;
}

signed main(){
    int T;scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&k,&z);
        FOR(i,1,n) scanf("%lld",a+i);
        FOR(i,0,k+1) FOR(j,0,z+1) f[i][j] = -1e18;
        f[0][0] = a[1];
        FOR(i,0,k){
            FOR(j,0,z){
                if(f[i][j] == -1e18) continue;
                int pos = 1+i-j;if(pos > n) continue;
                if(pos+1<=n) upd(f[i+1][j],f[i][j]+a[pos+1]);
                if(pos-1>=1) upd(f[i][j+1],f[i][j]+a[pos-1]);
            }
        }
        int ans = -1e18;
        FOR(i,0,k) FOR(j,0,z) if(i+j <= k) upd(ans,f[i][j]);
        printf("%lld\n",ans);
    }
    return 0;
}