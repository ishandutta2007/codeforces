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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt = 0;
        for (int i = 1; i + 1 < n; i++) {
            if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
                if (i + 2 < n) a[i + 1] = max(a[i], a[i + 2]);
                else a[i + 1] = a[i];
                cnt++;
            }
        }
        cout << cnt << endl;
        for (auto to : a) {
            cout << to << ' ';
        }
        cout << endl;
    }
    return 0;
}