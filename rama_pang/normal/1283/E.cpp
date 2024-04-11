#include <bits/stdc++.h>
using namespace std;
using lint = long long;
int solve();
// #define TESTCASE
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    #ifdef TESTCASE
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    #else
    solve();
    #endif
    return 0;
}

int solve() {
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(begin(a), end(a));

    map<int, int> mp;

    int mn = 0, mx = 0;

    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 0 && mp[a[i] + 1] == 0 && mp[a[i] - 1] == 0) {
            mn++;
            mp[a[i] + 1] = 1;
        }
    }
    mp.clear();
    for (int i = 0; i < n; i++) {
        if (mp[a[i]] == 0 || mp[a[i] + 1] == 0 || mp[a[i] - 1] == 0) {
            mx++;
            for (int j = -1; j <= 1; j++) {
                if (mp[a[i] + j] == 0) {
                    mp[a[i] + j] = 1;
                    break;
                }
            }
        }
    }

    cout << mn << " " << mx << "\n";
    

}