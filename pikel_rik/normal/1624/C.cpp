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

        sort(a.rbegin(), a.rend());

        bool possible = true;
        for (int i = n; i > 0; i--) {
            for (int j = n - i; j < n; j++) {
                while (a[j] > i) {
                    a[j] /= 2;
                }
            }
            int j = find(a.begin() + n - i, a.end(), i) - a.begin();
            if (j != n) {
                swap(a[n - i], a[j]);
            } else {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }
    return 0;
}