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
using i128 = __int128;
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

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;
const int md = 1e9 + 7;


inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int pw(int a, ll b) {
    int res = 1;
    for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return pw(a, md - 2);
}


void solve() {
    int n; cin >> n;
    if (n == 1) {
        cout << "1\n";
        return;
    }
    vi ways(n + 1);
    ways[n] = 2;
    int l = n;
    int r = n;
    int s = 2;
    for(int i = n - 1; i >= 1; --i) {
        while((r - i) >= i) {
            s = sub(s, ways[r]);
            r--;
        }
        ways[i] = s;
        assert(l == i + 1);
        s = add(s, ways[i]);
        l--;
    }
    for(int i = 1; i <= n; ++i) {
        int res = 1;
        int need = i / 2;
        res = mul(res, pw(2, need));
        res = mul(res, ways[i]);
        cout << mul(res, rev(pw(2, n))) << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}