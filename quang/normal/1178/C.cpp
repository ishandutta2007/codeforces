#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

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


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w,h;
    cin >> w >> h;
    int res = 1;   
    for (int i = 1; i <= w + h; i++) {
        res = mul(res, 2);
    }
    cout << res << endl;
    return 0;
}