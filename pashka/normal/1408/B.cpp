#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        int c = 0;
        for (int i = 0; i < n - 1; i++) if (a[i] != a[i + 1]) c++;
        if (c > 0 && k == 1) {
            cout << -1 << "\n";
            return;
        }
        if (k == 1) {
            cout << 1 << "\n";
            return;
        }
        int res = (c + k - 2) / (k - 1);
        if (res == 0) res = 1;
        cout << res << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test t;
        t.solve();
    }

    return 0;
}