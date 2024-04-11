#ifdef ONPC
    #define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> free;
    vector<int> in(n, 0);
    for (int i = 0; i < n; i++) {
        free.insert(i);
        cin >> a[i];
        a[i]--;
        in[a[i]]++;
    }
    vector<int> b(n, -1);
    for (int i = 0; i < n; i++) {
        if (in[i] == 0 && free.count(a[i])) {
            b[i] = a[i];
            free.erase(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (free.count(a[i])) {
            b[i] = a[i];
            free.erase(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == -1 && free.count(i)) {
            free.erase(i);
            if (sz(free) == 0) {
                while (true);
            }
            b[i] = *free.begin();
            free.erase(free.begin());
            free.insert(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (b[i] == -1) {
            if (sz(free) == 0) {
                while (true);
            }
            b[i] = *free.begin();
            free.erase(free.begin());
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            ans++;
        }
    }
    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        cout << b[i] + 1 << ' ';
    }
    cout << '\n';
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
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