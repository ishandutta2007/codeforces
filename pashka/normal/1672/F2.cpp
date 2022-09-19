#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka
struct test {

    vector<vector<int>> g;
    int m;
    bool ok;
    vector<int> z;

    void dfs(int x) {
        if (z[x] == 1) ok = false;
        if (z[x] != 0) return;
        z[x] = 1;
        for (int y: g[x]) {
            if (y != m)
                dfs(y);
        }
        z[x] = 2;
    }

    void solve() {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
        }
        vector<int> d(n);
        for (int i = 0; i < n; i++) d[a[i]]++;

        g.resize(n);
        for (int i = 0; i < n; i++) {
            g[a[i]].push_back(b[i]);
        }

        m = 0;
        for (int i = 0; i < n; i++) {
            if (d[i] > d[m]) m = i;
        }

        ok = true;
        z.resize(n);
        for (int i = 0; i < n; i++) {
            if (i != m) dfs(i);
        }

        if (ok) {
            cout << "AC\n";
        } else {
            cout << "WA\n";
        }
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