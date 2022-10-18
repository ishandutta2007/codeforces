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
    if (!(cin >> n)) {
        return 1;
    }
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> a[i][j];
        }
    }
    auto cmp = [&](int x, int y) {
        int cnt = 0;
        for (int i = 0; i < 5; i++) {
            if (a[x][i] < a[y][i]) {
                cnt++;
            }
        }
        return cnt >= 3;
    };
    vector<int> q;
    for (int i = 0; i < n; i++) {
        q.push_back(i);
    }
    while (sz(q) > 1) {
        int x = q.back();
        q.pop_back();
        if (cmp(x, q.back())) {
            q.back() = x;
        }
    }
    for (int i = 0; i < n; i++) {
        if (i != q[0] && cmp(i, q[0])) {
            cout << -1 << '\n';
            return 0;
        }
    }
    cout << q[0] + 1 << '\n';
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