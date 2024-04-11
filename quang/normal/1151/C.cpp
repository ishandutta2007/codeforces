#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int MOD = 1000000007;

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

int get(long long u) {
    int a[2] = {0, 0};
    long long cur = 1;
    int id = 0;
    while (u > 0) {
        long long foo = min(cur, u);
        a[id] = add(a[id], foo % MOD);
        u -= foo;
        id ^= 1;
        cur *= 2ll;
    }
    return add(mul(a[0], a[0]), mul(a[1], add(a[1], 1)));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long l, r;
    cin >> l >> r;
    cout << sub(get(r), get(l - 1)) << endl;
    return 0;
}