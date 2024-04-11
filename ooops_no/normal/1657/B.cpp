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
        int n, b, x, y;
        cin >> n >> b >> x >> y;
        n++;
        vector<int> a(n);
        int sum = 0;
        for (int i = 1; i < n; i++) {
            if (a[i - 1] + x <= b) {
                a[i] = a[i - 1] + x;
            } else {
                a[i] = a[i - 1] - y;
            }
            sum += a[i];
        }
        cout << sum << endl;
    }
    return 0;
}