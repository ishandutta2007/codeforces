#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

int n, m, dp[2][N], pref[N];
string s, t;

vector<int> computeLps() {
    vector<int> lps(m);

    int i = 1, len = 0;
    lps[0] = 0;

    while (i < m) {
        if (t[i] == t[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s >> t;
    n = s.length();
    m = t.length();

    vector<int> lps = computeLps();
    vector<int> matches;

    int i = 0, j = 0;

    while (i < n) {
        if (s[i] == t[j]) {
            i++;
            j++;
        }

        if (j == m) {
            matches.push_back(i - j);
            j = lps[j - 1];
        }

        else if (i < n and s[i] != t[j]) {
            if (j != 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }

    if (matches.empty()) {
        cout << "0\n";
        return 0;
    }

    dp[1][n-1] = (matches.back() == n - 1 ? 1 : 0);
    pref[n-1] = dp[1][n-1];

    for (int i = n - 2; i >= 0; i--) {
        dp[0][i] = (dp[1][i + 1] + dp[0][i + 1]) % mod;
        if (!binary_search(all(matches), i))
            dp[1][i] = dp[1][i + 1];
        else dp[1][i] = (n - i - m + 1 + pref[i + m]) % mod;
        pref[i] = (pref[i+1] + (ll)dp[0][i] + dp[1][i]) % mod;
    }

    cout << (dp[0][0] + dp[1][0]) % mod << "\n";
    return 0;
}