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
        int l = n;
        int r = -1;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] == a[i + 1]) {
                l = min(l, i);
                r = max(r, i);
            }
        }
        if (l == n || l == r) {
            cout << "0\n";
            return;
        }
        cout << max(1, r - l - 1) << "\n";
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