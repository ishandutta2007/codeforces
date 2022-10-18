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
    ll u, v;
    cin >> u >> v;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = v + min(u, v);
    for (int i = 1; i < n; i++) {
        if (abs(a[i] - a[i - 1]) > 1) {
            cout << "0\n";
            return 0;
        }
        if (a[i] != a[i - 1]) {
            ans = min(u, v);
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
        cout << '\n';
        #ifdef ONPC
            cout << "\n__________________________" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}