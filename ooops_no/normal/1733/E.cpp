#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

vector<vector<ll>> fill_dp(ll val) {
    vector<vector<ll>> dp(120, vector<ll>(120));
    dp[0][0] = val;
    for (int i = 0; i < 120; i++) {
        for (int j = 0; j < 120; j++) {
            if (j + 1 < 120) {
                dp[i][j + 1] += (dp[i][j] + 1) / 2;
            }
            if (i + 1 < 120) {
                dp[i + 1][j] += (dp[i][j]) / 2;
            }
        }
    }
    return dp;
}

signed main() {
#ifdef LOCAL
   // freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        ll t;
        int x, y;
        cin >> t >> x >> y;
        if (t < x + y) {
            cout << "NO\n";
            continue;
        }
        auto dp = fill_dp(t - x - y), dpp = fill_dp(t - x - y + 1);
        int posx = -1, posy = -1;
        for (int i = 0; i < 120; i++) {
            int j = (x + y) - i;
            if (j >= 0 && j < 120) {
                if (dp[i][j] != dpp[i][j]) {
                    assert(posx == -1 && posy == -1);
                    posx = i, posy = j;
                }
            }
        }
        if (posx == x && posy == y) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}