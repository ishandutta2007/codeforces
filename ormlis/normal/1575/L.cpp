#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

void solve() {
    int n;
    cin >> n;
    const int INFi = 2e9;
    vi nvp(n + 1, INFi);
    vpi v;
    nvp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        if (i < x) continue;
        v.emplace_back(x, x - i);
    }
    sort(all(v));
    for(auto &[a, b] : v) {
        b = -b;
        (*upper_bound(all(nvp), b)) = b;
    }
    cout << (int) (lower_bound(all(nvp), INFi) - nvp.begin()) - 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}