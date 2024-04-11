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
        vector<int> xx;
        for (int j = 0; j < n / 2; j++) {
            if (a[j] != a[n - 1 - j]) {
                xx.push_back(a[j]);
                xx.push_back(a[n - 1 - j]);
                break;
            }
        }
        if (xx.empty()) {
            cout << "YES\n";
            return;
        }
        for (int x : xx) {
            vector<int> aa;
            for (int w : a) {
                if (w != x) aa.push_back(w);
            }
            int t = aa.size();
            bool ok = true;
            for (int j = 0; j < t / 2; j++) {
                if (aa[j] != aa[t - 1 - j]) ok = false;
            }
            if (ok) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
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