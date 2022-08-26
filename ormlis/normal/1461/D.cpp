#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;

using namespace std;

const ll INF = 2e18 + 5;
const int INFi = 1e8;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;

void solve() {
    int n, q; cin >> n >> q;
    set<ll> was;
    vector<int> a(n);
    range(i, n) cin >> a[i];
    function<void(int, int)> solve = [&] (int l, int r) {
        if (a[r - 1] == a[l]) {
            was.insert(1ll * a[l] * (r - l));
            return;
        }
        int x = (a[r - 1] + a[l]) / 2;
        int kek = -1;
        ll s = 0;
        for(int i = l; i < r; ++i) {
            s += a[i];
            if (a[i] > x && kek == -1) {
                kek = i;
            }
        }
        was.insert(s);
        solve(l, kek);
        solve(kek, r);
    };
    sort(all(a));
    solve(0, n);
    range(_, q) {
        ll s; cin >> s;
        if (was.count(s)) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}