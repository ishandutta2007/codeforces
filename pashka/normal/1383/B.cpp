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
        for (int x = 30; x >= 0; x--) {
            int c = 0;
            for (int i = 0; i < n; i++) {
                if ((a[i] >> x) & 1) c++;
            }
            if (c % 2 == 1) {
                if (c % 4 == 1 || n % 2 == 0) {
                    cout << "WIN\n";
                } else {
                    cout << "LOSE\n";
                }
                return;
            }
        }
        cout << "DRAW\n";
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