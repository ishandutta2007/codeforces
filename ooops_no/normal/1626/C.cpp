#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long

mt19937 rnd(51);

const int INF = 1e18;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, ans = 0;
        cin >> n;
        vector<int> k(n), h(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        int last = -INF;
        for (int i = n - 1; i >= 0; i--) {
            if (i + 1 < n) last -= k[i + 1] - k[i];
            last = max(last, h[i]);
            h[i] = last;
        }
        last = 0;
        int pow = 0;
        for (int i = 0; i < n; i++) {
            if (k[i] - last >= h[i]) {
                ans += h[i] * (h[i] + 1) / 2;
                pow = h[i];
            } else {
                int val = k[i] - last;
                ans += val * (val + 1) / 2 + val * pow;
                pow += val;
            }
            last = k[i];
        }
        cout << ans << endl;
    }
    return 0;
}