#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int MOD = 1e9 + 7, N = 4e5 + 10;
int f[N];

int mul(int a, int b) {
    return (1ll * a * b % MOD);
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

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int cnk(int n, int k) {
    return mul(f[n], mul(inv(f[k]), inv(f[n - k])));
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        f[i] = mul(f[i - 1], i);
    }
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }
    while (a.size() > 0 && a.back() == 0) {
        a.pop_back();
    }
    n = a.size();
    if (n == 0) {
        cout << 0 << endl;
    } else {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = add(ans, cnk(a[i] + i, i + 1));
        }
        cout << ans << endl;
    }
    return 0;
}