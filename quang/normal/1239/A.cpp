#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
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
int f[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    f[1] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = add(f[i - 1], f[i - 2]);
    }
    int n, m;
    cin >> n >> m;
    int res = add(f[n], f[m]);
    res = sub(res, 1);
    res = mul(res, 2);
    cout << res << endl;
    return 0;
}