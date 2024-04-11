#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x = 0;
        cin >> n;
        vector<int> dp(n + 1), a(n);
        map<int,int> last;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        last[0] = 0;
        for (int i = 0; i < n; i++) {
            x ^= a[i];
            dp[i + 1] = dp[i];
            if (last.count(x)) {
                dp[i + 1] = max(dp[i + 1], dp[last[x]] + 1);
            }
            last[x] = i + 1;
        }
        cout << n - dp[n] << endl;
    }
    return 0;
}