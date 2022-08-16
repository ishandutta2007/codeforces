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
const int N = 500 + 5;

int n, k, dp[N][N], cost[N][N];
string s;

void convert(int l, int r) {
    for (int i = 0; i < (r - l + 1) / 2; i++) {
        s[l + i] = s[r - i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> k;
    n = s.length();

    for (int l = 0; l < n; l++) {
        for (int r = l; r < n; r++) {
            int ans = 0;
            for (int i = 0; i < (r - l + 1) / 2; i++) {
                ans += s[l + i] != s[r - i];
            }
            cost[l][r] = ans;
        }
    }

    for (int i = 0; i < n; i++)
        dp[i][1] = cost[0][i];

    for (int no = 2; no <= k; no++) {
        for (int i = n - 1; i >= no - 1; i--) {
            dp[i][no] = INT_MAX;
            for (int j = i; j >= no - 1; j--) {
                dp[i][no] = min(dp[i][no], cost[j][i] + dp[j - 1][no - 1]);
            }
        }
    }

    int best = k;
    for (int i = 1; i < k; i++) {
        if (dp[n - 1][i] < dp[n - 1][best])
            best = i;
    }

    int i = n - 1, no = best;
    vector<pair<int, int>> ans;

    while (no > 1) {
        for (int j = i; j >= no - 1; j--) {
            if (dp[i][no] == cost[j][i] + (j ? dp[j - 1][no - 1] : 0)) {
                ans.emplace_back(j, i);
                convert(j, i);
                i = j - 1;
                no--;
                break;
            }
        }
    }

    convert(0, i);
    reverse(all(ans));

    cout << dp[n - 1][best] << "\n";

    cout << s.substr(0, i + 1);
    for (auto &[i, j] : ans) {
        cout << '+';
        cout << s.substr(i, j - i + 1);
    }
    return 0;
}