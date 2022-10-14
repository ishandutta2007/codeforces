#include <bits/stdc++.h>
using namespace std;
using lint = long long;
// #define TESTCASE
int solve();
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifdef TESTCASE
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}

const lint MOD = 998244353;

int solve() {

    int n;
    cin >> n;
    vector<lint> memo(n + 1, -1);
    auto fact = [&] (const auto& self, lint n) {
        if (n <= 1) {
            return 1ll;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        return memo[n] = (1ll * n * self(self, n - 1)) % MOD;
    };

    auto rec = [&](const auto& self, lint n) {
        if (n == 1) {
            return 1ll;
        }
        if (n == 2) {
            return 2ll;
        }
        return (1ll * n * (self(self, n - 1) + fact(fact, n - 1) - 1)) % MOD;
    };

    cout << rec(rec, n) << "\n";
    // vector<int> p(n);
    // int a = (n * (n - 1)) / 2;
    // iota(begin(p), end(p), 0);

    // vector<int> k;
    // do {
    //     for (auto i : p) {
    //         k.emplace_back(i);
    //     }
    // } while (next_permutation(begin(p), end(p)));

    // int ans = 0;
    // int sum = 0;
    // for (int i = 0; i < n; i++) {
    //     sum += k[i];
    // }
    // if (sum == a) ans++;
    // for (int i = n; i < k.size(); i++) {
    //     sum += k[i];
    //     sum -= k[i - n];
    //     if (sum == a) ans++;
    // }
    // cout << ans << "\n";

    // // for (auto i : k) {
    // //     cout << i << " ";
    // // }

}

/*
1 = 1
2 = 2 * 1 + 0
9 = 3 * 3 + 0
56 = 4 * 12 + 8
395 = 5 * 68 + 55 = (56 + 24 - 1) * 5
3084 = 6 * 463 + 306
26621 = 7 * 3547 + 1792
253280 = 8 * 30168 + 11846
2642391

n! of correct sums initially

k suffix, n - k prefix



*/