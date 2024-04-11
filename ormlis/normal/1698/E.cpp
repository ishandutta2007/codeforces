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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 5e5 + 20;
const int LG = 30;


const int md = 998244353; //1e9 + 9;

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
    int r = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) r = mul(r, a);
    return r;
}

int rev(int a) {
    return binpow(a, md - 2);
}

const int maxF = 2e5 + 5;
int fact[maxF];
int rfact[maxF];

void initF() {
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

vi rev(vi a) {
    int n = a.size();
    vi was(n, -1);
    rep(i, n) if (a[i] != -1) was[a[i]] = i;
    return was;
}

void solve() {
    int n, s;
    cin >> n >> s;
    vi a(n);
    rep(i, n) cin >> a[i];
    vi b(n);
    rep(i, n) cin >> b[i];
    vi was(n, -1);
    rep(i, n) {
        a[i]--;
        if (b[i] != -1) {
            b[i]--;
        }
    }
    a = rev(a);
    b = rev(b);
    rep(i, n) if (b[i] != -1) was[b[i]] = i;
    vi cur(n);
    int cnt = 0;
    int ans = 1;
    rep(i, s) {
        if (was[a[i]] == -1) cnt++;
        else cur[a[i]] = 1;
    }
    for (int i = 0; i < n; ++i) {
        if (i + s < n) {
            if (was[a[i + s]] == -1) cnt++;
            else cur[a[i + s]] = 1;
        }
        if (b[i] != -1) {
            if (cur[b[i]] != 0) {
                cur[b[i]] = 0;
                continue;
            }
            cout << "0\n";
            return;
        }
        ans = mul(ans, cnt);
        cnt--;
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    initF();
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}