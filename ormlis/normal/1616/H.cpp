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
const int maxN = 2e5;
const int LG = 30;


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


struct Node {
    int cnt;
    Node *l, *r;

    Node() : l(nullptr), r(nullptr), cnt(0) {}
};

void add_value(Node *&r, int x, int h) {
    if (!r) {
        r = new Node();
    }
    r->cnt++;
    if (h == -1) return;
    if (x & (1 << h)) {
        add_value(r->r, x, h - 1);
    } else {
        add_value(r->l, x, h - 1);
    }
}

int st2[maxN];

int get_sz(Node *a) {
    if (!a) return 0;
    return a->cnt;
}

int calc(Node *a, Node *b, int h, int x) {
    if (!a && !b) return 0;
    if (!a) return st2[b->cnt];
    if (!b) return st2[a->cnt];
    if (h == -1) return st2[a->cnt + b->cnt];
    if ((1 << h) & x) {
        return sub(mul(add(calc(a->l, b->r, h - 1, x ^ (1 << h)), 1),
                       add(calc(a->r, b->l, h - 1, x ^ (1 << h)), 1)), 1);
    } else {
        int res = add(calc(a->l, b->l, h - 1, x), calc(a->r, b->r, h - 1, x));
        res = add(res, st2[get_sz(a->l) + get_sz(a->r)]);
        res = add(res, st2[get_sz(b->l) + get_sz(b->r)]);
        res = sub(res, st2[get_sz(a->l)]);
        res = sub(res, st2[get_sz(a->r)]);
        res = sub(res, st2[get_sz(b->l)]);
        res = sub(res, st2[get_sz(b->r)]);
        return res;
    }
}

int calc(Node *a, int h, int x) {
    if (!a) return 0;
    if (h == -1) return st2[a->cnt];
    if (((1 << h) & x) == 0) {
        return add(calc(a->l, h - 1, x), calc(a->r, h - 1, x));
    }
    return calc(a->l, a->r, h - 1, x ^ (1 << h));
}

void solve() {
    int n, x;
    cin >> n >> x;
    vi a(n);
    rep(i, n) cin >> a[i];
    Node *root = nullptr;
    rep(i, n) {
        add_value(root, a[i], LG - 1);
    }
    for (int i = 1; i <= n; ++i) {
        st2[i] = mul(st2[i - 1], 2);
        st2[i] = add(st2[i], 1);
    }
    cout << calc(root, LG - 1, x) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(20 - 7) << fixed;
    int t = 1;
    range(i, t) {
        solve();
    }
    return 0;
}