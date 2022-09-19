#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

struct test {
    void solve() {
        int n, k;
        cin >> n >> k;
        if (n < 2 * k - 1) {
            cout << -1 << "\n";
        } else {
            for (int i = 0;i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j && (i % 2 == 0) && k > 0) {
                        cout << "R";
                        k--;
                    } else {
                        cout << ".";
                    }
                }
                cout << "\n";
            }
        }
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