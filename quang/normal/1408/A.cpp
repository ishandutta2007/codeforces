#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int &u : a) cin >> u;
            for (int &u : b) cin >> u;
                for (int &u : c) cin >> u;
        vector<int> res(n);
        res[0] = a[0];
        for (int i = 1; i + 1 < res.size(); i++) {
            if (a[i] != res[i - 1]) res[i] = a[i];
            else res[i] = b[i];
        }
        if (a.back() != res[0] && a.back() != res[res.size() - 2]) {
            res.back() = a.back();
        }
        if (b.back() != res[0] && b.back() != res[res.size() - 2]) {
            res.back() = b.back();
        }
        if (c.back() != res[0] && c.back() != res[res.size() - 2]) {
            res.back() = c.back();
        }
        for (int u : res) cout << u << ' ';
            cout << '\n';
    }
    return 0;
}