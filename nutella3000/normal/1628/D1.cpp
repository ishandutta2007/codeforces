#include<bits/stdc++.h>
using namespace std;
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& a, int b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(int& a, int b){ if(a < b){ a = b; return 1; } return 0; }



mt19937 Rand(time(0));
int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 5e9 + 7, mod = 1e9 + 7;
const int N = (1 << 18);

int bp(int a, int b) {
    int r = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) r = r * a % mod;
    return r;
}

int inv(int a) { return bp(a, mod-2); }

void run() {
    int n, m, k; cin >> n >> m >> k;
    vector<vector<int>> dp(n+1, vector<int>(n+1, inf));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = dp[i-1][0];
        for (int j = 1; j <= i; ++j) {
            // dp[i][j] = min(dp[i-1][j-1]+d, dp[i-1][j]-d)
            int d = (dp[i-1][j] - dp[i-1][j-1]+mod)%mod;
            if (dp[i-1][j] == inf) d = 2*k;
            dp[i][j] = (dp[i-1][j-1] + d*inv(2)) % mod;
        }
    }
    cout << dp[n][m] << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}