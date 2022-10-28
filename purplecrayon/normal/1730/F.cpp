#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 5e3+10, MOD = 1e9+7;
const int K = 8;

int n, k;
int p[N], ip[N];
int cur[N][1 << K], nxt[N][1 << K];

// max element for {1..i} has to be in {i..i+k}

int store[N][N];

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i], --p[i];
    }
    for (int i = 0; i < n; i++) ip[p[i]] = i;

    for (int j = 0; j < n; j++) {
        for (int mask = 0; mask < (1 << k); mask++) {
            nxt[j][mask] = MOD;
        }
    }
    for (int mx = 0; mx <= min(n-1, k); mx++) {
        int mask = 0;
        for (int j = mx-1; j >= mx-k; j--) {
            if (j < 0) mask |= 1 << (mx - j - 1);
        }
        nxt[mx][mask] = 0;
    }

    for (int i = 0; i < n; i++) { // ip[me]
        for (int j = 0; j < n; j++) {
            if (ip[i] < ip[j]) store[i][j]++;
            if (j) store[i][j] += store[i][j-1];
        }
    }
    for (int i = 0; i < n-1; i++) {
        for (int j = max(0, i - k - 1); j <= min(n - 1, i + k + 1); j++) {
            for (int mask = 0; mask < (1 << k); mask++) {
                cur[j][mask] = nxt[j][mask];
                nxt[j][mask] = MOD;
            }
        }

        for (int mask = 0; mask < (1 << k); mask++) {
            for (int mx = i; mx <= min(n - 1, i + k); mx++) {
                if (cur[mx][mask] == MOD) continue;

                // cout << "i, mask, mx: " << i << ' ' << mask << ' ' << mx << ' ' << cur[mx][mask] << endl;
                for (int me = max(0, i - k); me <= min(n - 1, i + 1 + k); me++) if (me != mx) {
                        // i'm placing the **number** me, and the numbers that have been put already are:
                        //      - everything less than mx - k
                        //      - mx
                        //      - everything that's in the mask

                    int invs = (ip[mx] > ip[me]) + (mx - k - 1 >= 0 ? store[me][mx - k - 1] : 0);
                    // for (int x = 0; x < mx - k; x++) if (ip[x] > ip[me]) invs++;
                    for (int x = max(0, mx - k); x < mx; x++) {
                        if (((mask >> (mx - x - 1)) & 1)) {
                            if (ip[x] > ip[me])
                                invs++;
                        }
                    }
                        
                    if (me < mx) {
                        if (me < mx - k) continue;
                        if ((mask >> (mx - me - 1)) & 1) continue;
                        int new_mask = mask | (1 << (mx - me - 1));
                        
                        // cout << "transition 0: " << me << ' ' << new_mask << ' ' << invs << endl;

                        nxt[mx][new_mask] = min(nxt[mx][new_mask], cur[mx][mask] + invs); 
                    } else {
                        int take = me - mx;
                        // if there are any 0's among k-1, k-2.. k-take, continue
                        if (take > k + 1) continue;
                        if (__builtin_popcount((mask >> (k - take + 1)) + 1) != 1) continue;
                        int new_mask = ((mask << take) | (1 << (take - 1))) & ((1 << k) - 1);

                        // cout << "transition 1: " << me << ' ' << new_mask << ' ' << invs << endl;
                        nxt[me][new_mask] = min(nxt[me][new_mask], cur[mx][mask] + invs);
                    }
                }
            }
        }
    }

    int ans = MOD;
    for (int i = 0; i < n; i++) ans = min(ans, nxt[i][(1 << k) - 1]);
    assert(ans != MOD);
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}