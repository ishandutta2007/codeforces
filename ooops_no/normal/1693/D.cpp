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
    int n;
    cin >> n;
    vector<int> a(n), dp1(n), dp2(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    int ind = n;
    for (int i = n - 1; i >= 0; i--) {
        dp1[i] = n + 1, dp2[i] = 0;
        int j;
        for (j = i + 1; j < n; j++) {
            int val1 = 0, val2 = n + 1;
            if (a[j - 1] < a[j]) {
                val1 = max(val1, dp1[j - 1]);
            }
            if (dp2[j - 1] < a[j]) {
                val1 = max(val1, a[j - 1]);
            }

            if (a[j - 1] > a[j]) {
                val2 = min(val2, dp2[j - 1]);
            }
            if (dp1[j - 1] > a[j]) {
                val2 = min(val2, a[j - 1]);
            }
            if (val1 == dp1[j] && val2 == dp2[j]) break;
            dp1[j] = val1, dp2[j] = val2;
            if (val1 == 0 && val2 == n + 1) {
                ind = min(ind, j);
                break;
            }
        }
        ans += ind - i;
    }
    cout << ans << endl;
    return 0;
}