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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> mx(a[n - 1] + 1);
        for (int i = 0; i < n; i++) {
            vector<int> arr{a[i]};
            int now = a[i], cnt = 0;
            while (now > 0) {
                int val = a[i] / now + 1;
                if (val <= k) {
                    arr.pb(a[i] / val);
                    now = a[i] / val;
                } else {
                    break;
                }
            }
            reverse(arr.begin(), arr.end());
            if (arr[0] != 0) {
                mx[0] = max(mx[0], arr[0]);
            }
            for (int j = 1; j < arr.size(); j++) {
                mx[arr[j - 1] + 1] = max(mx[arr[j - 1] + 1], arr[j]);
            }
        }
        int r = 0, ans = a.back();
        for (int i = 0; i <= a[0]; i++) {
            r = max({r, i, mx[i]});
            ans = min(ans, r - i);
        }
        cout << ans << endl;
    }
    return 0;
}