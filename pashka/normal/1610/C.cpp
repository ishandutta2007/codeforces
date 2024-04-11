#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
        int l = 0;
        int r = n + 1;
        while (r > l + 1) {
            int m = (l + r) / 2;
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (b[i] >= c && a[i] >= m - 1 - c) {
                    c++;
                }
                if (c == m) break;
            }
            if (c == m) {
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