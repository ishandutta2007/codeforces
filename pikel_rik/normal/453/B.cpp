#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T, typename comp = less<>> using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int fact[61], dp[101][1 << 17], back[101][1 << 17];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 1; i <= 100; i++) {
        for (int j = 0; j < (1 << 17); j++)
            dp[i][j] = inf;
    }

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
    for (int i = 1; i < 60; i++) {
        for (int j = 0; j < p.size(); j++) {
            if (i % p[j] == 0)
                fact[i] |= (1 << j);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k < 60; k++) {
            int x = (~fact[k]) & ((1 << 17) - 1);
            for (int s = x;; s = (s - 1) & x) {
                if (dp[i - 1][s] + abs(a[i] - k) < dp[i][s | fact[k]]) {
                    dp[i][s | fact[k]] = dp[i - 1][s] + abs(a[i] - k);
                    back[i][s | fact[k]] = k;
                }
                if (s == 0) break;
            }
        }
    }

    vector<int> ans;
    int ptr = n, mask = min_element(dp[n], dp[n] + (1 << 17)) - dp[n];

    while (ptr > 0) {
        ans.push_back(back[ptr][mask]);
        mask ^= fact[back[ptr][mask]];
        ptr--;
    }

    reverse(all(ans));
    for (int i : ans) cout << i << " ";
    return 0;
}