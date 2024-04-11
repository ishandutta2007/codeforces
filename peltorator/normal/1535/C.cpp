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
    string s;
    cin >> s;
    int n = sz(s);
    vector<vector<int>> pos(2, vector<int>(2, n));
    int fin = n;
    ll ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] != '?') {
            int dig = s[i] - '0';
            int par = i % 2;
            fin = min(pos[dig ^ 1][par], pos[dig][par ^ 1]);
            pos[dig][par] = i;
        }
        ans += fin - i;
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