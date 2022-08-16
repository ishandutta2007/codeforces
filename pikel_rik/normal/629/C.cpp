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
const int N = 2e3 + 5;

ll dp[N][N];
void precomp() {
    dp[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (j < i)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            if (j > 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
        }
    }
}

int n, m;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    precomp();
    cin >> n >> m >> s;

    int cnt = 0, mn = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == '(')
            cnt++;
        else cnt--;
        mn = min(mn, cnt);
    }

    ll ans = 0;
    for (int i = -mn; i <= n - m; i++) { //0
        for (int l = i; l <= n - m; l += 2) { // 0
            if (cnt + i < N)
                ans = (ans + dp[l][i] * dp[n - m - l][cnt + i] % mod) % mod;
//            cout << i << " " << l << " " << dp[l][i] << " " << dp[n - m - 1][cnt + i] << "\n";
        }
    }

    cout << ans << "\n";
    return 0;
}