#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    int m = *max_element(a.begin(), a.end());
    vector<int> cnt(m + 1);
    for (int x : a) cnt[x]++;

    vector<int> cnt_mult(m + 1);
    for (int i = 1; i <= m; i++) {
        for (int j = i; j <= m; j += i) {
            cnt_mult[i] += cnt[j];
        }
    }

    vector<bool> is_prime(m + 1, 1);
    vector<int> primes;
    for (int i = 2; i <= m; i++) if (is_prime[i]) {
        primes.push_back(i);
        for (int j = 2 * i; j <= m; j += i) {
            is_prime[j] = 0;
        }
    }


    vector<ll> dp(m + 1);
    for (int i = m; i >= 1; i--) {
        dp[i] = (long long) cnt_mult[i] * i;
        for (int x : primes) {
            int j = x * i;
            if (j > m) break;
            dp[i] = max(dp[i], dp[j] + (long long) (cnt_mult[i] - cnt_mult[j]) * i);
        }
    }
    cout << dp[1] << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}