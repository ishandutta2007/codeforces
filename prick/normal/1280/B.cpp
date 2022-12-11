#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <iomanip>

using namespace std;

#define sz(x) ((int) (x).size())

void solve() {
    int r, c;
    cin >> r >> c;
    vector<string> a(r);
    for (int i = 0; i < r; ++i) {
        cin >> a[i];
    }
    int cnt = 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (a[i][j] == 'A') {
                ++cnt;
            }
        }
    }
    if (cnt == 0) {
        cout << "MORTAL\n";
        return;
    }
    if (cnt == r * c) {
        cout << 0 << '\n';
        return;
    }
    int ans = 100500;
    for (int it = 0; it < 2; ++it) {
        for (int i = 0; i < r; ++i) {
            vector<int> pref(c + 1);
            for (int j = 0; j < c; ++j) {
                pref[j + 1] = pref[j];
                if (a[i][j] == 'P') {
                    ++pref[j + 1];
                }
            }
            for (int j = 0; j < c; ++j) {
                if (a[i][j] == 'A') {
                    int t = 0;
                    if (pref[j + 1] != 0) ++t;
                    if (pref[j + 1] != pref[c]) ++t;
                    if (i > 0) ++t;
                    if (i < r - 1) ++t;
                    ans = min(ans, t);
                }
            }
        }
        vector<string> b(c, string(r, '.'));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                b[j][i] = a[i][j];
            }
        }
        a = b;
        swap(r, c);
    }
    cout << ans << '\n';
}

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        solve();
    }
}