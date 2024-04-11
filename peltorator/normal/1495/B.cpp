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
    vector<int> a(n);
    for (int &i : a) {
        cin >> i;
    }
    if (n == 2) {
        cout << "0\n";
        return 0;
    }
    vector<int> b;
    int cur = 2;
    for (int i = 2; i < n; i++) {
        bool lst = (a[i - 2] < a[i - 1]);
        bool th = (a[i - 1] < a[i]);
        if (th == lst) {
            cur++;
        } else {
            if (lst) {
                b.push_back(cur);
            } else {
                b.push_back(-cur);
            }
            cur = 2;
        }
    }
    if (a[n - 2] < a[n - 1]) {
        b.push_back(cur);
    } else {
        b.push_back(-cur);
    }

    int mx = 0;
    for (int i : b) {
        mx = max(mx, abs(i));
    }
    if (mx % 2 == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> poses;
    for (int i = 0; i < sz(b); i++) {
        if (abs(b[i]) == mx) {
            poses.push_back(i);
        }
    }
    if (sz(poses) != 2) {
        cout << 0 << '\n';
        return 0;
    }
    if (sz(poses) == 2 && (poses[1] != poses[0] + 1 || b[poses[0]] != mx)) {
        cout << 0 << '\n';
        return 0;
    }
    cout << 1 << '\n';
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