#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int MOD;

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

int n, k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> MOD >> k;
    map<int, int> m;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int u;
        cin >> u;
        int x = power(u, 4);
        int y = mul(u, k);
        x = sub(x, y);
        res += m[x];
        m[x]++;
    }
    cout << res << endl;
    return 0;
}