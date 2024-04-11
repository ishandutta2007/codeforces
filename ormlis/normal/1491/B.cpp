#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

const int INFi = 2e9 + 5;
const int maxN = 3e5 + 100;
const int md = 1e9 + 7;
const ll INF = 2e18;

void solve() {
    int n, u, v; cin >> n >> u >> v;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    int ans = min(v, u) + v;
    range(i, n - 1) {
        if (a[i + 1] != a[i]) ans = min(u, v);
    }
    range(i, n - 1) {
        if (abs(a[i + 1] - a[i]) > 1) {
            cout << "0\n";
            return;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}