#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 20, MOD = 998244353;

const int M = 3e7;
static int trash[M];
int trash_p = 0;

struct neg_vec {
    int offset;
    vector<int> v;

    neg_vec() {}
    neg_vec(int n): offset(n) {
        v.assign(2 * n + 1, 0);
    }
    int& operator[] (int i) {
        return i < -offset || i > +offset ? trash[trash_p++] : v[i + offset];
    }
};

int n, sum_mask[1 << N], sum[N], min_ps[N];
neg_vec cnt[N];
neg_vec cnt_no_neg[N];
int dp[1 << N]; // can extend or can't

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int ps = 0;

        int m = sz(s);
        cnt[i] = cnt_no_neg[i] = neg_vec(m);
        min_ps[i] = MOD;
        for (char c : s) {
            int x = (c == '(' ? +1 : -1);
            sum[i] += x;
            ps += x;
            cnt[i][ps]++;

            if (min_ps[i] >= ps) cnt_no_neg[i][ps]++;
            min_ps[i] = min(min_ps[i], ps);
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) if ((i >> j) & 1)
            sum_mask[i] += sum[j];
    }
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    int ans = 0;
    for (int mask = 0; mask < (1 << n); mask++) if (dp[mask] != -1) {
        ans = max(ans, dp[mask]);
        for (int j = 0; j < n; j++) if ((mask >> j) & 1 ^ 1) {
            int cur_sum = sum_mask[mask];
            if (cur_sum + min_ps[j] < 0) {
                // consider this being the last thing
                ans = max(ans, dp[mask] + cnt_no_neg[j][-cur_sum]);
            } else {
                dp[mask | (1 << j)] = max(dp[mask | (1 << j)], dp[mask] + cnt[j][-cur_sum]);
            }
        }
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}