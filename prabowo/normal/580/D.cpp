#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <set>
#include <map>
#include <deque>
#include <vector>
#include <queue>
#include <stack>

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define MOD7 10000000007
#define INF 2000000000
#define INFLL 9000000000000000000LL
#define EPS 1e-7
#define pi acos(-1)
#define sqr(x) x*x
#define kevin using
#define keren namespace
#define abiez std
#define SYNC ios_base::sync_with_stdio(0)
#define lol ;
#define tulis cout <<
#define ok << endl

kevin keren abiez;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef vector<int> vi;
typedef vector<pii> vii;
//HARUS LONG LONG FUCK
LL n,m,k,arr[105],a,b,c,ans;
vector<pair<LL,LL> > vec[105];
LL asd[20][20];
LL dp[20][530000];
LL cari(LL last,LL bitmask) {
    if (__builtin_popcount(bitmask) == m) return arr[last];
    if (dp[last][bitmask] != -1) return dp[last][bitmask];
    LL &ret = dp[last][bitmask] = 0;
    for (int i=0;i<n;i++) {
        if (~bitmask & (1LL << i)) {
            ret = max(ret,cari(i,bitmask | (1LL << i)) + asd[last][i] + arr[last]);
        }
    }
    return ret;
}
int main() {
    SYNC;
    cin >> n >> m >> k;
    for (int i=0;i<n;i++) {
        cin >> arr[i];
    }
    for (int i=0;i<k;i++) {
        cin >> a >> b >> c;
        a--;b--;
        asd[a][b] = max(asd[a][b],c);
    }
    memset(dp,-1,sizeof(dp));
    ans = cari(19,0);
    cout << ans << endl;
}