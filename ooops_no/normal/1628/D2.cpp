#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int MOD = 1e9 + 7, N = 1e6 + 10;
int f[N];

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b) {
    return (a * b % MOD);
}

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n /= 2;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

int cnk(int n, int k) {
    if (n < 0) return 1;
    if (k > n || k < 0) return 0;
    return mul(f[n], inv(mul(f[n - k], f[k])));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        f[i] = (i == 0 ? 1 : mul(f[i - 1], i));
    }
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            ans = add(ans, mul(mul(i, k), mul(cnk(n - i - 1, m - i), inv(binpow(2, n - i)))));
        }
        cout << ans << endl;
    }
    return 0;
}