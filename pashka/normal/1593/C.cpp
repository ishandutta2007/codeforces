#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n, k;
        cin >> n >> k;
        vector<int> x(k);
        for (int i = 0; i < k; i++) {
            cin >> x[i];
        }
        int l = 0;
        sort(x.begin(), x.end());
        int r = k + 1;
        while (r > l + 1) {
            int m = (l + r) / 2;
            long s = 0;
            for (int i = 0; i < m; i++) {
                s += (n - x[k - 1 - i]);
            }
            if (s < n) {
                l = m;
            } else {
                r = m;
            }
        }
        cout << l << "\n";
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