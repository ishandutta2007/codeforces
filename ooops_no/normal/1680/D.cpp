#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const ll INF = 1e13;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = -INF;
    for (int i = 0; i < n; i++) {
        vector<int> b;
        ll cnt = 0, bal = 0;
        for (int j = 0; j < n; j++) {
            b.pb(a[(i + j) % n]);
            cnt += (b[j] == 0);
            bal += b[j];
        }
        bool good = 1;
        for (int j = 0; j < n; j++) {
            if (b[j] == 0) {
                cnt--;
                int val = min(k, cnt * k - bal);
                b[j] = val;
                bal += b[j];
                if (abs(b[j]) > k) good = 0;
            }
        }
        if (!good || bal != 0) continue;
        ll mn = 0, mx = 0, now = 0;
        for (int j = 0; j < n; j++) {
            now += b[j];
            mn = min(mn, now);
            mx = max(mx, now);
        }
        ans = max(ans, mx - mn + 1);
    }
    cout << (ans == -INF ? -1 : ans) << endl;
    return 0;
}