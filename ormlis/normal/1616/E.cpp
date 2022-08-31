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
const int maxN = 605;
const int LG = 20;

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if (s < t) {
        cout << "0\n";
        return;
    }
    {
        auto s2 = s;
        sort(all(s2));
        if (s2 >= t) {
            cout << "-1\n";
            return;
        }
    }
    int pref = 0;
    while (pref < n && s[pref] == t[pref]) pref++;
    for (int i = 1; i <= min(n - 1, pref); ++i) {
        if (s[i] < s[i - 1]) {
            cout << "1\n";
            return;
        }
    }
    assert(pref != n);
    assert(s[pref] > t[pref]);
    ll ans = INF;
    for (int i = pref; i < n; ++i) {
        if (s[i] < t[pref]) {
            ans = min(ans, (ll)i - pref);
        }
        if (pref > 0 && s[i] < t[pref - 1]) {
            ans = min(ans, (ll)i - pref + 1);
        }
    }
    fenwick f;
    f.build(n);
    vector<vector<int>> pos(26);
    for (int i = n - 1; i >= pref; --i) {
        pos[s[i] - 'a'].push_back(i);
    }
    for (int i = 1; i < n; ++i) f.upd(i, 1);
    ll cur = 0;
    for (int pref2 = pref; pref2 < n - 1; ++pref2) {
        int c = (t[pref2] - 'a');
        if (pos[c].empty()) break;
        int p = pos[c].back();
        pos[c].pop_back();
        cur += f.get(p) - pref2;
        f.upd(0, 1);
        f.upd(p, -1);
        int nxt = (t[pref2 + 1] - 'a');
        for (int c2 = 0; c2 < nxt; ++c2) {
            if (pos[c2].empty()) continue;
            int b = pos[c2].back();
            ans = min(ans, cur + f.get(b) - (pref2 + 1));
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}