#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int MOD = 998244353;

vector<int> calc(vector<bool> a) {
    int n = a.size();
    int m = n / 2;
    vector<int> d(m + 1);
    vector<int> d2(m + 1);
    vector<int> d3(m + 1);
    d[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            d3[j] = d2[j];
            d2[j] = d[j];
        }
        if (i > 0 && !a[i] && !a[i - 1]) {
            for (int j = 1; j <= m; j++) {
                d[j] += d3[j - 1];
                if (d[j] >= MOD) {
                    d[j] -= MOD;
                }
            }
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> r(n);
    vector<bool> c(m);
    for (int i = 0; i < k; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;x2--;y1--;y2--;
        r[x1] = r[x2] = true;
        c[y1] = c[y2] = true;
    }

    vector<int> dr = calc(r);
    vector<int> dc = calc(c);

    int er = 0;
    for (int i = 0; i < n; i++) if (!r[i]) er++;
    int ec = 0;
    for (int i = 0; i < m; i++) if (!c[i]) ec++;

    int nn = max(n, m) + 1;
    vector<vector<int>> C(nn, vector<int>(nn));
    for (int i = 0; i < nn; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
            if (C[i][j] >= MOD) {
                C[i][j] -= MOD;
            }
        }
    }

//    for (int i : dr) {
//        cout << i << " ";
//    }
//    cout << "\n";
//    for (int i : dc) {
//        cout << i << " ";
//    }
//    cout << "\n";
    vector<long> fact(nn + 1);
    fact[0] = 1;
    for (int i = 1; i <= nn; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }

    long res = 0;
    for (int i = 0; i < dr.size(); i++) {
        for (int j = 0; j < dc.size(); j++) {
            long x = dr[i];
            x *= dc[j];
            x %= MOD;
            if (er - 2 * i < 0) continue;
            x *= C[er - 2 * i][j];
            x %= MOD;
            if (ec - 2 * j < 0) continue;
            x *= C[ec - 2 * j][i];
            x %= MOD;
            x *= fact[i];
            x %= MOD;
            x *= fact[j];
            x %= MOD;
            res += x;
            res %= MOD;
        }
    }
    cout << res;


    return 0;
}