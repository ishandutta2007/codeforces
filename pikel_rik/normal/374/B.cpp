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
const int N = 1e5 + 5;

int n, dp[N];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    n = s.length();

    ll ans = 1;
    int c = 0;

    for (int i = 1; i < n; i++) {
        if (s[i] - '0' + s[i - 1] - '0' == 9)
            c++;
        else if (c % 2 == 0)
            ans *= c / 2 + 1, c = 0;
        else c = 0;
    }

    if (c % 2 == 0)
        ans *= c / 2 + 1;

    cout << ans << "\n";
    return 0;
}