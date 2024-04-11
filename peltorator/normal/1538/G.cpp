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

const ll INF = 1e18;

int solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a == b) {
        cout << min(x, y) / a << '\n';
        return 0;
    }
    ll l = 0, r = x + 1;
    if (a < b) {
        swap(a, b);
    }
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll LB = -INF;
        ll RB = INF;

        ll up = x - m * b;
        ll down = a - b;
        if (up < 0) {
            RB = -1;
        } else {
            RB = up / down;
        }

        ll up2 = m * a - y;
        ll down2 = a - b;
        if (up2 < 0) {
            LB = 0;
        } else {
            LB = (up2 + down2 - 1) / down2;
        }


        if (RB >= LB && LB <= m) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';
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