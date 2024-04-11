#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define ll long long
#define pb push_back
#define ld long double

array<ll, 3> gcd(int a, int b) {
    if (b == 0) {
        return {1, 0, a};
    }
    auto g = gcd(b, a % b);
    ll x = g[1], y = g[0] - g[1] * (a / b);
    return {x, y, g[2]};
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n), b(n), arr, ans(n + 1);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sum += b[i];
        arr.pb(a[i] - b[i]);
    }
    sort(arr.rbegin(), arr.rend());
    ans[0] = sum;
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i - 1] + arr[i - 1];
    }
    int opt = 0;
    while (opt + 1 <= n && ans[opt] <= ans[opt + 1]) {
        opt++;
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        auto g = gcd(a, b);
        if (n % g[2] != 0) {
            cout << -1 << endl;
            continue;
        }
        ll res = -1;
        g[0] *= n / g[2], g[1] *= n / g[2];
        ll pos = g[0] * a, step = b / g[2] * a;
        if (pos <= opt) {
            ll cnt = (opt - pos) / step;
            pos += step * cnt;
        } else {
            ll cnt = (pos - opt) / step + 1;
            pos -= step * cnt;
        }
        for (auto cond : {pos, pos + step}) {
            if (cond >= 0 && cond <= n) {
                res = max(res, ans[cond]);
            }
        }
        cout << res << endl;
    }
    return 0;
}