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

const int INFi = 2e9;
const ll INF = 2e18;
const int LG = 20;
const int maxN = 2e5 + 10;

void solve() {
    int k; cin >> k;
    vi c(k);
    rep(i, k) cin >> c[i];
    vl f(2);
    f[0] = 1;
    f[1] = 1;
    ll s = accumulate(all(c), 0ll);
    ll cur = 2;
    for(int i = 2; cur < s; ++i) {
        ll t = f[i - 1] + f[i - 2];
        f.push_back(t);
        cur += t;
    }
    if (cur > s) {
        cur -= f.back();
        f.pop_back();
    }
    assert(cur <= s);
    if (cur < s) {
        cout << "NO\n";
        return;
    }
    set<pair<int, int>> q;
    rep(i, k) q.insert({c[i], i});
    int last = -1;
    for(int i = (int)f.size() - 1; i >= 0; --i) {
        ll x = f[i];
        if (q.empty() || q.rbegin()->first < x) {
            cout << "NO\n";
            return;
        }
        auto [ct, j] = *q.rbegin();
        q.erase(prev(q.end()));
        c[j] -= x;
        if (last != -1 && c[last] > 0) q.insert({c[last], last});
        last = j;
    }
    assert(q.empty());
    assert(last == -1 || c[last] == 0);
    cout << "YES\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}