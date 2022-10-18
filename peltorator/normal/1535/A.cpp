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
    vector<int> a(4);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.rbegin(), b.rend());
    int mi = 0;
    while (a[mi] != b[0]) {
        mi++;
    }
    int m2i = 0;
    while (a[m2i] != b[1]) {
        m2i++;
    }
    if (mi > 1) {
        swap(mi, m2i);
    }
    if (mi < 2 && m2i >= 2) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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