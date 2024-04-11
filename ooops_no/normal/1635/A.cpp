#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> was(30);
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < 30; j++) {
                if ((1LL << j) & a[i]) {
                    was[j] = 1;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < 30; i++) {
            if (was[i]) {
                ans += (1LL << i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}