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
        sort(a.begin(), a.end());
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) {
            d[i] = d[i - 1];
            if (a[i - 1] <= i) {
                d[i] = max(d[i], d[i - a[i - 1]] + 1);
            }
        }
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