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
#define P std::pair<LL,LL>
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
int a[MAXN],b[MAXN],n;
int f[MAXN][2];

signed main(){
    scanf("%lld",&n);
    FOR(i,1,n) scanf("%lld",a+i);int t = 0;
    for(int i = 1;i <= n;i+=2) b[++t] = a[i];
    for(int i = 2;i <= n;i += 2) b[++t] = a[i];
    FOR(i,1,n) b[i] += b[i-1];
    int ans = 0;
    FOR(i,(n+1)/2,n){
        ans = std::max(ans,b[i]-b[i-(n+1)/2]);
    }
    FOR(i,1,(n+1)/2-1){
        ans = std::max(ans,b[i]+b[n]-b[n-((n+1)/2-i)]);
    }
    printf("%lld\n",ans);
    return 0;
}