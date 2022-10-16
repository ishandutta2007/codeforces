#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
void solve()
{
    int n, k; cin >> n >> k;
    vector<int> a(n), d(n);
    for (int &i: a) cin >> i;
    for (int &i: d) cin >> i;

    if (k == 0) {
        // try everything
        ll ans = 0, cur = 0;
        for (int i = n-1; i >= 0; i--) {
            cur += a[i];
            ans = max(ans, cur - d[i]);
        }
        cout << ans << '\n';
    } else if (k == 1) {
        // try for k = 0 except can't excite 1
        ll ans = 0, cur = 0;
        for (int i = n-1; i >= 1; i--) {
            cur += a[i];
            ans = max(ans, cur - d[i]);

            if (a[0] > d[0]) ans = max(ans, cur - d[i] + a[0] - d[0]);
        }

        // skip exactly one index
        ll sumai = 0;
        for (int i: a) sumai += i;

        for (int i = 1; i < n; i++) {
            // if skip last index, cost = min of first n-1
            // if not last index, cost = d[1]
            ll tmp = 0;
            if (i == n-1) {
                int mincost = *min_element(d.begin(), d.end()-1);
                tmp = sumai - a[i] - mincost;
            } else {
                tmp = sumai - a[i] - d[0];
            }

            // if activate skipped gives profit, do it
            if ((a[i] - d[i]) > 0) tmp += a[i] - d[i];

            ans = max(ans, tmp);
        }
        sort(d.begin(), d.end());
        ans = max(ans, sumai - d[0] - d[1]);
        cout << ans << '\n';
    } else {
        // smallest cost in first n-1 indices
        ll ans = 0;
        for (int i: a) ans += i;
        ans -= *min_element(d.begin(), d.end()-1);

        // only activate last
        ans = max(ans, (long long)a[n-1] - d[n-1]);

        cout << max(0LL, ans) << '\n';
    }
}

/*
5 1
50 1 3 5 6
1000 1 1 1 3
*/

signed main()
{
    fastio;

    int testcase = 1;
    //cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}