#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n + 2);
        for (int i =0; i < n; i++) cin >> a[i + 1];
        long res = 0;
        for (int i = 0; i < n; i++) {
            int k = max(a[i], a[i + 2]);
            if (a[i + 1] > k) {
                res += (a[i + 1] - k);
                a[i + 1] = k;
            }
        }
        for (int i = 0; i < n + 1; i++) {
            res += abs(a[i] - a[i + 1]);
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