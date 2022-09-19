#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n, m;
        cin >> n >> m;
        if (n == 1 && m == 1) {
            cout << 0;
        } else if (n == 1 || m == 1) {
            cout << 1;
        } else {
            cout << 2;
        }
        cout << "\n";
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