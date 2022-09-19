#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

const int MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        s[i]--;
    }
    vector<int> f(m), h(m);
    for (int i = 0; i < m; i++) {
        cin >> f[i] >> h[i];
        f[i]--;
    }

    vector<int> cl(n), cr(n);
    for (int i = 0; i < n; i++) {
        cr[s[i]]++;
    }
    vector<vector<int>> q(n, vector<int>(n + 1));
    for (int i = 0; i < m; i++) {
        q[f[i]][h[i]]++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            q[i][j] += q[i][j - 1];
        }
    }

    vector<int> ss(n);
    vector<int> rr(n);

    for (int i = 0; i < n; i++) {
        int x = cl[i];
        int y = cr[i];
        if (x > y) swap(x, y);
        if (q[i][y] >= 2 && q[i][x] >= 1) {
            rr[i] = 2;
            ss[i] = ((long) q[i][x] * (q[i][y] - 1)) % MOD;
        } else if (q[i][y] >= 1) {
            rr[i] = 1;
            ss[i] = (q[i][y] + q[i][x]) % MOD;
        } else {
            rr[i] = 0;
            ss[i] = 1;
        }
    }

    int res_s = 1;
    int res_r = 0;
    for (int i = 0; i < n; i++) {
        res_r += rr[i];
        res_s = ((long) res_s * ss[i]) % MOD;
    }

    for (int i = 0; i < n; i++) {
        int k = s[i];
        cl[k]++;
        cr[k]--;
        if (q[k][cl[k]] > q[k][cl[k] - 1]) {
            int n_s = 1;
            int n_r = 1;
            for (int j = 0; j < n; j++)
                if (j != k) {
                    n_r += rr[j];
                    n_s = ((long) n_s * ss[j]) % MOD;
                }
            int c2 = q[k][cr[k]];
            if (cl[k] <= cr[k]) c2--;
            if (c2 > 0) {
                n_r ++;
                n_s = ((long) n_s * c2) % MOD;
            }
            if (n_r > res_r) {
                res_r = n_r;
                res_s = n_s;
            } else if (n_r == res_r) {
                res_s += n_s;
                res_s %= MOD;
            }
//            cout << i << " " << n_r << " " << n_s << " " << c2 << "\n";
        }
        int x = cl[k];
        int y = cr[k];
        if (x > y) swap(x, y);
        if (q[k][y] >= 2 && q[k][x] >= 1) {
            rr[k] = 2;
            ss[k] = ((long) q[k][x] * (q[k][y] - 1)) % MOD;
        } else if (q[k][y] >= 1) {
            rr[k] = 1;
            ss[k] = (q[k][y] + q[k][x]) % MOD;
        } else {
            rr[k] = 0;
            ss[k] = 1;
        }
//        for (int i = 0; i < n; i++) {
//            cout << i << ": " << rr[i] << " " << ss[i] << "\n";
//        }
    }
    cout << res_r << " " << res_s << "\n";

    return 0;
}