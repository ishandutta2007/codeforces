#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;
 
const int inf = 1e15;
const int mod = 1e9 + 7;
const int max_k = 5e3 + 4;

int n, k;
int dp[max_k][max_k];

int binpow(int a, int b) {
    int res = 1;
    for(;b > 0;b /= 2, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

void solve() {
    cin >> n >> k;

    for(int a = 0;a <= k;a++) {
        for(int b = 0;b <= k;b++) {
            int c = n - b;
            if (a == 0) {
                dp[a][b] = binpow(2, c);
                continue;
            }
            if (b == 0)
                dp[a][b] = c * dp[a - 1][b + 1] % mod;
            else
                dp[a][b] = (b * dp[a - 1][b] + c * dp[a - 1][b + 1]) % mod;
        }
    }

    cout << dp[k][0];
}



signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}