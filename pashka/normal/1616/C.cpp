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
        int res = n;
        if (n < 2) res = 0;
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {
                int s = 0;
                for (int i = 0; i < n; i++) {
                    int x1 = r - l;
                    int y1 = a[r] - a[l];
                    int x2 = i - l;
                    int y2 = a[i] - a[l];
                    if (x1 * y2 - x2 * y1 != 0) {
                        s++;
                    }
                }
                res = min(res, s);
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
        test().solve();
    }

    return 0;
}