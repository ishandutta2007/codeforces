// ./c-add-one.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

constexpr ll MOD = 1e9 + 7;
const int MN = 2e5 + 1;
int T,
    cnt[MN][10], dp[2][10][10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto &cdp = dp[0], &ndp = dp[1];
    for (auto i = 0; i < 10; i++)
        cdp[i][i] = 1LL;
    for (auto i = 0; i < MN; i++) {
        memset(ndp, 0, sizeof ndp);
        for (auto j = 0; j < 10; j++) {
            for (auto k = 0; k < 9; k++)
                ndp[j][k+1] = (ndp[j][k+1] + cdp[j][k]) % MOD;
            ndp[j][0] = (ndp[j][0] + cdp[j][9]) % MOD;
            ndp[j][1] = (ndp[j][1] + cdp[j][9]) % MOD;
        }
        for (auto j = 0; j < 10; j++) 
            for (auto k = 0; k < 10; k++) 
                cnt[i][j] = (cnt[i][j] + cdp[j][k]) % MOD;

        swap(cdp, ndp);
    }
    cin >> T;
    while (T--) {
        int N, M; cin >> N >> M;
        ll ans = 0;
        while (N) {
            ans = (ans + cnt[M][N % 10]) % MOD;
            N /= 10;
        }
        cout << ans << '\n';
    }

    return 0;
}