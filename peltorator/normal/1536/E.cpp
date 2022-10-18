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

const ll MOD = 1e9 + 7;

ll binpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = ans * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m;
    cin >> m;
    int empty = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '#') {
                empty++;
            }
        }
    }
    if (empty == n * m) {
        cout << binpow(2, empty) - 1 << '\n';
    } else {
        cout << binpow(2, empty) << '\n';
    }
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