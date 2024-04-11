#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ordered_set = tree<int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;

int n, dp[26][26];
string a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = n - 1; i >= 0; i--) {
        char ch1 = a[i].front(), ch2 = a[i].back();

        for (int j = 0; j < 26; j++) {
            if (dp[ch2 - 'a'][j] > 0)
                dp[ch1 - 'a'][j] = max((int)a[i].length() + dp[ch2 - 'a'][j], dp[ch1 - 'a'][j]);
        }
        dp[ch1 - 'a'][ch2 - 'a'] = max(dp[ch1 - 'a'][ch2 - 'a'], (int)a[i].length());
    }

    int best = 0;
    for (int i = 0; i < 26; i++) best = max(best, dp[i][i]);

    cout << best << "\n";
    return 0;
}