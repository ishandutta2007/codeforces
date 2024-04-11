#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        vector<int> g(n);
        for (int i = 0; i < n; i++) g[a[i]] = b[i];
        vector<bool> z(n);
        long res = 1;
        for (int i = 0; i < n; i++) {
            if (z[i]) continue;
            int x = i;
            while (!z[x]) {
                z[x] = true;
                x = g[x];
            }
            res *= 2;
            res %= (int) (1e9 + 7);
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