#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

bool mini(auto& x, const auto& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

bool maxi(auto& x, const auto& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = 1005;

vector<ll> what[N];
ll dp[N];

void run() {
    ll n, m;
    cin >> n >> m;
    if (m == 1) {
        cout << n * n << "\n";
        return;
    }
    ll ans = 0;
    for (ll x = 0; x < m; x++) {
        what[(x * x) % m].push_back(x);
    }
    for (ll x = 0; x < m; x++) {
        for (ll t : what[x]) {
            if (t == 0) {
                t += m;
            }
            ll w = n - t;
            if (w >= 0) {
                ll k = w / m;
                dp[x] += k + 1;
            }
        }
    }
    for (ll x = 0; x < m; x++) {
        ll y = (m - x) % m;
        ans += dp[x] * dp[y];
    }
    cout << ans << "\n";
}