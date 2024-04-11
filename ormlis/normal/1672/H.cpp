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
const int maxN = 4e5 + 10;
const int LG = 100;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vi tp(n, -1);
    rep(i, n - 1) {
        if (s[i] == s[i + 1]) {
            if (s[i] == '0') tp[i + 1] = 0;
            else tp[i + 1] = 1;
        }
    }
    vi s0(n), s1(n);
    for(int i = 1; i < n; ++i) {
        s0[i] = s0[i - 1];
        s1[i] = s1[i - 1];
        if (tp[i] == 0) s0[i]++;
        if (tp[i] == 1) s1[i]++;
    }
    rep(_, q) {
        int l, r; cin >> l >> r;
        l--;
        r--;
        int c0 = s0[r] - s0[l];
        int c1 = s1[r] - s1[l];
        cout << max(c0, c1) + 1 << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}