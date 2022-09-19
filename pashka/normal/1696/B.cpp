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
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) ok = false;
        }
        if (ok) {
            cout << 0 << "\n";
            return;
        }
        int l = 0;
        while (a[l] == 0) l++;
        int r = n - 1;
        while (a[r] == 0) r--;
        ok = true;
        for (int i = l; i <= r; i++) {
            if (a[i] == 0) ok = false;
        }
        if (ok) {
            cout << 1 << "\n";
            return;
        }
        cout << 2 << "\n";
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