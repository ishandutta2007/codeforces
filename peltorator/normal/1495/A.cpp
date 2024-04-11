#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "========" << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(239);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<ll> xs, ys;
    for (int i = 0; i < 2 * n; i++) {
        ll x, y;
        cin >> x >> y;
        if (x == 0) {
            ys.push_back(abs(y));
        } else {
            xs.push_back(abs(x));
        }
    }
    sort(xs.begin(), xs.end());
    sort(ys.begin(), ys.end());
    ld ans = 0;
    for (int i = 0; i < n; i++) {
        ans += sqrtl((ld)(xs[i] * xs[i] + ys[i] * ys[i]));
    }
    cout << fixed << setprecision(30);
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}