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

    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(k1), b(k2);
    for (int i = 0; i < k1; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k2; i++) {
        cin >> b[i];
    }
    if (*max_element(begin(a), end(a)) > *max_element(begin(b), end(b))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }


}