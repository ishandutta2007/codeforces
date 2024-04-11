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
const int maxN = 1e3 + 5;
const int LG = 19;
int k;

vector<pair<int, int>> multiply(const vector<pair<int, int>> &A, const vector<pair<int, int>> &B) {
    auto res = A;
    for(auto &[x, y] : B) {
        rep(_, y) {
            if (res.empty() || res.back().first != x) res.emplace_back(x, 0);
            res.back().second++;
            if (res.back().second == k) res.pop_back();
        }
    }
    return res;
}

int count_pep(vector<pair<int, int>> &A) {
    int ans = 0;
    for(auto &[x, y] : A) ans += y;
    return ans;
}

vector<pair<int, int>> binpow(const vector<pair<int, int>> &A, int b) {
    if (b == 1) return A;
    if (b % 2) return multiply(A, binpow(A, b - 1));
    auto m = binpow(A, b / 2);
    return multiply(m, m);
}

void solve() {
    int n; cin >> n;
    int m; cin >> k >> m;
    vi a(n);
    rep(i, n) cin >> a[i];
    vector<pair<int, int>> b;
    for(auto &x : a) {
        if (b.empty() || b.back().first != x) b.emplace_back(x, 0);
        b.back().second++;
        if (b.back().second == k) b.pop_back();
    }
    if (b.size() == 1) {
        ll res = 1ll * count_pep(b) * m;
        cout << res % k << '\n';
        return;
    }
    if (m == 1) {
        cout << count_pep(b) << '\n';
        return;
    }
    auto A = b;
    auto B = b;
    int sz = count_pep(b);
    auto C = multiply(A, B);
    int szC = count_pep(C);
    if (szC > sz) {
        ll result = szC + 1ll * (szC - sz) * (m - 2);
        cout << result << '\n';
        return;
    }
    auto res = binpow(b, m);
    cout << count_pep(res) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}