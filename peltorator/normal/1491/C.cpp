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
    vector<ll> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<ll> v(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            v[i] += v[i - 1];
        }
        ll extra = max(0LL, v[i] - (s[i] - 1));
        if (i + 1 < n) {
            v[i + 1] += extra;
        }
        if (i + 2 < n) {
            v[i + 2] -= extra;
        }
        if (i + 2 < n) {
            v[i + 2]++;
        }
        if (i + s[i] + 1 < n) {
            v[i + s[i] + 1]--;
        }
        ans += max(0LL, (s[i] - 1) - v[i]);
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