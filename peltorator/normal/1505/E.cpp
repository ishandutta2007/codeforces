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

string s[100];

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int m;
    cin >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int ans = 0;
    if (s[0][0] == '*') {
        ans++;
    }
    int x = 0, y = 0;
    while (true) {
        int len = 1e9, xx = -1, yy = -1;
        for (int i = x; i < n; i++) {
            for (int j = y; j < m; j++) {
                if (i != x || j != y) {
                    if (s[i][j] == '*') {
                        int l1 = i - x + j - y;
                        if (l1 < len || (l1 == len && i < xx)) {
                            len = l1;
                            xx = i;
                            yy = j;
                        }
                    }
                }
            }
        }
        if (xx == -1) {
            break;
        }
        x = xx;
        y = yy;
        ans++;
    }
    cout << ans << endl;
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