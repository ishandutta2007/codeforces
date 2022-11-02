#include<bits/stdc++.h>

using namespace std;
#define int long long
const int max_n = 104;


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    // online submission
#endif
    int n, m;
    cin >> n >> m;
    int a[n][2 * m];
    int ans = 0;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < 2 * m;j++) {
            cin >> a[i][j];
        }
        for(int j = 0;j < 2 * m;j += 2) {
            if (a[i][j] || a[i][j + 1]) ans++;
        }
    }
    cout << ans;
}