#include <bits/stdc++.h>
using namespace std;
using lint = long long;
#define TESTCASE
int solve();
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
}




int solve() {

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        if (max(a[i - 1], a[i]) - min(a[i - 1], a[i]) >= 2) {
            cout << "YES\n";
            cout << i <<  " " << i + 1 << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    


}