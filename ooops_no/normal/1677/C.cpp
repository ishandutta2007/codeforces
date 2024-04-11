#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), pos(n), used(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
            pos[b[i]] = i;
        }
        vector<int> even, odd;
        for (int i = 0; i < n; i++) {
            if (used[i]) continue;
            int j = i, cnt = 0;
            while (!used[j]) {
                used[j] = 1;
                cnt++;
                j = pos[a[j]];
            }
            if (cnt % 2 == 0) {
                even.pb(cnt);
            } else {
                odd.pb(cnt);
            }
        }
        sort(even.begin(), even.end());
        sort(odd.rbegin(), odd.rend());
        int l = 1, r = n;
        ll ans = 0;
        for (auto to : even) {
            int f = l;
            for (int j = 0; j < to; j++) {
                if (j + 1 < to) ans += abs(l - r);
                if (j % 2 == 0) {
                    l++;
                } else {
                    r--;
                }
            }
            ans += abs(f - (r + 1));
        }
        for (auto to : odd) {
            int f = l;
            for (int j = 0; j + 1 < to; j++) {
                if (j + 2 < to) ans += abs(l - r);
                if (j % 2 == 0) {
                    l++;
                } else {
                    r--;
                }
            }
            if (to > 1) {
                ans += abs(f - (r + 1));
            }
        }
        cout << ans << endl;
    }
    return 0;
}