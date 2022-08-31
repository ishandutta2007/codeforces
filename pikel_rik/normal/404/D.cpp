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
const int N = 1e6 + 5;

int n, dp[5][N];
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    n = s.length();

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i]))
            a[i] = s[i] - '0';
        else if (s[i] == '*') a[i] = 3;
        else a[i] = 4;
    }

    if (s[0] == '?') {
        dp[0][0] = dp[3][0] = 1;
        if (1 < n and (a[1] == 3 or a[1] == 4))
            dp[4][0] = 1;
    }
    else {
        if (a[0] != 1 and a[0] != 2)
            dp[a[0]][0] = 1;
        else if (a[0] == 1 and 1 < n and (a[1] == 3 or a[1] == 4))
            dp[4][0] = 1;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] == 0)
            dp[0][i] = (dp[1][i-1] + dp[0][i-1]) % mod;
        else if (a[i] == 1) {
            dp[1][i] = dp[3][i-1];
            if (i + 1 < n and (a[i+1] == 4 or a[i+1] == 3))
                dp[4][i] = (dp[0][i-1] + dp[1][i-1]) % mod;
        }
        else if (a[i] == 2) {
            if (i + 1 < n and (a[i+1] == 3 or a[i+1] == 4))
                dp[2][i] = dp[3][i-1];
        }
        else if (a[i] == 3)
            dp[3][i] = (dp[4][i-1] + (ll)dp[3][i-1] + dp[2][i-1]) % mod;
        else {
            dp[1][i] = dp[3][i-1];
            dp[0][i] = (dp[1][i-1] + dp[0][i-1]) % mod;
            dp[3][i] = (dp[4][i-1] + (ll)dp[3][i-1] + dp[2][i-1]) % mod;
            if (i + 1 < n and (a[i+1] == 3 or a[i+1] == 4)) {
                dp[2][i] = dp[3][i - 1];
                dp[4][i] = (dp[0][i-1] + dp[1][i-1]) % mod;
            }
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < 5; j++) {
//            cout << dp[j][i] << " ";
//        }
//        cout << "\n";
//    }

    cout << (dp[0][n-1] + (ll)dp[1][n-1] + dp[3][n-1]) % mod << "\n";
    return 0;
}