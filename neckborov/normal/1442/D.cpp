#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const int N = 3005;

int sz[N];
ll pref[N][N];
ll ans;
int n, k;

void go(int l, int r, vector<ll> dp) {
    if (l == r) {
        for (int i = 0; i <= sz[l]; i++) {
            ans = max(ans, pref[l][i] + dp[k - i]);
        }
        return;
    }
    int mid = (l + r) / 2;
    vector<ll> newDp = dp;
    for (int i = l; i <= mid; i++) {
        for (int s = k; s >= sz[i]; s--) {
            newDp[s] = max(newDp[s], newDp[s - sz[i]] + pref[i][sz[i]]);
        }
    }
    go(mid + 1, r, newDp);
    newDp = dp;
    for (int i = mid + 1; i <= r; i++) {
        for (int s = k; s >= sz[i]; s--) {
            newDp[s] = max(newDp[s], newDp[s - sz[i]] + pref[i][sz[i]]);
        }
    }
    go(l, mid, newDp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> sz[i];
        for (int j = 0; j < sz[i]; j++) {
            int x;
            cin >> x;
            if (j < k) {
                pref[i][j + 1] = pref[i][j] + x;
            }
        }
        sz[i] = min(sz[i], k);
    }
    vector<ll> dp(k + 1, -1e15);
    dp[0] = 0;
    go(0, n - 1, dp);
    cout << ans << endl;
    return 0;
}