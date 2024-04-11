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
        vector<vector<int>> mx(n, vector<int>(n));
        for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                vector<bool> z(n + 1);
                for (int i = l; i <= r; i++)
                    if (a[i] < n) z[a[i]] = true;
                mx[l][r] = 0;
                while (z[mx[l][r]]) mx[l][r]++;
            }
        }
        long res = 0;
        for (int l = 0; l < n; l++) {
            vector<long> d(n);
            for (int r = l; r < n; r++) {
                d[r] = 1 + mx[l][r];
                for (int i = l + 1; i <= r; i++) {
                    d[r] = max(d[r], d[i - 1] + mx[i][r] + 1);
                }
                res += d[r];
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