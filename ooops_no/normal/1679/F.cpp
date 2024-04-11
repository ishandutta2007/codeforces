#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int MOD = 998244353, K = 10;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

vector<vector<bool>> e(K, vector<bool>(K));
vector<int> comp(K);

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> bad(K);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e[a][b] = e[b][a] = 1;
        comp[a] |= (1 << b);
        comp[b] |= (1 << a);
    }
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < i; j++) {
            if (e[i][j]) {
                bad[i] |= (1 << j);
            }
        }
    }
    vector<int> dp(1 << K);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        vector<int> dpp(1 << K);
        for (int j = 0; j < (1 << K); j++) {
            if (dp[j] == 0) continue;
            for (int f = 0; f < K; f++) {
                if (j & bad[f]) continue;
                int nw = (j & comp[f]) | (1 << f);
                dpp[nw] = add(dpp[nw], dp[j]);
            }
        }
        swap(dp, dpp);
    }
    int ans = 0;
    for (auto to : dp) {
        ans = add(ans, to);
    }
    cout << ans << endl;
    return 0;
}