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
#define f0r(a, b) for (int i = (a); i < (b); ++i)
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
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

void solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << "A 1 0 0" << endl << "1" << endl << endl << endl;
        return;
    }
    vector<int> t(n);
    {
        cout << "Q ";
        int k = n / 2;
        cout << k << ' ';
        rep(i, k) {
            cout << i * 2 + 1 << ' ' << i * 2 + 2 << ' ';
        }
        cout << endl;
        str s;
        cin >> s;
        rep(i, k) {
            t[i * 2] = s[i] - '0';
            t[i * 2] ^= 1;
        }
    }
    if (n >= 3) {
        cout << "Q ";
        int k = (n - 1) / 2;
        cout << k << ' ';
        rep(i, k) {
            cout << i * 2 + 2 << ' ' << i * 2 + 3 << ' ';
        }
        cout << endl;
        str s;
        cin >> s;
        rep(i, k) {
            t[i * 2 + 1] = s[i] - '0';
            t[i * 2 + 1] ^= 1;
        }
    }
    {
        cout << "Q 1 1 " << n << endl;
        str s;
        cin >> s;
        t[n - 1] = s[0] - '0';
        t[n - 1] ^= 1;
    }
    int d = 0;
    while (d < n && t[d] == 0) d++;
    if (d == n) {
        cout << "A 0 0 " << n << endl;
        cout << endl << endl;
        for (int i = 1; i <= n; ++i) cout << i << ' ';
        cout << endl;
        return;
    }
    int start = (d + 1) % n;
    vector<int> r(n);
    int lst = start;
    vector<int> cyc;
    for (int i = start; i < start + n; ++i) {
        r[i % n] = lst;
        if (t[i % n] == 1) {
            lst = (i + 1) % n;
            cyc.push_back(lst);
        }
    }
    if (cyc.size() == 2) {
        int cnt1 = 0;
        rep(i, n) if (r[i] == lst) cnt1++;
        cout << "A " << cnt1 << ' ' << n - cnt1 << " 0" << endl;
        rep(i, n) if (r[i] == lst) cout << i + 1 << ' ';
        cout << endl;
        rep(i, n) if (r[i] != lst) cout << i + 1 << ' ';
        cout << endl;
        cout << endl;
        return;
    }
    // used : 3
    int q = 4;
    auto ask = [&](vpi v) {
        assert(!v.empty());
        q--;
        assert(q >= 0);
        cout << "Q " << v.size() << ' ';
        for (auto &[x, y] : v) cout << x << ' ' << y << ' ';
        cout << endl;
        str s;
        cin >> s;
        return s;
    };
    int sz = cyc.size();
    vi t2(sz, -1);
    int cnt = 0;
    while (cnt < sz) {
        vi us(sz);
        vpi cur;
        vi cur2;
        rep(i, sz) {
            if (t2[i] != -1) continue;
            int j = (i + 2) % sz;
            if (us[i] || us[j]) continue;
            us[i] = us[j] = 1;
            cur2.push_back(i);
            cur.emplace_back(cyc[i] + 1, cyc[j] + 1);
        }
        str res = ask(cur);
        rep(i, (int) cur2.size()) {
            t2[cur2[i]] = res[i] - '0';
            t2[cur2[i]] ^= 1;
            cnt++;
        }
    }
    vi col(sz, -1);
    col[0] = 1;
    col[1] = 2;
    for (int i = 2; i < sz; ++i) {
        if (t2[i - 2] == 0) {
            col[i] = col[i - 2];
            continue;
        }
        col[i] = col[i - 2] ^ col[i - 1];
    }
    vi res(n, -1);
    rep(i, sz) res[cyc[i]] = col[i] - 1;
    rep(i, n) {
        if (res[i] == -1) {
            res[i] = res[r[i]];
        }
        assert(res[i] != -1);
    }
    vvi ans(3);
    rep(i, n) {
        ans[res[i]].push_back(i);
    }
    cout << "A ";
    rep(i, 3) cout << ans[i].size() << ' ';
    cout << endl;
    rep(i, 3) {
        for (auto &x : ans[i]) cout << x + 1 << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}