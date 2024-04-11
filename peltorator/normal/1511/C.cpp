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
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    vector<int> firstpos(51, -1);
    int q;
    cin >> q;
    for (int i = 0; i < n; i++) {
        int col;
        cin >> col;
        if (firstpos[col] == -1) {
            firstpos[col] = i;
        }
    }
    for (int i = 0; i < q; i++) {
        int col;
        cin >> col;
        cout << firstpos[col] + 1 << '\n';
        for (int j = 1; j <= 50; j++) {
            if (firstpos[j] != -1 && firstpos[j] < firstpos[col]) {
                firstpos[j]++;
            }
        }
        firstpos[col] = 0;
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