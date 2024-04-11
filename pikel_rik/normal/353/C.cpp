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

int n, a[N], pref[N], dp[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    string s;
    cin >> s;

    while (!s.empty() and s.back() == '0')
        s.pop_back();

    if (s.empty()) {
        cout << "0\n";
        return 0;
    }

    n = s.length();
    dp[0] = 0;

    if (s[0] == '1')
        dp[0] = a[0];

    pref[0] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i] = a[i] + pref[i-1];

        if (s[i] == '1')
            dp[i] = max(a[i] + dp[i - 1], pref[i - 1]);
        else dp[i] = dp[i-1];
    }

    cout << dp[n-1] << "\n";
    return 0;
}