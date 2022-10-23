#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n, k;
        cin >> n >> k;
        bool ok = false;
        for (int i = 0;i  < n; i++) {
            int x;
            cin >> x;
            if (x == 1) ok = true;
        }
        cout << (ok ? "YES" : "NO") << "\n";
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