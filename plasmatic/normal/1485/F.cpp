// ./f-copy-or-prefix-sum.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

/*
 * dp[i] = #(hybrid) of length i that end with sum(A[1..i])==B[i]
 *
 * answer is sum(dp[1..N])+1
 */

const ll MOD = 1e9 + 7;
const int MN = 2e5 + 1;
int N;
ll B[MN], psum[MN], dp[MN];

// ll rq(int l, int r) { return psum[r] - (l ? psum[l-1] : 0); }
ll get(int q) { return q ? psum[q] : 0; }

void solve() {
    cin >> N;
    for (auto i = 1; i <= N; i++) {
        cin >> B[i];
        psum[i] = psum[i-1] + B[i];
    }
    fill(dp, dp+N+1, 0);
    dp[0] = 1;

    ll ans = dp[0], cum = dp[0];
    map<ll, ll> cnt; cnt[get(-1)] = dp[0];
    for (auto i = 1; i <= N; i++) {
        // for (auto j = 0; j < i; j++) { Optimize this super simple brute force :)
        //     if (B[i] - rq(j, i-1) != B[i]) // psum[i-1] != psum[j-1]
        //         dp[i] += dp[j];
        // }
        dp[i] = (cum - cnt[get(i-1)] + MOD) % MOD;
        cnt[get(i-1)] = (cnt[get(i-1)] + dp[i]) % MOD;
        cum = (cum + dp[i]) % MOD;
        ans += dp[i];
    }
    ans %= MOD;
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}