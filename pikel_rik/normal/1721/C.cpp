#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &x : a) cin >> x;

        vector<int> b(n);
        for (auto &x : b) cin >> x;

        vector<int> back(n);
        for (int i = 0; i < n; i++) {
            int lb = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            cout << b[lb] - a[i] << ' ';
            if (lb < i) {
                back[i] = 1;
            }
        }
        cout << '\n';

        vector<int> dmax(n);
        for (int i = n - 1, cur = 0; i >= 0; i--) {
            dmax[i] = b[i + cur] - a[i];
            if (back[i] == 1) {
                cur += 1;
            } else {
                cur = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << dmax[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}