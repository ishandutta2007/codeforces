#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 4e3+10, MOD = 1e9+7;

int n, a[N];
int pre[N];

int sum(int l, int r) {
    return pre[r] - (l ? pre[l-1] : 0);
}

const int K = 80;
int memo[N][K][K][2];

int rec(int l, int r, int k, int b) { // 0 is left, 1 is right
    if (r - l + 1 < k) return 0;
    int key = n - r - l + 1;
    if (memo[l][key][k][b] != -MOD) return memo[l][key][k][b];

    int ans = -MOD;
    if (b) ans = max(ans, sum(r - k + 1, r) - rec(l, r - k, k, 0));
    else ans = max(ans, sum(l, l + k - 1) - rec(l + k, r, k, 1));

    if (r - l + 1 > k) {
        if (b) ans = max(ans, sum(r - k, r) - rec(l, r - k - 1, k + 1, 0));
        else ans = max(ans, sum(l, l + k) - rec(l + k + 1, r, k + 1, 1));
    }

    return memo[l][key][k][b] = ans;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        pre[i] = a[i] + (i ? pre[i-1] : 0);
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < K; j++) for (int k = 0; k < K; k++) for (int b : {0, 1})
        memo[i][j][k][b] = -MOD;

    cout << rec(0, n-1, 1, 0) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}