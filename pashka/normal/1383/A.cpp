#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        vector<vector<int>> c(20, vector<int>(20));
        for (int i = 0; i < n; i++) {
            if (b[i] < a[i]) {
                cout << -1 << "\n";
                return;
            }
            c[a[i] - 'a'][b[i] - 'a']++;
        }
        int res = 0;
        for (int i = 0; i < 20; i++) {
            int d = -1;
            for (int j = i + 1; j < 20; j++) {
                if (c[i][j] > 0) {
                    d = j;
                    break;
                }
            }
            if (d != -1) {
                res++;
                for (int j = i + 1; j < 20; j++) {
                    c[d][j] += c[i][j];
                }
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