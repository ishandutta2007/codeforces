#include <bits/stdc++.h>

using namespace std;

inline int add(int u, int v, int MOD) {
    return (u += v) >= MOD ? u - MOD : u;
}

inline int sub(int u, int v, int MOD) {
    return (u -= v) < 0 ? u + MOD : u;
}

inline int mul(int u, int v, int MOD) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v, int MOD) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u, MOD);
        u = mul(u, u, MOD);
        v >>= 1;
    }
    return res;
}

inline int inv(int u, int MOD) {
    return power(u, MOD - 2, MOD);
}

const int N = 200010;
const int MOD[] = {1000000007, 1000000009, rand() % (int)1e6 + 1};
const int NUM = 3;
const int BASE = 10007;

struct Hash {
    int a[NUM];
    Hash(int u = 0) {
        for (int i = 0; i < NUM; i++) {
            a[i] = u % MOD[i];
        }
    }
    Hash operator + (const Hash &u) const {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = add(a[i], u.a[i], MOD[i]);
        }
        return res;
    }
    Hash operator - (const Hash &u) const {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = sub(a[i], u.a[i], MOD[i]);
        }
        return res;
    }
    Hash operator * (const int u) const {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = mul(a[i], u, MOD[i]);
        }
        return res;
    }
    Hash operator * (const Hash &u) const {
        Hash res(0);
        for (int i = 0; i < NUM; i++) {
            res.a[i] = mul(a[i], u.a[i], MOD[i]);
        }
        return res;
    }
    bool operator == (const Hash &u) const {
        for (int i = 0; i < NUM; i++) {
            if (a[i] != u.a[i]) return 0;
        }
        return 1;
    }
};

int n;
char s[N];
Hash h[N];
Hash hh[N], hhh[N];
Hash p[N];
int num0[N];
int nxt[N];
int numOdd[N];

bool isEqual(int l1, int r1, int l2, int r2) {
    if (l1 > r1) return 1;
    int len = r1 - l1 + 1;
    Hash res1 = h[r1] - (h[l1 - 1] * p[len]);
    Hash res2 = h[r2] - (h[l2 - 1] * p[len]);
    return res1 == res2;
}

bool isH(int l1, int r1, int l2, int r2, Hash *u, Hash *v) {
    if (l1 > r1) return 1;
    int len = num0[r1] - num0[l1 - 1];
    Hash res1 = u[r1] - (u[l1 - 1] * p[len]);
    Hash res2 = v[r2] - (v[l2 - 1] * p[len]);
    return res1 == res2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    cin >> (s + 1);
    num0[0] = 0;
    h[0] = Hash(0);
    p[0] = Hash(1);
    numOdd[0] = 0;
    hh[0] = Hash(0);
    hhh[0] = Hash(0);
    for (int i = 1; i <= n; i++) {
        num0[i] = num0[i - 1] + (s[i] == '0');
        numOdd[i] = numOdd[i - 1] + ((s[i] == '0') && (i % 2));
        h[i] = (h[i - 1] * BASE) + Hash(s[i]);
        p[i] = (p[i - 1] * BASE);
        if (s[i] == '1') {
            hh[i] = hh[i - 1];
            hhh[i] = hhh[i - 1];
        } else {
            hh[i] = (hh[i - 1] * BASE) + Hash(i % 2 + 1);
            hhh[i] = (hhh[i - 1] * BASE) + Hash(((i % 2) ^ 1) + 1);
        }
    }
    nxt[n] = n + 1;
    for (int i = n - 1; i > 0; i--) {
        nxt[i] = nxt[i + 1];
        if (s[i] == '1' && s[i + 1] == '1') nxt[i] = i;
    }
    int q;
    cin >> q;
    while (q--) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;
        Hash *u = (l1 % 2 ? hh : hhh);
        Hash *v = (l2 % 2 ? hh : hhh);
        if (!isH(l1, l1 + len - 1, l2, l2 + len - 1, u, v)) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}