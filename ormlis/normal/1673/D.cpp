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
const int maxN = 4 * 1e4 + 1;
const int maxP = 1000;
const int LG = 30;
const int md = 1e9 + 7; //998244353; //1e9 + 9;

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

map<ll, int> get_cnt(ll x) {
    map<ll, int> res;
    for (ll i = 2; i * i <= x; ++i) {
        while (x % i == 0) {
            x /= i;
            res[i]++;
        }
    }
    if (x != 1) res[x]++;
    return res;
}

void solve() {
    ll b, q, n;
    cin >> b >> q >> n;
    ll c, p, m;
    cin >> c >> p >> m;
    if (p % q != 0) {
        cout << "0\n";
        return;
    }
    if (c < b || (c - b) % q != 0 || (c + p * (m - 1)) > (b + q * (n - 1))) {
        cout << "0\n";
        return;
    }
    if (c - p < b) {
        cout << "-1\n";
        return;
    }
    if ((c + p * m) > (b + q * (n - 1))) {
        cout << "-1\n";
        return;
    }
    // lcm(q, x) == p
    auto cntp = get_cnt(p);
    auto cntq = get_cnt(q);
    ll must = 1;
    for (auto &[prime, k] : cntp) {
        if (cntq[prime] != k) {
            rep(_, k) must *= prime;
        }
    }
    int ans = 0;
    auto check = [&](ll x) {
        ll ct1 = (p / x) * (p / x);
        ct1 %= md;
        ans = add(ans, ct1);
    };
    ll can = p / must;
    for (ll d = 1; d * d <= can; ++d) {
        if (can % d != 0) continue;
        check(d * must);
        if (d * d != can) check(must * can / d);
    }
    cout << ans << '\n';
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}