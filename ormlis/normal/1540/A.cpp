#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int n; cin >> n;
    vector<int> d(n);
    range(i, n) cin >> d[i];
    sort(all(d));
    ll ans = d.back();
    ll ts = 0;
    range(i, n) {
        ans += ts - 1ll * d[i] * i;
        ts += d[i];
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