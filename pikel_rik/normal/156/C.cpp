#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e2 + 5;

int n, dp[N][25*N + 1];
string s;

int recurse(int pos, int sum) {
    if (sum < 0 or sum > (pos + 1) * 25)
        return 0;

    if (sum == 0 or sum == (pos + 1) * 25 or pos == 0)
        return 1;

    if (dp[pos][sum] != -1)
        return dp[pos][sum];

    int ans = 0;
    for (int i = 0; i < 26; i++)
        ans = (ans + recurse(pos - 1, sum - i)) % mod;

    return dp[pos][sum] = ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int t;
    cin >> t;

    memset(dp, -1, sizeof(dp));

    while (t--) {
        cin >> s;
        n = s.length();

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            a[i] = s[i] - 'a';

        int sum = accumulate(all(a), 0);
        cout << recurse(n - 1, sum) - 1 << "\n";
    }
    return 0;
}