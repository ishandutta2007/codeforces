#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e6 + 5;

int n, m;
vector<string> a;
vector<vector<int>> dp, states;

int cost(int i, int mask) {
    int c = 0;
    for (int j = 0; j < n; j++) {
        if (a[j][i] == '1' and !(mask & (1 << j)))
            c++;
        else if (a[j][i] == '0' and (mask & (1 << j)))
            c++;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n >= 4 and m >= 4) {
        cout << "-1\n";
        return 0;
    }

    if (n == 1 or m == 1) {
        cout << "0\n";
        return 0;
    }

    if (n > m) {
        vector<string> b(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                b[j] += a[i][j];
            }
        }
        a = b;
        swap(n, m);
    }

    dp = vector<vector<int>>(m, vector<int>(1 << n));
    states = vector<vector<int>>(1 << n);

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            bool ok = true;
            for (int k = 0; k < n - 1; k++) {
                int c = 0;
                for (int p = 0; p < 2; p++) {
                    c += ((i & (1 << (p + k))) > 0);
                    c += ((j & (1 << (p + k))) > 0);
                }
                ok &= (c & 1);
            }
            if (ok)
                states[i].push_back(j);
        }
        dp[0][i] = cost(0, i);
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = INT_MAX;
            int temp = cost(i, j);

            for (int k : states[j]) {
                dp[i][j] = min(dp[i][j], temp + dp[i - 1][k]);
            }
        }
    }

    int ans = INT_MAX;
    for (int j = 0; j < (1 << n); j++) {
        ans = min(ans, dp[m - 1][j]);
    }

    cout << ans << "\n";
    return 0;
}