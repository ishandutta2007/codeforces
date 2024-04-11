#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3;
//const int max_n = 4e5 + 3;

void run() {
    int n, k;
    cin >> n >> k;
    int max_n = 2 * n + 4;
    vector<int> a(n);
    vector<pii> b(max_n), dp(max_n);

    auto unite = [](pii v1, pii v2) {
        vector<int> arr = {v1.fi, v1.se, v2.fi, v2.se};
        sort(all(arr));
        if (arr[2] == arr[3]) arr.pop_back();
        return mp(arr.back(), arr[size(arr) - 2]);
    };

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        b[a[i]] = unite(b[a[i]], mp(i + 1, 0));
    }

    int res = -inf;
    for (int i = 0; i < max_n; ++i) {
        dp[i] = b[i];
        for (int bit = 0; bit < 20; ++bit) {
            if (i >> bit & 1)
                dp[i] = unite(dp[i], dp[i ^ (1 << bit)]);
        }
        //cout << i << " " << dp[i].fi << " " << dp[i].se << endl;
        if (dp[i].se) chkmax(res, dp[i].fi * dp[i].se - k * i);
    }
    cout << res << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}