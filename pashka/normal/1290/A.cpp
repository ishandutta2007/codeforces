#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

void solve_test() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    k = min(k, m - 1);
    int res = 0;
    for (int l = 0; l <= k; l++) {
        int r = k - l;
        int q = m - 1 - k;
        int s = INT_MAX;
        for (int ll = 0; ll <= q; ll++) {
            int rr = q - ll;
            int c = max(a[l + ll], a[n - 1 - r - rr]);
            s = min(s, c);
        }
        res = max(res, s);
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