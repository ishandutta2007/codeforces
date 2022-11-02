#include <bits/stdc++.h>

using namespace std;

#define int long long
#define double long double
#define mod 1000000007ll
#define INF 1000000000000000000ll

int ta[1000010],
    tb[1000010];

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, a, b, k;
    cin >> n >> m >> a >> b >> k;

    if (k >= n || k >= m) {
        cout << -1;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> ta[i];
        ta[i] += a;
    }

    for (int i = 1; i <= m; i++) {
        cin >> tb[i];
    }

    int gdzie = 1;

    int res = 0;

    for (int i = 0; i <= k; i++) {
        while (gdzie <= m && tb[gdzie] < ta[i+1]) {
            gdzie++;
        }

        if (gdzie + k - i > m) {
            cout << -1;
            return 0;
        }

        res = max(res, tb[gdzie + k - i]);
    }

    cout << res+b;

    return 0;
}
/*

*/