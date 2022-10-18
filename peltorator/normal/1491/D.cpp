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

vector<int> f(ll x) {
    vector<int> a;
    for (int i = 0; i < 35; i++) {
        a.push_back(x % 2);
        x /= 2;
    }
    for (int i = 1; i < sz(a); i++) {
        a[i] += a[i - 1];
    }
    return a;
}

ll st(ll x) {
    ll a = 0;
    while (x % 2 == 0) {
        a++;
        x /= 2;
    }
    return a;
}

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    while (n--) {
        ll u, v;
        cin >> u >> v;
        bool ok = true;
        vector<int> a = f(u), b = f(v);
        for (int i = 0; i < sz(a); i++) {
            if (a[i] < b[i]) {
                ok = false;
            }
        }
        if (u <= v && ok) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        /*
        if (u > v) {
            cout << "NO\n";
        } else {
            
            while (u % 2 == 0 && v % 2 == 0) {
                 u /= 2;
                 v /= 2;
            }
            if (u % 2 == 0) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
            }
        }
        */
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int TET = 1e9;
    //cin >> TET;
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