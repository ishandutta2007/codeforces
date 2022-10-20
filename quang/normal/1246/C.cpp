#include <bits/stdc++.h>

using namespace std;

const int N = 2010;
const int MOD = 1000000007;

inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
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

int n, m;
char s[N][N];
int numCol[N][N], numRow[N][N];

struct BIT {
    int t[N];

    void add(int x, int v) {
        while (x < N) {
            t[x] = ::add(t[x], v);
            x += x & -x;
        }
    }
    int get(int x) {
        int res = 0;
        while (x) {
            res = ::add(res, t[x]);
            x -= x & -x;
        }
        return res;
    }
    void add(int l, int r, int x) {
        add(l, x);
        add(r + 1, sub(0, x));
    }
} row[N], col[N];  

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
    }
    if (n == 1 && m == 1) {
        cout << 1 << endl;
        return 0;
    }
    for (int i = n; i; i--) {
        for (int j = m; j; j--) {
            numCol[i][j] = numCol[i + 1][j] + (s[i][j] == 'R');
            numRow[i][j] = numRow[i][j + 1] + (s[i][j] == 'R');
        }
    }
    row[1].add(1, 1, 1);
    col[1].add(1, 1, 1);
    for (int sum = 2; sum <= n + m; sum++) {
        for (int i = 1; i <= n; i++) {
            int j = sum - i;
            if (j < 1 || j > m) continue;
            // last col
            int now = col[j].get(i);
            int cntInRow = numRow[i][j + 1];
            int can = m - cntInRow;
            row[i].add(j + 1, can, now);

            // last row
            now = row[i].get(j);
            int cntInCol = numCol[i + 1][j];
            can = n - cntInCol;
            col[j].add(i + 1, can, now);
        }
    }
    int res = 0;
    res = add(res, col[m].get(n));
    res = add(res, row[n].get(m));
    cout << res << endl;
    return 0;
}