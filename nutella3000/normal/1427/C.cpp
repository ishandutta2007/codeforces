#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;

const int inf = 1e15;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int r, n;
    cin >> r >> n;

    n++;
    vector<int> t(n), x(n), y(n), dp(n, -inf);

    x[0] = 1;
    y[0] = 1;
    dp[0] = 0;


    for(int i = 1;i < n;i++) {
        cin >> t[i] >> x[i] >> y[i];

        for(int j = i - 1;j >= max(0ll, i - 2020);j--) {
            if (abs(x[j] - x[i]) + abs(y[j] - y[i]) <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }

    int res = 0;
    for(int i : dp)
        res = max(res, i);
    cout << res;
}