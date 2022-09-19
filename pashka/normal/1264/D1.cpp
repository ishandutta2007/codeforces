#include <bits/stdc++.h>
#define long long long int
using namespace std;

// @author: pashka

#define MOD 998244353

long sum(long a, long b) {
    long res = (a + b) % MOD;
    if (res < 0) res += MOD;
    return res;
}

long mult(long a, long b) {
    long res = (a * b) % MOD;
    if (res < 0) res += MOD;
    return res;
}

long power(long a, long b) {
    a %= MOD;
    if (a < 0) a += MOD;
    long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

long inv(long a) {
    return power(a, MOD - 2);
}

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    vector<vector<long>> dl(n + 1, vector<long>(n + 1));
    dl[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[i] == '?' || s[i] == '(') {
                dl[i + 1][j + 1] = sum(dl[i + 1][j + 1], dl[i][j]);
            }
            if (s[i] == '?' || s[i] == ')') {
                dl[i + 1][j] = sum(dl[i + 1][j], dl[i][j]);
            }
        }
    }
    vector<vector<long>> dr(n + 1, vector<long>(n + 1));
    dr[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (s[n - 1 - i] == '?' || s[n - 1 - i] == ')') {
                dr[i + 1][j + 1] = sum(dr[i + 1][j + 1], dr[i][j]);
            }
            if (s[n - 1 - i] == '?' || s[n - 1 - i] == '(') {
                dr[i + 1][j] = sum(dr[i + 1][j], dr[i][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            dl[i][j] += dl[i][j + 1];
            dr[i][j] += dr[i][j + 1];
            dl[i][j] %= MOD;
            dr[i][j] %= MOD;
        }
    }

    long res = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            long z = mult(dl[i][j], dr[n - i][j]);
            if (s[i - 1] == '?' || s[i - 1] == ')') {
                z = sum(z, -mult(dl[i - 1][j], dr[n - i][j]));
            }
            if (s[i - 1] == '?' || s[i - 1] == '(') {
                z = sum(z, -mult(dl[i - 1][j], dr[n - i][j]));
            }
//            cout << i << " " << j << " " << dl[i][j] << " " << dr[n - i][j] << " " << z << "\n";
            res = sum(res, z);
        }
    }
    cout << res << "\n";

    return 0;
}