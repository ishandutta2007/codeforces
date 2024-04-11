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
            vector<int> arr;
            for (int j = k; j >= 1; j--) {
                if (arr.size() == 0 || arr.back() != a[i] / j) {
                    arr.pb(a[i] / j);
                }
            }
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