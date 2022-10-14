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
        int cp[2] = {};
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            cp[a % 2]++;
        }
        int m;
        cin >> m;
        int cq[2] = {};
        for (int i = 0; i < m; i++) {
            int a;
            cin >> a;
            cq[a % 2]++;
        }
        long long ans = 0;
        ans += (1ll * cp[0] * cq[0]);
        ans += (1ll * cp[1] * cq[1]);
        cout << ans << "\n";
    }
}