#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pb push_back
#define ld double
#define ll __int128

mt19937 rnd(51);

const int INF = 1e18;

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int now = 1;
    vector<int> a;
    for (int i = 1; now <= 1e12; i++) {
        a.pb(now);
        now *= i;
    }
    int t;
    cin >> t;
    while (t--) {
        int n, ans = INF, cnt = 0;
        cin >> n;
        for (int i = 0; i < (1 << 15); i++) {
            int res = 0 ;
            for (int j = 0; j < 15; j++) {
                if (i & (1 << j)) {
                    res += a[j];
                }
            }
            if (n < res) continue;
            ans = min(ans, (int)__builtin_popcountll(n - res) + __builtin_popcountll(i));
        }
        cout << ans << endl;
    }
    return 0;
}