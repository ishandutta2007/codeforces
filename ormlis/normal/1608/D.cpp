#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
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
const int maxN = 2e5;
const int LG = 30;

const int md = 998244353; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void init() {
    fact[0] = 1;
    for (int i = 1; i < maxF; ++i) fact[i] = mul(fact[i - 1], i);
    rfact[maxF - 1] = rev(fact[maxF - 1]);
    for (int i = maxF - 1; i >= 1; --i) {
        rfact[i - 1] = mul(rfact[i], i);
    }
}

int C(int n, int k) {
    if (k < 0 || n < k) return 0;
    return mul(fact[n], mul(rfact[k], rfact[n - k]));
}


void solve() {
    init();
    int n;
    cin >> n;
    int cnt1 = 0;
    int cnt2 = 0;
    ar<int, 2> deg_in = {0, 0};
    ar<int, 2> deg_out = {0, 0};
    bool was = false;
    int k = 0;

    rep(i, n) {
        string s;
        cin >> s;
        int a, b;
        if (s[0] == '?') a = -1;
        else if (s[0] == 'W') a = 0;
        else a = 1;

        if (s[1] == '?') b = -1;
        else if (s[1] == 'W') b = 0;
        else b = 1;

        if (a != -1) a ^= 1;
        if (a != -1) deg_in[a]++;
        else cnt1++;
        if (b != -1) deg_out[b]++;
        else cnt2++;

        if (a != -1 && b != -1 && a != b) was = true;
        if (a == -1 && b == -1) k++;
    }
    int ans = 0;
    for(int t = 0; t <= cnt1; ++t) {
        int r = deg_in[0] + t - deg_out[0];
        int r2 = deg_in[1] + (cnt1 - t) - deg_out[1];
        assert(r + r2 == cnt2);
        ans = add(ans, mul(C(cnt1, t), C(cnt2, r)));
    }
    if (!was) {
        ans = sub(ans, binpow(2, k));
        if (deg_in[0] == 0 && deg_out[0] == 0) {
            ans = add(ans, 1);
        }
        if (deg_in[1] == 0 && deg_out[1] == 0) {
            ans = add(ans, 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}