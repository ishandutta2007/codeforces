#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;

const ll INF = 4e18;
const int INFi = 2e9;
const int maxN = 5000 + 5;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    ll h, c, t;
    cin >> h >> c >> t;

    if (t <= (h + c) / 2) {
        cout << 2 << "\n";
        return;
    }

    ll x = - (h - t) / (c + h - 2 * t);

    auto get = [&](ll y) {
        return (ld) ((y + 1) * h + y * c) / ((ld) (2 * y + 1));
    };

    if (abs(get(x) - t) > abs(get(x + 1) - t)) {
        cout << 2 * (x + 1) + 1 << "\n";
    } else {
        cout << 2 * x + 1 << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}