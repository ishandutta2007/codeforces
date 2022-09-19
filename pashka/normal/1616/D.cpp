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
        int x;
        cin >> x;
        vector<int> d(n + 1);
        for (int i = 0; i < n; i++) {
            d[i + 1] = 1 + (i == 0 ? 0 : d[i - 1]);
            if (i > 0) {
                if (a[i] + a[i - 1] >= 2 * x) {
                    d[i + 1] = max(d[i + 1], 2 + (i == 1 ? 0 : d[i - 2]));
                }
            }
            if (i > 1) {
                if (a[i] + a[i - 1] >= 2 * x &&
                    a[i - 1] + a[i - 2] >= 2 * x &&
                    a[i] + a[i - 1] + a[i - 2] >= 3 * x) {
                    d[i + 1] = max(d[i + 1], 3 + (i == 2 ? 0 : d[i - 3]));
                    if (i - 3 >= 0 && a[i - 1] + a[i - 2] + a[i - 3] >= 3 * x) {
                        d[i + 1] = max(d[i + 1], 2 + d[i - 1]);
                    }
                }
            }
        }
//        for (int x : d) cout << x << " ";
//        cout << "\n";
        cout << d[n] << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        test().solve();
    }

    return 0;
}