#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = (1 << 10), mod = 1e9 + 7;

int C[N][N];

int f(int n, int r, int z) {
    map<int, int> dp1, dp2;
    dp1[r] = 1;
    for (int bit = 60; bit >= 0; --bit) {
        bool bigInt = false;
        for (int i = (z >> bit & 1); i <= n; i += 2) {
            int val = i * (1ll<<bit);
            if (val > r) {
                bigInt = true;
                break;
            }

            for (auto j : dp1) {
                if (j.fi >= val) {
                    dp2[j.fi - val] += j.se * C[n][i] % mod;
                }
            }
        }
        for (auto& i : dp2)
            i.se %= mod;

        int sum = 0;
        while (!bigInt && siz(dp2) && dp2.rbegin()->fi >= n*(1ll << bit)) {
            sum += dp2.rbegin()->se;
            dp2.erase(--dp2.end());
        }
        if (sum != 0) {
            dp2[n*(1ll << bit)] = sum % mod;
        }

        dp1.clear();
        swap(dp1, dp2);
    }
    int res = 0;
    for (auto i : dp1)
        res += i.se;
    return res % mod;
}

void run() {
    int n, l, r, z; cin >> n >> l >> r >> z;

    C[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            C[i][j] = (C[i-1][j] + (j ? C[i-1][j-1] : 0)) % mod;
        }
    }

    cout << (f(n, r, z) - f(n, l-1, z) + mod) % mod << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}