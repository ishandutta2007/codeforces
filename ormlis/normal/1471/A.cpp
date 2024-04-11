#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()

typedef long long ll;

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    ll ans = (accumulate(all(a), 0ll) + x - 1) / x;
    ll ans2 = 0;
    range(i, n) ans2 += (a[i] + x - 1) / x;
    cout << ans << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}