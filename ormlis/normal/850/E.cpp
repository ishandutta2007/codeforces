#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 2e9;
const ll INF = 2e18;
const int maxN = 2e6 + 30;
const int LG = 20;

const int N = 3e5 + 9, mod = 1e9 + 7;

int POW(long long n, long long k) {
    int ans = 1 % mod; n %= mod; if (n < 0) n += mod;
    while (k) {
        if (k & 1) ans = (long long) ans * n % mod;
        n = (long long) n * n % mod;
        k >>= 1;
    }
    return ans;
}
const int inv2 = (mod + 1) >> 1;
#define M (1 << 20)
#define OR 0
#define AND 1
#define XOR 2
struct FWHT{
    int P1[M], P2[M];
    void wt(int *a, int n, int flag = XOR) {
        if (n == 0) return;
        int m = n / 2;
        wt(a, m, flag); wt(a + m, m, flag);
        for (int i = 0; i < m; i++){
            int x = a[i], y = a[i + m];
            if (flag == OR) a[i] = x, a[i + m] = (x + y) % mod;
            if (flag == AND) a[i] = (x + y) % mod, a[i + m] = y;
            if (flag == XOR) a[i] = (x + y) % mod, a[i + m] = (x - y + mod) % mod;
        }
    }
    void iwt(int* a, int n, int flag = XOR) {
        if (n == 0) return;
        int m = n / 2;
        iwt(a, m, flag); iwt(a + m, m, flag);
        for (int i = 0; i < m; i++){
            int x = a[i], y = a[i + m];
            if (flag == OR) a[i] = x, a[i + m] = (y - x + mod) % mod;
            if (flag == AND) a[i] = (x - y + mod) % mod, a[i + m] = y;
            if (flag == XOR) a[i] = 1LL * (x + y) * inv2 % mod, a[i + m] = 1LL * (x - y + mod) * inv2 % mod; // replace inv2 by >>1 if not required
        }
    }
    vector<int> multiply(int n, vector<int> A, vector<int> B, int flag = XOR) {
        assert(__builtin_popcount(n) == 1);
        A.resize(n); B.resize(n);
        for (int i = 0; i < n; i++) P1[i] = A[i];
        for (int i = 0; i < n; i++) P2[i] = B[i];
        wt(P1, n, flag); wt(P2, n, flag);
        for (int i = 0; i < n; i++) P1[i] = 1LL * P1[i] * P2[i] % mod;
        iwt(P1, n, flag);
        return vector<int> (P1, P1 + n);
    }
    vector<int> pow(int n, vector<int> A, long long k, int flag = XOR) {
        assert(__builtin_popcount(n) == 1);
        A.resize(n);
        for (int i = 0; i < n; i++) P1[i] = A[i];
        wt(P1, n, flag);
        for(int i = 0; i < n; i++) P1[i] = POW(P1[i], k);
        iwt(P1, n, flag);
        return vector<int> (P1, P1 + n);
    }
} t;

void solve() {
    int n; cin >> n;
    vector<int> A(1 << n), B(1 << n);
    rep(i, 1 << n) {
        char x; cin >> x;
        if (x == '1') A[i] = 1;
        else B[i] = 1;
    }
    auto C = t.multiply((1 << n), A, B);
    C.resize((1 << n));
    int ans = 0;
    rep(i, 1 << n) {
        ll res = POW(2, __builtin_popcount(i));
        res *= C[i];
        res %= mod;
        ans += res;
        ans %= mod;
    }
    cout << (1ll * ans * 3) % mod << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}