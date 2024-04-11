#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 2501;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    range(i, n) cin >> a[i];
    range(i, m) cin >> b[i];
    vector<ll> f(m - n + 1);
    ll s1 = 0;
    range(i, n) {
        if (i & 1) s1 -= a[i];
        else s1 += a[i];
    }
    ll s2 = 0;
    range(i, n) {
        if (i & 1) s2 += b[i];
        else s2 -= b[i];
    }
    f[0] = s1 + s2;
    for (int i = n; i < m; ++i) {
        s2 += b[i - n];
        s2 = -s2;
        if (n & 1) {
            s2 -= b[i];
        } else {
            s2 += b[i];
        }
        f[i - n + 1] = s1 + s2;
    }
    sort(all(f));
    ll w = 0;

    auto get = [&w, &f]() {
        int lb = lower_bound(all(f), w) - f.begin();
        ll res = INF;
        if (lb != f.size()) {
            res = f[lb] - w;
        }
        if (lb != 0) {
            res = min(res, w - f[lb - 1]);
        }
        return res;
    };
    cout << get() << "\n";
    range(_, q) {
        int l, r, x;
        cin >> l >> r >> x;
        if ((r - l + 1) & 1) {
            if (l & 1) w -= x;
            else w += x;
        }
        cout << get() << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}