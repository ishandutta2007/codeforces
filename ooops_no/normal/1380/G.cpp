#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int MOD = 998244353;

int add(int a, int b) {
    return a + b < MOD ? a + b : a + b - MOD;
}

int sub(int a, int b) {
    return a - b >= 0 ? a - b : a - b + MOD;
}

int mul(int a, int b) {
    return (long long) a * b % MOD;
}

int binpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) {
            res = mul(res, a);
        }
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

int inv(int a) {
    return binpow(a, MOD - 2);
}

int divide(int a, int b) {
    return mul(a, inv(b));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(c.rbegin(), c.rend());
    for (int i = 1; i < n; i++) c[i] += c[i - 1];
    for (int i = 1; i <= n; i++){
        int ans = 0, now = 0;
        for (int j = 0; j < n; j += i){
            ans = add(ans, mul(c[min(n - 1, j + i - 1)] - (j > 0 ? c[j - 1] : c[j]), now++));
        }
        cout << divide(ans, n) << ' ';
    }
    return 0;
}