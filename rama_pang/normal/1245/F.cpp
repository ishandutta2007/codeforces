#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N = 40;
int L[40], R[40];
lint memo[2][2][2][2][40]; // f1 = x > l, f2 = x < r, f3, f4 for y, n = leftmost digits
/*  After f1 = f2 = 1, we can place anything in current position, otherwise we are limited
    (it can go out of bounds) which is why we set a flag on it.
*/

lint dp(int f1, int f2, int f3, int f4, int n) {
    if (n >= N) return 1;
    if (memo[f1][f2][f3][f4][n] != -1) return memo[f1][f2][f3][f4][n];
    lint &res = memo[f1][f2][f3][f4][n] = 0;

    int l1 = f1? 0 : L[n];
    int r1 = f2? 1 : R[n];
    int l2 = f3? 0 : L[n];
    int r2 = f4? 1 : R[n];

    for (int i = l1; i <= r1; i++) {
        for (int j = l2; j <= r2; j++) {
            if (i == 1 && j == 1) continue;
            int nf1 = (f1 | i > L[n]);
            int nf2 = (f2 | i < R[n]);
            int nf3 = (f3 | j > L[n]);
            int nf4 = (f4 | j < R[n]);
            res += dp(nf1, nf2, nf3, nf4, n + 1);
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) {
        memset(memo, -1, sizeof(memo));
        memset(L, 0, sizeof(L));
        memset(R, 0, sizeof(R));

        int l, r;
        cin >> l >> r;
        int i = N - 1;
        while (l > 0) {
            L[i] = l % 2;
            l /= 2;
            i--;
        }

        i = N - 1;
        while (r > 0) {
            R[i] = r % 2;
            r /= 2;
            i--;
        }

        cout << dp(0, 0, 0, 0, 0) << "\n";

    }
}