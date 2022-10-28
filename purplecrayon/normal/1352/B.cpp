#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k; cin >> n >> k;
    for (int b : {1, 2}) {
        vector<int> ans(k, b);
        int sum = (k - 1) * b;
        int last = n - sum;
        if (last > 0 && last % 2 == b % 2) {
            ans[k-1] = last;
            
            cout << "YES\n";
            for (int x : ans) cout << x << ' '; cout << '\n';
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    int T; cin >> T;
    while (T--) solve();
}