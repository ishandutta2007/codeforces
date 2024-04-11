#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                ans++;
                sum++;
                a[i]++;
            }
        }
        if (sum == 0) {
            ans++;
        }
        cout << ans << "\n";
    }
}