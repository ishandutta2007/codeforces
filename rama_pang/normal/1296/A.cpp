#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        int odd = 0;
        int even = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            if (a[i] & 1) {
                odd = 1;
            } else {
                even = 1;
            }
        }
        if (sum % 2 == 1 || (odd && even)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }

    }

}