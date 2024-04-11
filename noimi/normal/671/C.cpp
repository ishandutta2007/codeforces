#pragma region Macros
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define ios ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define Size(c) (int)(c).size()
#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define ULL(...)                                                                                                                                               \
    ull __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define LD(...)                                                                                                                                                \
    ld __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
int scan() { return getchar(); }
template <class T> void scan(T a) { cin >> a; }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(vector<T> &);
template <class T, size_t size> void scan(array<T, size> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T, size_t size> void scan(T (&)[size]);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(deque<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T, size_t size> void scan(array<T, size> &a) {
    for(auto &i : a) scan(i);
}
template <class T, class L> void scan(pair<T, L> &p) {
    scan(p.first);
    scan(p.second);
}
template <class T, size_t size> void scan(T (&a)[size]) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
}
string stin() {
    string s;
    cin >> s;
    return s;
}
template <class T, class S> inline bool chmax(T &a, S b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T, class S> inline bool chmin(T &a, S b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
vi iota(int n) {
    vi a(n);
    iota(all(a), 0);
    return a;
}
template <class T> void UNIQUE(vector<T> &x) {
    sort(all(x));
    x.erase(unique(all(x)), x.end());
}
int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}
void print() { putchar(' '); }
void print(bool a) { cout << a; }
void print(int a) { cout << a; }
void print(long long a) { cout << a; }
void print(char a) { cout << a; }
void print(string &a) { cout << a; }
void print(double a) { cout << a; }
template <class T> void print(const vector<T> &);
template <class T, size_t size> void print(const array<T, size> &);
template <class T, class L> void print(const pair<T, L> &p);
template <class T, size_t size> void print(const T (&)[size]);
template <class T> void print(const vector<T> &a) {
    if(a.empty()) return;
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
    cout << endl;
}
template <class T> void print(const deque<T> &a) {
    if(a.empty()) return;
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
}
template <class T, size_t size> void print(const array<T, size> &a) {
    print(a[0]);
    for(auto i = a.begin(); ++i != a.end();) {
        cout << " ";
        print(*i);
    }
}
template <class T, class L> void print(const pair<T, L> &p) {
    cout << '(';
    print(p.first);
    cout << ",";
    print(p.second);
    cout << ')';
}
template <class T> void print(set<T> &x) {
    for(auto e : x) print(e), cout << " ";
    cout << endl;
}
template <class T> void print(multiset<T> &x) {
    for(auto e : x) print(e), cout << " ";
    cout << endl;
}
template <class T, size_t size> void print(const T (&a)[size]) {
    print(a[0]);
    for(auto i = a; ++i != end(a);) {
        cout << " ";
        print(*i);
    }
}
template <class T> void print(const T &a) { cout << a; }
int out() {
    putchar('\n');
    return 0;
}
template <class T> int out(const T &t) {
    print(t);
    putchar('\n');
    return 0;
}
template <class Head, class... Tail> int out(const Head &head, const Tail &... tail) {
    print(head);
    putchar(' ');
    out(tail...);
    return 0;
}
ll gcd(ll a, ll b) {
    while(b) {
        ll c = b;
        b = a % b;
        a = c;
    }
    return a;
}
ll lcm(ll a, ll b) {
    if(!a || !b) return 0;
    return a * b / gcd(a, b);
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
vector<int> divisor(int x) {
    vector<int> ans;
    for(int i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    sort(all(y));
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
int popcount(ll x) { return __builtin_popcountll(x); }
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n) { return uniform_int_distribution<int>(0, n - 1)(rng); }
template <typename T> void shuffle(vector<T> &v) {
    rep3(i, v.size() - 1, 1) { swap(v[i], v[rnd(i)]); }
}
#define endl '\n'
vector<string> YES{"NO", "YES"};
vector<string> Yes{"No", "Yes"};
vector<string> yes{"no", "yes"};

#ifdef _LOCAL
#undef endl
#define debug(x)                                                                                                                                               \
    cout << #x << ": ";                                                                                                                                        \
    print(x);                                                                                                                                                  \
    cout << endl;
void err() {}
template <class T> void err(const T &t) {
    print(t);
    cout << " ";
}
template <class Head, class... Tail> void err(const Head &head, const Tail &... tail) {
    print(head);
    putchar(' ');
    out(tail...);
}
#else
#define debug(x)
template <class... T> void err(const T &...) {}
#endif

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
};
template <typename T> using Edges = vector<edge<T>>;

struct Graph : vector<vector<int>> {
    using vector<vector<int>>::vector;
    inline void add(int a, int b, bool directed = false) {
        (*this)[a].emplace_back(b);
        if(!directed) (*this)[b].emplace_back(a);
    }
    void read(int n = -1, int offset = 1) {
        if(n == -1) n = this->size() - 1;
        int a, b;
        while(n--) {
            cin >> a >> b;
            Graph::add(a - offset, b - offset);
        }
    }
};
template <typename T> struct WeightedGraph : vector<Edges<T>> {
    using vector<Edges<T>>::vector;
    inline void add(int a, int b, T c, bool directed = false) {
        (*this)[a].emplace_back(b, c);
        if(!directed) (*this)[b].emplace_back(a, c);
    }
    inline void add(int a, int b, T c, int id, bool directed = false) {
        (*this)[a].emplace_back(a, b, c, id);
        if(!directed) (*this)[b].emplace_back(b, a, c, id);
    }
    void read(int n = -1, int offset = 1) {
        if(n == -1) n = this->size() - 1;
        int a, b;
        while(n--) {
            cin >> a >> b;
            Graph::add(a - offset, b - offset);
        }
    }
};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
#pragma endregion

// ____________________

const int N = 200001;
class SegmentTree {
    const ll inf = 1e18;
    int n, n0;
    ll max_v[4 * N], smax_v[4 * N], max_c[4 * N];
    ll min_v[4 * N], smin_v[4 * N], min_c[4 * N];
    ll sum[4 * N];
    ll len[4 * N], ladd[4 * N], lval[4 * N];

    void update_node_max(int k, ll x) {
        sum[k] += (x - max_v[k]) * max_c[k];

        if(max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if(max_v[k] == smin_v[k]) {
            max_v[k] = smin_v[k] = x;
        } else {
            max_v[k] = x;
        }

        if(lval[k] != inf && x < lval[k]) { lval[k] = x; }
    }
    void update_node_min(int k, ll x) {
        sum[k] += (x - min_v[k]) * min_c[k];

        if(max_v[k] == min_v[k]) {
            max_v[k] = min_v[k] = x;
        } else if(smax_v[k] == min_v[k]) {
            min_v[k] = smax_v[k] = x;
        } else {
            min_v[k] = x;
        }

        if(lval[k] != inf && lval[k] < x) { lval[k] = x; }
    }

    void push(int k) {

        if(n0 - 1 <= k) return;

        if(lval[k] != inf) {
            updateall(2 * k + 1, lval[k]);
            updateall(2 * k + 2, lval[k]);
            lval[k] = inf;
            return;
        }

        if(ladd[k] != 0) {
            addall(2 * k + 1, ladd[k]);
            addall(2 * k + 2, ladd[k]);
            ladd[k] = 0;
        }

        if(max_v[k] < max_v[2 * k + 1]) { update_node_max(2 * k + 1, max_v[k]); }
        if(min_v[2 * k + 1] < min_v[k]) { update_node_min(2 * k + 1, min_v[k]); }

        if(max_v[k] < max_v[2 * k + 2]) { update_node_max(2 * k + 2, max_v[k]); }
        if(min_v[2 * k + 2] < min_v[k]) { update_node_min(2 * k + 2, min_v[k]); }
    }

    void update(int k) {
        sum[k] = sum[2 * k + 1] + sum[2 * k + 2];

        if(max_v[2 * k + 1] < max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 2];
            max_c[k] = max_c[2 * k + 2];
            smax_v[k] = max(max_v[2 * k + 1], smax_v[2 * k + 2]);
        } else if(max_v[2 * k + 1] > max_v[2 * k + 2]) {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1];
            smax_v[k] = max(smax_v[2 * k + 1], max_v[2 * k + 2]);
        } else {
            max_v[k] = max_v[2 * k + 1];
            max_c[k] = max_c[2 * k + 1] + max_c[2 * k + 2];
            smax_v[k] = max(smax_v[2 * k + 1], smax_v[2 * k + 2]);
        }

        if(min_v[2 * k + 1] < min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1];
            smin_v[k] = min(smin_v[2 * k + 1], min_v[2 * k + 2]);
        } else if(min_v[2 * k + 1] > min_v[2 * k + 2]) {
            min_v[k] = min_v[2 * k + 2];
            min_c[k] = min_c[2 * k + 2];
            smin_v[k] = min(min_v[2 * k + 1], smin_v[2 * k + 2]);
        } else {
            min_v[k] = min_v[2 * k + 1];
            min_c[k] = min_c[2 * k + 1] + min_c[2 * k + 2];
            smin_v[k] = min(smin_v[2 * k + 1], smin_v[2 * k + 2]);
        }
    }

    void _update_min(ll x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a || max_v[k] <= x) { return; }
        if(a <= l && r <= b && smax_v[k] < x) {
            update_node_max(k, x);
            return;
        }

        push(k);
        _update_min(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_min(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_max(ll x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a || x <= min_v[k]) { return; }
        if(a <= l && r <= b && x < smin_v[k]) {
            update_node_min(k, x);
            return;
        }

        push(k);
        _update_max(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_max(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void addall(int k, ll x) {
        max_v[k] += x;
        if(smax_v[k] != -inf) smax_v[k] += x;
        min_v[k] += x;
        if(smin_v[k] != inf) smin_v[k] += x;

        sum[k] += len[k] * x;
        if(lval[k] != inf) {
            lval[k] += x;
        } else {
            ladd[k] += x;
        }
    }

    void updateall(int k, ll x) {
        max_v[k] = x;
        smax_v[k] = -inf;
        min_v[k] = x;
        smin_v[k] = inf;
        max_c[k] = min_c[k] = len[k];

        sum[k] = x * len[k];
        lval[k] = x;
        ladd[k] = 0;
    }

    void _add_val(ll x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a) { return; }
        if(a <= l && r <= b) {
            addall(k, x);
            return;
        }

        push(k);
        _add_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _add_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    void _update_val(ll x, int a, int b, int k, int l, int r) {
        if(b <= l || r <= a) { return; }
        if(a <= l && r <= b) {
            updateall(k, x);
            return;
        }

        push(k);
        _update_val(x, a, b, 2 * k + 1, l, (l + r) / 2);
        _update_val(x, a, b, 2 * k + 2, (l + r) / 2, r);
        update(k);
    }

    ll _query_max(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a) { return -inf; }
        if(a <= l && r <= b) { return max_v[k]; }
        push(k);
        ll lv = _query_max(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_max(a, b, 2 * k + 2, (l + r) / 2, r);
        return max(lv, rv);
    }

    ll _query_min(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a) { return inf; }
        if(a <= l && r <= b) { return min_v[k]; }
        push(k);
        ll lv = _query_min(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_min(a, b, 2 * k + 2, (l + r) / 2, r);
        return min(lv, rv);
    }

    ll _query_sum(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a) { return 0; }
        if(a <= l && r <= b) { return sum[k]; }
        push(k);
        ll lv = _query_sum(a, b, 2 * k + 1, l, (l + r) / 2);
        ll rv = _query_sum(a, b, 2 * k + 2, (l + r) / 2, r);
        return lv + rv;
    }

  public:
    SegmentTree(int n) { SegmentTree(n, nullptr); }

    SegmentTree(int n, ll *a) : n(n) {
        n0 = 1;
        while(n0 < n) n0 <<= 1;

        for(int i = 0; i < 2 * n0; ++i) ladd[i] = 0, lval[i] = inf;
        len[0] = n0;
        for(int i = 0; i < n0 - 1; ++i) len[2 * i + 1] = len[2 * i + 2] = (len[i] >> 1);

        for(int i = 0; i < n; ++i) {
            max_v[n0 - 1 + i] = min_v[n0 - 1 + i] = sum[n0 - 1 + i] = (a != nullptr ? a[i] : 0);
            smax_v[n0 - 1 + i] = -inf;
            smin_v[n0 - 1 + i] = inf;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 1;
        }

        for(int i = n; i < n0; ++i) {
            max_v[n0 - 1 + i] = smax_v[n0 - 1 + i] = -inf;
            min_v[n0 - 1 + i] = smin_v[n0 - 1 + i] = inf;
            max_c[n0 - 1 + i] = min_c[n0 - 1 + i] = 0;
        }
        for(int i = n0 - 2; i >= 0; i--) { update(i); }
    }

    // range minimize query
    void update_min(int a, int b, ll x) { _update_min(x, a, b, 0, 0, n0); }

    // range maximize query
    void update_max(int a, int b, ll x) { _update_max(x, a, b, 0, 0, n0); }

    // range add query
    void add_val(int a, int b, ll x) { _add_val(x, a, b, 0, 0, n0); }

    // range update query
    void update_val(int a, int b, ll x) { _update_val(x, a, b, 0, 0, n0); }

    // range minimum query
    ll query_max(int a, int b) { return _query_max(a, b, 0, 0, n0); }

    // range maximum query
    ll query_min(int a, int b) { return _query_min(a, b, 0, 0, n0); }

    // range sum query
    ll query_sum(int a, int b) { return _query_sum(a, b, 0, 0, n0); }
};

main() {
    INT(n);
    VEC(int, a, n);
    auto f = [](ll x, ll y) { return max(x, y); };
    ll v[n];
    rep(i, n) v[i] = i - 1;
    SegmentTree seg(n, v);
    // LazySegmentTree<ll, ll> seg(n, plus<ll>(), f, f, 0LL, -1, v, multiplies<ll>());
    vector<vll> d(200001);
    rep(i, n) {
        for(int j = 1; j * j <= a[i]; j++) {
            if(a[i] % j == 0) {
                d[j].eb(i);
                if(a[i] != j * j) d[a[i] / j].eb(i);
            }
        }
    }
    ll ans = 0;
    rep3(i, 200000, 1) {
        auto &w = d[i];
        if(w.size() <= 1) continue;
        // print(w);
        vi s;
        s.eb(w.front()), s.eb(w[1]), s.eb(w[w.size() - 2]), s.eb(w.back());
        auto F = [&](int l, int r) { seg.update_max(l, r, r - 1); };
        ll pre = seg.query_sum(0, n);
        F(w.front() + 1, w.back());
        F(0, w[w.size() - 2]);
        F(w[1] + 1, n);
        ans += (seg.query_sum(0, n) - pre) * i;
    }
    cout << ans << endl;
}