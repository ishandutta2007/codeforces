#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        long s = 0;
        int c = INT_MAX;
        for (int i = 0; i < 2 * n; i++) {
            for (int j = 0; j < 2 * n; j++) {
                int x;
                cin >> x;
                if (i >= n && j >= n) {
                    s += x;
                } else {
                    if ((i == n || i == 2 * n - 1) &&
                        (j == 0 || j == n - 1)) {
                        c = min(c, x);
                    }
                    if ((i == 0 || i == n - 1) &&
                        (j == n || j == 2 * n - 1)) {
                        c = min(c, x);
                    }
                }
            }
        }
        cout << s + c << "\n";
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