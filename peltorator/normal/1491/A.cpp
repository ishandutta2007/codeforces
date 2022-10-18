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
    int q;
    cin >> q;
    int zer = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            zer++;
        }
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            x--;
            if (a[x] == 1) {
                zer++;
            } else {
                zer--;
            }
            a[x] = 1 - a[x];
        } else {
            int k;
            cin >> k;
            int ones = n - zer;
            if (ones >= k) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        }
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