#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()

typedef long long ll;

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    bool f = false;
    ll ans = 0;
    for(ll y = 1; !f; y *= x) {
        range(i, n) {
            if (a[i] % y) {
                f = true;
                break;
            }
            ans += a[i];
        }
    }
    cout << ans << '\n';
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