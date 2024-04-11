#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];
        vector<int> c(n);
        for (int i = 0; i < n; i++) cin >> c[i];
        vector<int> res(n);
        res[0] = a[0];
        for (int i = 1; i < n - 1; i++) {
            if (a[i] != res[i - 1]) res[i] = a[i]; else res[i] = b[i];
        }
        if (a[n - 1] != res[0] && a[n - 1] != res[n - 2]) {
            res[n - 1] = a[n - 1];
        }
        if (b[n - 1] != res[0] && b[n - 1] != res[n - 2]) {
            res[n - 1] = b[n - 1];
        }
        if (c[n - 1] != res[0] && c[n - 1] != res[n - 2]) {
            res[n - 1] = c[n - 1];
        }
        for (int i = 0; i < n ; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
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