#include <bits/stdc++.h>

using namespace std;

const int N = 11;
const int MOD = 1000003;

int a[N][N + 1];

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

int main() {


    // int x = 2;
    // cout << (1+  1ll * 689719 * x +  1ll * 310292 * x * x) % MOD << endl;
    // return 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        int cur = 1;
        for (int j = 0; j < N; j++) {
            a[i][j] = cur;
            cur = (1ll * cur * i) % MOD;
        }
        cout << "? " << i << endl;
        int u;
        cin >> u;
        if (u == 0) {
            cout << "! " << i << endl;
            return 0;
        }
        a[i][N] = u;
    }
        // for (int i = 0; i < N; i++, cout << endl) for (int j = 0; j <= N; j++) cout << a[i][j] << ' ';
        //     cout << endl;

    for (int col = 0; col < N; col++) {
        for (int i = 0; i < N; i++) {
            if (i != col) {
                int foo = mul(a[i][col], inv(a[col][col]));
                // if (col == 2 && i == 1) cout << "now " <<  a[i][col] << ' ' << a[col][col] << endl;
                for (int j = col; j <= N; j++) {
                    a[i][j] = (1ll * a[i][j] - 1ll * a[col][j] * foo % MOD + MOD) % MOD;
                }
            }
        }

            // for (int i = 0; i < N; i++, cout << endl) for (int j = 0; j <= N; j++) cout << a[i][j] << ' ';
            //     cout << endl;
    }
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j <= N; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    vector<int> coeff(N);
    for (int i = 0; i < N; i++) coeff[i] = mul(inv(a[i][i]), a[i][N]);
    // for (int u : coeff) cout << u << ' ';
    //     cout << endl;
    for (int i = N; i < MOD; i++) {
        int cur = 1;
        int res = 0;
        for (int j = 0; j < coeff.size(); j++) {
            res = (res + 1ll * coeff[j] * cur % MOD) % MOD;
            // cout << cur << ' ';
            cur = (1ll * cur * i) % MOD;
        }
        // cout << res << endl;
        // break;
        if (res == 0) {
            cout << "! " << i << endl;
            return 0;
        }
    }
    cout << "! " << -1 << endl;

    return 0;
}