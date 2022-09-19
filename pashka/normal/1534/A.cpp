#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
            int n, m;
            cin >> n >> m;
            vector<string> a(n);
            for (int i =0; i < n; i++) cin >> a[i];
            int c = -1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] != '.') {
                        int k = (a[i][j] == 'R') ^ ((i + j) % 2 == 0);
                        if (c == -1) c = k;
                        if (c != k) {
                            cout << "NO\n";
                            return;
                        }
                    }
                }
            }
            if (c == -1) c = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    a[i][j] = "RW"[(i + j + c) % 2];
                }
            }
            cout << "YES\n";
            for (string s : a) cout << s << "\n";
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