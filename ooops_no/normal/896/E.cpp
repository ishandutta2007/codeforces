#pragma GCC target("avx")
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")

#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

const int N = 1e5 + 10;
int a[N];

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        int t, l, r, x;
        cin >> t >> l >> r >> x;
        l--, r--;
        if (t == 1) {
            for (int j = l; j <= r; ++j) {
                if (a[j] > x) {
                    a[j] -= x;
                }
            }
        } else {
            int ans = 0;
            for (int j = l; j <= r; j++) {
                ans += (a[j] == x);
            }
            cout << ans << endl;
        }
    }
    return 0;
}