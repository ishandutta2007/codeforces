#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

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


struct BIT {
    int t[N];

    void add(int x, int v) {
        while (x < N) {
            t[x] += v;
            x += (x & -x);
        }
    }

    int get(int x) {
        int res = 0;
        while (x) {
            res += t[x];
            x -= (x & -x);
        }
        return res;
    }

    int get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
} tFix;

int n;
int a[N];
int used[N];
int b[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int cnt = 0;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] != -1) {
            res = add(res, tFix.get(a[i] + 1, n));
            used[a[i]] = 1;
            tFix.add(a[i], 1);
        } else cnt++;
    }
    int num = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) b[++num] = i;
    }
    int now = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == -1) {
            now++;
        } else {
            int pos = lower_bound(b + 1, b + num + 1, a[i]) - b - 1;
            res = add(res, mul(cnt - now, mul(pos, inv(cnt))));
            res = add(res, mul(now, mul(cnt - pos, inv(cnt))));

        }
    }

    res = add(res, mul(cnt, mul(cnt - 1, inv(4))));
    cout << res << endl;
    return 0;
}