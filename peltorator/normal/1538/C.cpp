#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
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
    ll l, r;
    cin >> l >> r;
    vector<ll> a(n);
    for (ll &val : a) {
        cin >> val;
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int lb = lower_bound(a.begin(), a.end(), l - a[i]) - a.begin();
        int rb = lower_bound(a.begin(), a.end(), r - a[i] + 1) - a.begin();
        rb = min(rb, i);
        lb = min(lb, i);
        if (lb < rb) {
            ans += rb - lb;
        }
    }
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
        #ifdef ONPC
            cout << "__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}