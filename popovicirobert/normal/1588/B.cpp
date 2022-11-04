#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))
#define Test(x) cout << "Case #" << x << ": ";

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
 

using namespace std;






int main() {
#ifdef HOME
    // ifstream cin("A.in");
    // ofstream cout("A.out");
#endif
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    vector<vector<int>> p(4);
    p[1] = {0, 2, 1, 5, 4, 3};
    p[2] = {0, 1, 3, 2, 5, 4};
    p[3] = {0, 1, 2, 6, 5, 4, 3, 9, 8, 7, 10};

    map<pair<int, int>, ll> memo;

    auto Ask = [&](int l, int r, int tt) {
        if (memo.count({l, r})) {
            return memo[{l, r}];
        }

        cout << "? " << l << " " << r << endl;

        #ifndef HOME
            ll answer;
            cin >> answer;
        #else
            ll answer = 0;
            for (int i = l; i <= r; i++) {
                for (int j = i + 1; j <= r; j++) {
                    if (p[tt][i] > p[tt][j]) {
                        answer++;
                    }
                }
            }
        #endif

        return memo[{l, r}] = answer;
    };

    int t;
    cin >> t;

    for (int tt = 1; tt <= t; tt++) {
        int n;
        cin >> n;

        memo.clear();

        ll total = Ask(1, n, tt);

        int l = 1;
        for (int step = 1 << 30; step; step >>= 1) {
            if (l + step <= n && Ask(l + step, n, tt) == total) {
                l += step;
            }
        }

        int mid = l + Ask(l, n, tt) - Ask(l + 1, n, tt) + 1;

        ll val = total - Ask(1, mid - 1, tt);

        int len = 1;
        for (int step = 1 << 30; step; step >>= 1) {
            if (1LL * (len + step) * (len + step - 1) / 2 <= val) {
                len += step;
            }
        }

        cout << "! " << l << " " << mid << " " << mid + len - 1 << endl;
    }

    return 0;
}