#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) FOR(i, 0, (n)-1)
#define sqr(x) ((x) * (x))
#define all(x) (x).begin(), (x).end()
#define reset(x, y) memset(x, y, sizeof(x))
#define uni(x) (x).erase(unique(all(x)), (x).end());
#define BUG(x) cerr << #x << " = " << (x) << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define _1 first
#define _2 second

const int maxn = 412345;
const int MOD = 1e9 + 7;

int n, q;

struct Seg {
    int l, r;
    ll val, mask, lzy, lmsk;
} T[maxn << 2];

ll mask[312], fac[65];

ll pow_mod(ll a, ll k) {
    ll ret = 1;
    while (k) {
        if (k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

void build(int o, int l, int r) {
    T[o].l = l, T[o].r = r, T[o].val = T[o].lzy = 1;
    if (l != r) {
        int m = l + r >> 1;
        build(o << 1, l, m);
        build(o << 1 | 1, m + 1, r);
    }
}

inline void push_down(int o) {
    T[o << 1].lmsk |= T[o].lmsk, T[o << 1].lzy = T[o << 1].lzy * T[o].lzy % MOD;
    T[o << 1 | 1].lmsk |= T[o].lmsk, T[o << 1 | 1].lzy = T[o << 1 | 1].lzy * T[o].lzy % MOD;
    T[o].lmsk = 0, T[o].lzy = 1;
}

inline void push_up(int o) {
    T[o].mask = T[o << 1].mask | T[o << 1].lmsk;
    T[o].mask |= T[o << 1 | 1].mask | T[o << 1 | 1].lmsk;
    T[o].val = T[o << 1].val * pow_mod(T[o << 1].lzy, T[o << 1].r - T[o << 1].l + 1) % MOD;
    T[o].val = T[o].val * T[o << 1 | 1].val % MOD * pow_mod(T[o << 1 | 1].lzy, T[o << 1 | 1].r - T[o << 1 | 1].l + 1) % MOD;
}

void update(int o, int l, int r, int x) {
    if (l <= T[o].l && T[o].r <= r) {
        T[o].lmsk |= mask[x];
        T[o].lzy = T[o].lzy * x % MOD;
        return;
    }
    push_down(o);
    int m = T[o].l + T[o].r >> 1;
    if (l <= m) update(o << 1, l, r, x);
    if (m < r) update(o << 1 | 1, l, r, x);
    push_up(o);
}

pair<int, ll> query(int o, int l, int r) {
    if (l <= T[o].l && T[o].r <= r)
        return {T[o].val * pow_mod(T[o].lzy, T[o].r - T[o].l + 1) % MOD, T[o].mask | T[o].lmsk};
    push_down(o);
    ll prod = 1, msk = 0;
    int m = T[o].l + T[o].r >> 1;
    if (l <= m) {
        auto now = query(o << 1, l, r);
        prod = prod * now._1 % MOD;
        msk |= now._2;
    }
    if (m < r) {
        auto now = query(o << 1 | 1, l, r);
        prod = prod * now._1 % MOD;
        msk |= now._2;
    }
    push_up(o);
    return {int(prod), msk};
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> primes;
    bool vis[312] = {};
    FOR(i, 2, 300) if (!vis[i]) {
            primes.eb(i);
            for (int j = i * i; j <= 300; j += i) vis[j] = true;
        }
    assert(primes.size() == 62);
    FOR(i, 1, 300) REP(j, 62) if (i % primes[j] == 0) mask[i] |= (1LL << j);
    REP(i, 62) {
        int now = primes[i];
        fac[i] = (now - 1) * pow_mod(now, MOD - 2) % MOD;
    }
    build(1, 1, 1 << 19);
    cin >> n >> q;
    FOR(i, 1, n) {
        int a;
        cin >> a;
        update(1, i, i, a);
    }
    while (q--) {
        string s;
        cin >> s;
        if (s[0] == 'T') {
            int l, r;
            cin >> l >> r;
            auto ret = query(1, l, r);
            ll ans = ret._1;
            REP(i, 62) if (ret._2 & (1LL << i)) ans = ans * fac[i] % MOD;
            cout << ans << '\n';
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            update(1, l, r, x);
        }
    }
}