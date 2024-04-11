#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(51);

const int INF = 1e18;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n), mx(n + 1, -INF);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += a[j];
                mx[j - i + 1] = max(mx[j - i + 1], sum);
            }
        }
        for (int i = n - 1; i >= 0; i--) mx[i] = max(mx[i], mx[i + 1]);
        mx[0] = max(mx[0], 0ll);
        int bst = -INF;
        for (int i = 0; i <= n; i++) {
            cout << max(bst, mx[i] + i * x) << ' ';
            bst = max(bst, mx[i] + i * x);
        }
        cout << endl;
    }
    return 0;
}