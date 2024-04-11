#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mx = 0;
        for (int i = 1; i < n - 1; i++) {
            mx = max(mx, a[i]);
        }
        if (mx == 1 || (n == 3 && a[1] % 2 == 1)) {
            cout << -1 << endl;
        } else {
            int cnt = 0;
            for (int i = 1; i < n - 1; i++) {
                cnt += a[i] / 2 + a[i] % 2;
            }
            cout << cnt << endl;
        }
    }
    return 0;
}