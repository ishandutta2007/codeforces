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
    vector<int> arr(n);
    for (int &val : arr) {
        cin >> val;
    }
    map<int, int> q;
    for (int ms = 0; ms < (1 << n); ms++) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (((ms >> i) & 1)) {
                sum += arr[i];
            }
        }
        q[sum]++;
        if (q[sum] > 1) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
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