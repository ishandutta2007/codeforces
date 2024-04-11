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
    lint sum = 0;
    lint Xor = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        Xor ^= a[i];
    }
    if (sum == 2 * Xor) {
        cout << 0 << "\n\n";
        return 0;
    }
    vector<lint> ans;
    ans.emplace_back(Xor);
    sum += Xor;
    Xor = 0;
    ans.emplace_back(sum);
    Xor = sum;
    sum += sum;
    assert(sum == 2 * Xor);
    cout << ans.size() << "\n";
    for (auto i : ans) {
        cout << i << " ";
    }
    cout << "\n";



}