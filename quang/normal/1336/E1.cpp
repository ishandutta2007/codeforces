#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int D = 100;

#define int long long

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

long long basis[D]; // basis[i] keeps the mask of the vector whose f value is i

int sz; // Current size of the basis

void insertVector(long long mask) {
    for (int i = 0; i < m; i++) {
        if ((mask & 1ll << i) == 0) continue; // continue if i != f(mask)

        if (!basis[i]) { // If there is no basis vector with the i'th bit set, then insert this vector into the basis
            basis[i] = mask;
            ++sz;
            
            return;
        }

        mask ^= basis[i]; // Otherwise subtract the basis vector from this vector
    }
}

int res[D];

void go(int u, long long mask) {
    if (u == m) {
        res[__builtin_popcountll(mask)]++;
        return;
    }
    if (basis[u]) {
        go(u + 1, mask);
        go(u + 1, mask ^ basis[u]);
    } else {
        go(u + 1, mask);
    }
}

map<pair<long long, int>, int> dp;

main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    sz = 0;
    for (int i = 1; i <= n; i++) {
        long long u;
        cin >> u;
        insertVector(u);
    }
    for (int i = 0; i < m; i++) {
        if (!basis[i]) continue;
        for (int j = 0; j < i; j++) {
            if (!basis[j]) continue;
            if (basis[j] >> i & 1ll) basis[j] ^= basis[i];
        }
    }
    if (sz <= 23) {
        go(0, 0ll);
    } else {
        long long totMask = (1ll << m) - 1;
        for (int i = 0; i < m; i++) {
            if (basis[i]) totMask ^= (1ll << i);
        }
        dp[{0ll, 0}] = 1;
        for (int i = 0; i < m; i++) {
            if (!basis[i]) continue;
            map<pair<long long, int>, int> cur;
            for (auto u : dp) {
                long long mask = u.first.first;
                int num = u.first.second;
                int val = u.second;
                int newVal = add(cur[{mask, num}], val);
                cur[{mask, num}] = newVal;
                newVal = add(cur[{mask ^ (totMask & basis[i]), num + 1}], val);
                cur[{mask ^ (totMask & basis[i]), num + 1}] = newVal;
            }
            dp.swap(cur);
        }
        for (auto u : dp) {
            long long mask = u.first.first;
            int num = u.first.second;
            int val = u.second;
            res[__builtin_popcountll(mask) + num] = add(res[__builtin_popcountll(mask) + num], val);
        }
    }
    int foo = 1;
    for (int i = 1; i <= n - sz; i++) {
        foo = add(foo, foo);
    }
    for (int i = 0; i <= m; i++) cout << mul(foo, res[i]) << ' ';
        cout << endl;
    return 0;
}