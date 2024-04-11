#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n - 2 || abs(a - b) > 1) {
            cout << "-1\n";
            continue;
        }

        vector<int> p(n);
        iota(p.begin(), p.end(), 0);

        if (a == b) {
            for (int i = n - 2; i > 1 && a > 0 && b > 0; i -= 2) {
                swap(p[i - 1], p[i]);
                a -= 1, b -= 1;
            }
        } else {
            swap(p[n - 2], p[n - 1]);
            for (int i = n - 3; i > 1 && a > 0 && b > 0; i -= 2) {
                swap(p[i - 1], p[i]);
                a -= 1, b -= 1;
            }
            if (b > 0) {
                for (auto &x : p) {
                    x = n - 1 - x;
                }
            }
        }

        for (auto &x : p) {
            cout << x + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}