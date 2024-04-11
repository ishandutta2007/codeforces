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
const int N = 100 + 5;
const int S = 9*N + 5;

int n, m, k, a[N][N];
bitset<S> dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m >> k; k++;
    vector<string> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = v[i][j] - '0';
        }
    }

    for (int j = 0; j < m; j++)
        dp[n - 1][j] = (1 << a[n - 1][j]);

    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (j - 1 >= 0)
                dp[i][j] |= (dp[i + 1][j - 1] << a[i][j]);
            if (j + 1 < m)
                dp[i][j] |= (dp[i + 1][j + 1] << a[i][j]);
        }
    }

    int best = -1, besti = -1;
    for (int sum = 0; sum < S; sum += k) {
        for (int j = 0; j < m; j++) {
            if (dp[0][j][sum])
                best = sum, besti = j;
        }
    }

    if (best == -1) {
        cout << "-1\n";
        return 0;
    }

    string s;
    int j = besti, sum = best;

    for (int i = 0; i < n - 1; i++) {
        sum -= a[i][j];
        if (j - 1 >= 0 and dp[i + 1][j - 1][sum])
            s += 'R', j--;
        else if (j + 1 < m and dp[i + 1][j + 1][sum])
            s += 'L', j++;
    }

    reverse(all(s));
    cout << best << "\n" << j + 1 << "\n";
    cout << s << "\n";
    return 0;
}