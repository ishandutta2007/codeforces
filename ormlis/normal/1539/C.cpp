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
const int INFi = 2e9;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;

void solve() {
    int n;
    ll k, x; cin >> n >> k >> x;
    vector<ll> a(n);
    range(i, n) cin >> a[i];
    sort(all(a));
    int ans = 1;
    vector<ll> can;
    for(int i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > x) {
            can.emplace_back((a[i] - a[i - 1] - 1) / x);
            ans++;
        }
    }
    sort(all(can));
    for(auto &w : can) {
        if (w > k) break;
        k -= w;
        ans--;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}