#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))

using namespace std;
typedef long long ll;

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll &val : a) {
        cin >> val;
    }
    sort(a.rbegin(), a.rend());
    ll cursum = 0;
    int ans = 0;
    if (a[0] == a.back()) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        while (cursum - i * a[i] > k) {
            // h : cursum - i * h <= k      cursum - k <= i * h        ceil((cursum - k) / i) <= h
            ll h = (cursum - k - 1) / i + 1;
            cursum = h * i;
            ans++;
        }
        if (i == n - 1) {
            cout << ans + 1 << endl;
            return 0;
        }
        cursum += a[i];
    }
}