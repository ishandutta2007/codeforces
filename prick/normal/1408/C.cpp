//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx2,tune=native")
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) (v).begin(), (v).end()
#define sz(a) ((ll)(a).size())
#define X first
#define Y second

using ll = long long;
using ull = unsigned long long;
using dbl = long double;

double f(const vector<int> &a, double time) {
    int cur = 0;
    double speed = 1;
    for (auto pos: a) {
        if (pos == 0) continue;
        if (cur + speed * time >= pos) {
            time -= (pos - cur) / speed;
            cur = pos;
            ++speed;
        } else {
            return cur + speed * time;
        }
    }
    return cur;
}

void solve() {
    int n, L;
    cin >> n >> L;
    vector<int> a(n + 2);
    a[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    a[n + 1] = L;
    auto rev = a;
    reverse(rev.begin(), rev.end());
    for (int i = 0; i < sz(rev); ++i) {
        rev[i] = L - rev[i];
    }
    double left = 0, right = L;
    for (int iter = 0; iter < 100; ++iter) {
        double mid = (left + right) / 2;
        if (f(a, mid) + f(rev, mid) >= L) {
            right = mid;
        } else {
            left = mid;
        }
    }
    cout << right << '\n';
}

signed main() {
#ifdef LOCAL
    assert(freopen("input.txt", "r", stdin));
    // assert(freopen("output.txt", "w", stdout));
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);

    int T = 1;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }

#ifdef LOCAL
    cout << endl << endl << "time = " << clock() / (double)CLOCKS_PER_SEC << endl;
#endif
}