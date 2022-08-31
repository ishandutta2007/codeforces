#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;
    ll ans = 0;
    ll cur = 0;
    range(i, n) {
        ll x; cin >> x;
        cur += x;
        ll d = cur / k;
        if (d == 0 && cur != x) d = 1;
        ans += d;
        cur -= d * k;
        cur = max(cur, 0ll);
    }
    if (cur) ans++;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}