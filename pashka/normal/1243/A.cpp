#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res = max(res, min(n - i, a[i]));
    }
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }

    return 0;
}