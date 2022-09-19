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
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            int x = min(a[i], a[i + 1]);
            int y = max(a[i], a[i + 1]);
            while (y > 2 * x) {
                res++;
                x *= 2;
            }
        }
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