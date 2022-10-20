#include <bits/stdc++.h>

using namespace std;

const int N = 250010;

int n, m;

int add(int u, int v) {
    return (u += v) >= m ? u - m : u;
}

int mul(int u, int v) {
    return 1ll * u * v % m;
}

int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

int inv(int u) {
    return power(u, m - 2);
}

int f[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        f[i] = mul(f[i - 1], i);
    }   
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int now = power(n - i + 1, 2);
        now = mul(now, f[i]);
        now = mul(now, f[n - i]);
        res = add(res, now);
    }
    cout << res << endl;
    return 0;
}