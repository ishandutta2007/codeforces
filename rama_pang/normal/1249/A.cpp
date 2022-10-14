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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(begin(a), end(a));
        int ans = 1;
        for (int i = 0; i + 1 < n; i++) {
            if (a[i] + 1 == a[i + 1]) {
                ans++;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}