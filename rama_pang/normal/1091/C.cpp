#include <bits/stdc++.h>
using namespace std;
using lint = long long;
// #define TESTCASE
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
    return 0;
}

int solve() {
    int n;
    cin >> n;
    vector<int> f;
    for (int k = 1; k * k <= n; k++) {
        if (n % k == 0) {
            f.emplace_back(k);
            f.emplace_back(n / k);
        }
    }

    vector<lint> ans;
    for (auto i : f) {
        int a = __gcd(n, i);
        int b = n;
        int cnt = (b - a) / __gcd(n, i);
        ans.emplace_back(1ll * (a + b) * (cnt + 1) / 2 + cnt - n + 1);
    }

    sort(begin(ans), end(ans));
    ans.resize(unique(begin(ans), end(ans)) - begin(ans));
    for (auto i : ans) {
        cout <<  i << " ";
    }
    cout << "\n";
    

}