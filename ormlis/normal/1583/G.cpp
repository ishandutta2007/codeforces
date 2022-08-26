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

const int md = 1e9 + 7; //1e9 + 7, 1e9 + 9

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
    for(; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res,  a);
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

struct fenwick {
    int n{};
    vector<int> fenw{};

    void build(int k) {
        n = k + 5;
        fenw.resize(n);
    }

    void upd(int i, int x) {
        for (; i < n; i = i | (i + 1)) fenw[i] = add(fenw[i], x);
    }

    int get(int i) {
        int res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res = add(res, fenw[i]);
        return res;
    }

    int get(int l, int r) {
        if (l > r) return 0;
        return sub(get(r), get(l - 1));
    }
};

void solve() {
    int n; cin >> n;
    vec<ar<int, 3>> abi(n);
    rep(i, n) {
        cin >> abi[i][1] >> abi[i][0];
        abi[i][2] = i;
    }
    sort(all(abi));
    vi b(n);
    vi a(n);
    const int INFi = 2e9;
    rep(i, n) b[i] = abi[i][0];
    rep(i, n) a[i] = abi[i][1];
    vi mn(n, INFi);
    vpi ord2(n);
    rep(i, n) {
        ord2[i] = {a[i], i};
    }
    sort(all(ord2));
    vi pos2(n);
    rep(i, n) pos2[ord2[i].second] = i;
    for(int i = n - 1; i >= 0; --i) {
        if (i + 1 < n) mn[i] = mn[i + 1];
        mn[i] = min(mn[i], ord2[i].second);
    }
    vi pos(n);
    rep(i, n) pos[abi[i][2]] = i;
    int q; cin >> q;
    vector<int> qq(q);
    rep(i, q) {
        cin >> qq[i];
        qq[i]--;
        qq[i] = pos[qq[i]];
    }
    vi dp(n, 0);
    fenwick f;
    f.build(n * 2 + 10);
    rep(i, n) {
        dp[i] = add(1, f.get(a[i], n * 2 + 5));
        f.upd(a[i], dp[i]);
    }
    int w = -1;
    vi orda = qq;
    sort(all(orda), [&] (const int &i, const int &j) {
        return a[i] < a[j];
    });
    set<int> have;
    rep(i, q) have.insert(qq[i]);
    int t = 0;
    int answer = 0;
    int d = n - 1;
    while(t < q) {
        if (a[orda[t]] <= w) {
            have.erase(orda[t]);
            t++;
            continue;
        }
        int mx = *have.rbegin();
        while(d >= mx) {
            f.upd(a[d], sub(0, dp[d]));
            d--;
        }
        answer = add(answer, add(1, f.get(w + 1, 2 * n + 5)));
        w = a[mx];
    }
    cout << answer << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}