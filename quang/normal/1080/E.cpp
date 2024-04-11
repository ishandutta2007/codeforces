#include <bits/stdc++.h>

using namespace std;

const int N = 260;
const int MOD = 1000000007;
const int BASE = 10007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) u -= MOD;
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) u += MOD;
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

int n, m;
char a[N][N];
int p[30];
int cur[N];
int val[N];
int b[N];
int c[N * 2];
int len[N * 2];

bool check(int u) {
    if (!u) return 1;
    return u == (u & -u);
}

bool checkBound(int l, int r, int sz) {
    return l > 0 && r <= sz;
}

int getRes(int now) {
    for (int i = 1; i <= n; i++) {
        c[i * 2 - 1] = b[i];
        c[i * 2] = now;
    }
    int sz = n * 2 - 1;
    int maxRight = 0;
    int id = -1;
    
    for (int i = 1; i <= sz; i++) {
        int cur = -1;
        if (maxRight <= i) {
            cur = i;
        } else {
            int prefId = id * 2 - i;
            cur = min(maxRight, i + len[prefId]);   
        }
        while (checkBound(i * 2 - cur - 1, cur + 1, sz) && c[i * 2 - cur - 1] == c[cur + 1]) cur++;
        len[i] = cur - i;
        if (maxRight < cur) {
            maxRight = cur;
            id = i;
        }
    }

    int res = 0;
    for (int i = 1; i <= sz; i++) {
        if (i % 2) {
            if (c[i] >= 0) {
                res += (len[i] / 2) + 1;
            }
        } else {
            res += (len[i] + 1) / 2;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i < 30; i++) {
        p[i] = mul(p[i - 1], BASE);
    }
    for (int i = 1; i <= n; i++) {
        cin >> (a[i] + 1);
    }
    long long res = 0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cur[j] = 0;
            val[j] = 0;
        }

        for (int j = i; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                int id = a[k][j] - 'a';
                cur[k] = add(cur[k], p[id]);
                val[k] ^= (1 << id);
            }
            int curVal = 0;
            for (int k = 1; k <= n; k++) {
                if (check(val[k])) {
                    b[k] = cur[k];
                }  else {
                    b[k] = --curVal;
                }
            }
            curVal--;
            res += getRes(curVal);
        }
    }
    cout << res << endl;
    return 0;
}