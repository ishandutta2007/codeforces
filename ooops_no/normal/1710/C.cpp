#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int MOD = 998244353;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int a = 0; a <= 2; a++) {
        for (int b = 0; b <= 2; b++) {
            for (int c = 0; c <= 2; c++) {
                vector<int> arr{(a ^ b), (b ^ c), (a ^ c)};
                sort(arr.begin(), arr.end());
            }
        }
    }
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> dp(8, vector<int>(8));
    vector<int> type{0, 1, 2, 4, 4, 2, 1};
    dp[0][7] = 1;
    for (int i = 0; i < n; i++) {
        vector<vector<int>> dpp(8, vector<int>(8));
        for (int mask = 0; mask < 8; mask++) {
            for (int cond = 0; cond < 8; cond++) {
                for (int nw = 0; nw < 8; nw++) {
                    bool bad = 0;
                    for (int j = 0; j < 3; j++) {
                        if (s[i] == '0' && (nw & (1 << j)) && (cond & (1 << j))) {
                            bad = 1;
                        }
                    }
                    if (bad) continue;
                    int new_mask = (mask | type[nw]), new_cond = cond;
                    for (int j = 0; j < 3; j++) {
                        if (s[i] == '1' && !(nw & (1 << j))) {
                            if (new_cond & (1 << j)) {
                                new_cond -= (1 << j);
                            }
                        }
                    }
                    dpp[new_mask][new_cond] = add(dpp[new_mask][new_cond], dp[mask][cond]);
                }
            }
        }
        swap(dp, dpp);
    }
    int ans = 0;
    for (int i = 0; i < 8; i++) {
        ans = add(ans, dp[7][i]);
    }
    cout << ans << endl;
    return 0;
}