#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 998244353;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u-= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

int n;
int a[N];
int f[2][3][210];
int sumF[2][3][210];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (a[1] != -1) {
        f[0][0][a[1]] = 1;
        for (int i = a[1]; i <= 200; i++) {
            sumF[0][0][i] = 1;
        }
    } else {
        for (int i = 1; i <= 200; i++) {
            f[0][0][i] = 1;
            sumF[0][0][i] = add(1, sumF[0][0][i - 1]);
        }
    }
    int cur = 0;
    for (int i = 2; i <= n; i++, cur ^= 1) {
        memset(f[cur ^ 1], 0, sizeof f[cur ^ 1]);
        memset(sumF[cur ^ 1], 0, sizeof sumF[cur ^ 1]);
        int low = (a[i] == -1 ? 1 : a[i]);
        int high = (a[i] == -1 ? 200 : a[i]);
        // cout << i << endl;
        for (int j = low; j <= high; j++) {
            f[cur ^ 1][0][j] = add(f[cur ^ 1][0][j], sumF[cur][0][j - 1]);
            f[cur ^ 1][0][j] = add(f[cur ^ 1][0][j], sumF[cur][1][j - 1]);
            f[cur ^ 1][0][j] = add(f[cur ^ 1][0][j], sumF[cur][2][j - 1]);

            f[cur ^ 1][1][j] = add(f[cur ^ 1][1][j], f[cur][0][j]);
            f[cur ^ 1][1][j] = add(f[cur ^ 1][1][j], f[cur][1][j]);
            f[cur ^ 1][1][j] = add(f[cur ^ 1][1][j], f[cur][2][j]);

            f[cur ^ 1][2][j] = add(f[cur ^ 1][2][j], sub(sumF[cur][1][200], sumF[cur][1][j]));
            f[cur ^ 1][2][j] = add(f[cur ^ 1][2][j], sub(sumF[cur][2][200], sumF[cur][2][j]));
            // cout << j << " " << f[cur ^ 1][0][j] << " " << f[cur ^ 1][1][j] << " " << f[cur ^ 1][2][j] << endl;
        }

        for (int j = 0; j < 3; j++) {
            for (int k = 1; k <= 200; k++) {
                sumF[cur ^ 1][j][k] = add(sumF[cur ^ 1][j][k - 1], f[cur ^ 1][j][k]);
            }
        }
        // cout << sumF[cur ^ 1][2][200] << endl;
    }
    int res = add(sumF[cur][1][200], sumF[cur][2][200]);
    cout << res << endl;
    return 0;
}