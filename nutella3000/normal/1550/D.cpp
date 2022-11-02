#include <bits/stdc++.h>
using namespace std;
     
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
mt19937 rnd;

const int inf = 2e9 + 3, mod = 1e9 + 7;
const int max_n = 2e5 + 3;

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = a * a % mod)
        if (b & 1) res = res * a % mod;
    return res;
}

int inv(int a) { return binpow(a, mod - 2); }

int fact[max_n], ifact[max_n];

void init() {
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < max_n; ++i)
        fact[i] = fact[i - 1] * i % mod, ifact[i] = ifact[i - 1] * inv(i) % mod;
}

int Cnk(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

void run() {
    int n, l, r;
    cin >> n >> l >> r;

    int q1 = min(r - n, 1 - l);

    int r1 = q1 * (Cnk(n, n / 2) + (n % 2 == 1 ? Cnk(n, n / 2 + 1) : 0)) % mod;
    int r2 = 0;

    for (int c = q1 + 1; c <= q1 + n; ++c) {
        int i = max(1ll, r - c + 1);
        if (i - l < c && i <= n) break;
        int d1 = min(r - c, c + l - 1);
        d1 = max(0ll, min(d1, n));
        int d2 = min(n, r - c) - max(c + l, 1ll) + 1;

        //cout << c << " " << d1 << " " << d2 << endl;

        r2 += Cnk(d2, n / 2 - d1);
        if (n % 2 == 1) r2 += Cnk(d2, n / 2 + 1 - d1);
    }

    cout << (r1 + r2) % mod<< endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);

#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    init();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}