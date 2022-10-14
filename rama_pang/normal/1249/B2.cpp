#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<int> a(n), ans(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            if (ans[i] != -1) {
                continue;
            }
            int j = a[i];
            int cnt = 1;
            while (j != i) {
                cnt++;
                j = a[j];
            }
            ans[j] = cnt;
            j = a[j];
            while (j != i) {
                ans[j] = cnt;
                j = a[j];
            }
        }

        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}