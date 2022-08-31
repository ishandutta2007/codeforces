#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>
 
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<climits>
 
#define oo            (int)13e7
#define s(n)          scanf("%d",&n)
#define sl(n)         scanf("%lld",&n)
#define sf(n)         scanf("%lf",&n)
#define fill(a,v)     memset(a, v, sizeof a)
#define ull           unsigned long long
#define ll            long long
#define bitcount      __builtin_popcount
#define all(x)        x.begin(), x.end()
#define pb( z )       push_back( z )
#define gcd           __gcd
using namespace std;

// 1 <= a0 < a1 < a2 < .. < ak <= n-2
const int mod = 1000000007;
inline int add(int x, int y) {
    int r = (x+y);
    if (r >= mod) r -= mod;
    return r;
}
inline int sub(int x, int y) {
    return add(x, mod - y);
}
int dp[1024][1024];
int solve(int ai, int k) {
    if (ai < 1) return 0;
    if (k == 0) return 1;
    int &res = dp[ai][k];
    if (~res) return res;
    int w1 = add( solve(ai-1, k), solve(ai-1, k) );
    w1 = sub(w1, solve(ai-2, k));
    res = add( w1, solve(ai-2, k-1) );
    return res;
}

int main(int argc, char** argv) {
	int n, m, _k;
    s(n); s(m); s(_k);
    fill(dp, -1);
    
    for (int k=0; k <= _k; k++)
    for (int ai=0; ai <= max(n, m); ai++) {
        int &res = dp[ai][k];
        if (ai < 1) {
            res = 0;
        } else if (k==0) {
            res = 1;
        } else {
            
            res = ai ? add( dp[ai-1][k], dp[ai-1][k] ) : 0;
            if (ai >= 2) {
                res = sub( res, dp[ai-2][k]);
                res = add( res, dp[ai-2][k-1] );
            }
        }
    }
    
    
    ll ans = dp[m][_k];//solve(m, k);
    ans = (ans * dp[n][_k] ) % mod;
    cout << ans << endl;
	return 0;
}