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
    int k;
    cin >> k;
    vector<int> used(2 * n, 0);
    vector<int> x, y;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        x.push_back(a);
        y.push_back(b);
        used[a] = used[b] = 1;
    }
    vector<int> free;
    for (int i = 0; i < 2 * n; i++) {
        if (!used[i]) {
            free.push_back(i);
        }
    }
    for (int i = 0; i < n - k; i++) {
        x.push_back(free[i]);
        y.push_back(free[n - k + i]);
    }
    for (int i = 0; i < n; i++) {
        if (x[i] > y[i]) {
            swap(x[i], y[i]);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int A = i, B = j;
            if (x[i] > x[j]) {
                swap(A, B);
            }
            if (y[A] > x[B] && y[A] < y[B]) {
                ans++;
            }
        }
    }
    cout << ans << '\n';
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