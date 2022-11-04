#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long

using namespace std;

const int MOD = 998244353;

inline int lgput(int a, ll b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

int main() {
#ifdef HOME
    ifstream cin("B.in");
    ofstream cout("B.out");
#endif
    int n, m, l, r;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> l >> r;

    if((1LL * n * m) % 2) {
        cout << lgput(r - l + 1, 1LL * n * m) % MOD;
        return 0;
    }

    auto get = [&](int x) {
        return (x + 1) / 2;
    };

    int even = r / 2 - (l - 1) / 2;
    int odd = r - l + 1 - even;
    ll A = 1LL * get(n) * get(m) + 1LL * (n / 2) * (m / 2);
    ll B = 1LL * get(n) * (m / 2) + 1LL * (n / 2) * get(m);

    int A0 = (lgput(r - l + 1, A) - lgput(even - odd, A) + MOD) % MOD;
    int B0 = (lgput(r - l + 1, B) - lgput(even - odd, B) + MOD) % MOD;
    A0 = (1LL * A0 * lgput(2, MOD - 2)) % MOD;
    B0 = (1LL * B0 * lgput(2, MOD - 2)) % MOD;

    int ans = (1LL * A0 * B0 + 1LL * (lgput(r - l + 1, A) - A0 + MOD) * (lgput(r - l + 1, B) - B0 + MOD)) % MOD;
    cout << ans;

    return 0;
}