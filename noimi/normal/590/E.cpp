#pragma region Macros
#pragma GCC optimize("O3")
#pragma GCC target("avx2,avx")
#pragma GCC optimize("unroll-loops")
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
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
using namespace std;
string YES[2] = {"NO", "YES"};
string Yes[2] = {"No", "Yes"};
string yes[2] = {"no", "yes"};
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define si(c) (int)(c).size()
#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) {
    scan(head);
    IN(tail...);
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
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())
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
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
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
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(15);
    }
} setup_io;
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

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return move(res);
}
template <class T> Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return move(res);
}

#define i128 __int128_t
#define ull unsigned long long int
#define TEST                                                                                                                                                   \
    INT(testcases);                                                                                                                                            \
    while(testcases--)
template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
    for(auto &e : v) cout << e << " ";
    cout << endl;
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    cout << "(" << p.fi << ", " << p.se << ")";
    return os;
}
template <class S, class T> string to_string(pair<S, T> p) { return "(" + to_string(p.first) + "," + to_string(p.second) + ")"; }
template <class A> string to_string(A v) {
    if(v.empty()) return "{}";
    string ret = "{";
    for(auto &x : v) ret += to_string(x) + ",";
    ret.back() = '}';
    return ret;
}

void dump() { cerr << endl; }
template <class Head, class... Tail> void dump(Head head, Tail... tail) {
    cerr << to_string(head) << " ";
    dump(tail...);
}
#define endl '\n'
#ifdef _LOCAL
#undef endl
#define debug(x)                                                                                                                                               \
    cout << #x << ": ";                                                                                                                                        \
    dump(x)
#else
#define debug(x)
#endif
// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int rnd(int n) { return uniform_int_distribution<int>(0, n - 1)(rng); }
// ll rndll(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng); }

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
#pragma endregion

string s;
vector<int> sa;
bool lt_substr(const string &t, int si = 0, int ti = 0) {
    int sn = (int)s.size(), tn = (int)t.size();
    while(si < sn && ti < tn) {
        if(s[si] < t[ti]) return true;
        if(s[si] > t[ti]) return false;
        ++si, ++ti;
    }
    return si >= sn && ti < tn;
}

int _lower_bound(const string &t) {
    int low = -1, high = (int)sa.size();
    while(high - low > 1) {
        int mid = (low + high) / 2;
        if(lt_substr(t, sa[mid]))
            low = mid;
        else
            high = mid;
    }
    return high;
}
pair<int, int> lower_upper_bound(string &t) {
    int idx = _lower_bound(t);
    int low = idx - 1, high = (int)sa.size();
    t.back()++;
    while(high - low > 1) {
        int mid = (low + high) / 2;
        if(lt_substr(t, sa[mid]))
            low = mid;
        else
            high = mid;
    }
    t.back()--;
    return {idx, high};
}

struct HopcroftKarp {
    vector<vector<int>> graph;
    vector<int> dist, match;
    vector<bool> used, vv;

    HopcroftKarp(int n, int m) : graph(n), match(m, -1), used(n) {}

    void add_edge(int u, int v) { graph[u].push_back(v); }

    void bfs() {
        dist.assign(graph.size(), -1);
        queue<int> que;
        for(int i = 0; i < graph.size(); i++) {
            if(!used[i]) {
                que.emplace(i);
                dist[i] = 0;
            }
        }

        while(!que.empty()) {
            int a = que.front();
            que.pop();
            for(auto &b : graph[a]) {
                int c = match[b];
                if(c >= 0 && dist[c] == -1) {
                    dist[c] = dist[a] + 1;
                    que.emplace(c);
                }
            }
        }
    }

    bool dfs(int a) {
        vv[a] = true;
        for(auto &b : graph[a]) {
            int c = match[b];
            if(c < 0 || (!vv[c] && dist[c] == dist[a] + 1 && dfs(c))) {
                match[b] = a;
                used[a] = true;
                return (true);
            }
        }
        return (false);
    }

    int bipartite_matching() {
        int ret = 0;
        while(true) {
            bfs();
            vv.assign(graph.size(), false);
            int flow = 0;
            for(int i = 0; i < graph.size(); i++) {
                if(!used[i] && dfs(i)) ++flow;
            }
            if(flow == 0) return (ret);
            ret += flow;
        }
    }

    void output() {
        for(int i = 0; i < match.size(); i++) {
            if(~match[i]) { cout << match[i] << "-" << i << endl; }
        }
    }
};

#include <algorithm>
#include <cassert>
#include <numeric>
#include <string>
#include <vector>

namespace atcoder {

namespace internal {

std::vector<int> sa_naive(const std::vector<int> &s) {
    int n = int(s.size());
    std::vector<int> sa(n);
    std::iota(sa.begin(), sa.end(), 0);
    std::sort(sa.begin(), sa.end(), [&](int l, int r) {
        if(l == r) return false;
        while(l < n && r < n) {
            if(s[l] != s[r]) return s[l] < s[r];
            l++;
            r++;
        }
        return l == n;
    });
    return sa;
}

std::vector<int> sa_doubling(const std::vector<int> &s) {
    int n = int(s.size());
    std::vector<int> sa(n), rnk = s, tmp(n);
    std::iota(sa.begin(), sa.end(), 0);
    for(int k = 1; k < n; k *= 2) {
        auto cmp = [&](int x, int y) {
            if(rnk[x] != rnk[y]) return rnk[x] < rnk[y];
            int rx = x + k < n ? rnk[x + k] : -1;
            int ry = y + k < n ? rnk[y + k] : -1;
            return rx < ry;
        };
        std::sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for(int i = 1; i < n; i++) { tmp[sa[i]] = tmp[sa[i - 1]] + (cmp(sa[i - 1], sa[i]) ? 1 : 0); }
        std::swap(tmp, rnk);
    }
    return sa;
}

// SA-IS, linear-time suffix array construction
// Reference:
// G. Nong, S. Zhang, and W. H. Chan,
// Two Efficient Algorithms for Linear Time Suffix Array Construction
template <int THRESHOLD_NAIVE = 10, int THRESHOLD_DOUBLING = 40> std::vector<int> sa_is(const std::vector<int> &s, int upper) {
    int n = int(s.size());
    if(n == 0) return {};
    if(n == 1) return {0};
    if(n == 2) {
        if(s[0] < s[1]) {
            return {0, 1};
        } else {
            return {1, 0};
        }
    }
    if(n < THRESHOLD_NAIVE) { return sa_naive(s); }
    if(n < THRESHOLD_DOUBLING) { return sa_doubling(s); }

    std::vector<int> sa(n);
    std::vector<bool> ls(n);
    for(int i = n - 2; i >= 0; i--) { ls[i] = (s[i] == s[i + 1]) ? ls[i + 1] : (s[i] < s[i + 1]); }
    std::vector<int> sum_l(upper + 1), sum_s(upper + 1);
    for(int i = 0; i < n; i++) {
        if(!ls[i]) {
            sum_s[s[i]]++;
        } else {
            sum_l[s[i] + 1]++;
        }
    }
    for(int i = 0; i <= upper; i++) {
        sum_s[i] += sum_l[i];
        if(i < upper) sum_l[i + 1] += sum_s[i];
    }

    auto induce = [&](const std::vector<int> &lms) {
        std::fill(sa.begin(), sa.end(), -1);
        std::vector<int> buf(upper + 1);
        std::copy(sum_s.begin(), sum_s.end(), buf.begin());
        for(auto d : lms) {
            if(d == n) continue;
            sa[buf[s[d]]++] = d;
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        sa[buf[s[n - 1]]++] = n - 1;
        for(int i = 0; i < n; i++) {
            int v = sa[i];
            if(v >= 1 && !ls[v - 1]) { sa[buf[s[v - 1]]++] = v - 1; }
        }
        std::copy(sum_l.begin(), sum_l.end(), buf.begin());
        for(int i = n - 1; i >= 0; i--) {
            int v = sa[i];
            if(v >= 1 && ls[v - 1]) { sa[--buf[s[v - 1] + 1]] = v - 1; }
        }
    };

    std::vector<int> lms_map(n + 1, -1);
    int m = 0;
    for(int i = 1; i < n; i++) {
        if(!ls[i - 1] && ls[i]) { lms_map[i] = m++; }
    }
    std::vector<int> lms;
    lms.reserve(m);
    for(int i = 1; i < n; i++) {
        if(!ls[i - 1] && ls[i]) { lms.push_back(i); }
    }

    induce(lms);

    if(m) {
        std::vector<int> sorted_lms;
        sorted_lms.reserve(m);
        for(int v : sa) {
            if(lms_map[v] != -1) sorted_lms.push_back(v);
        }
        std::vector<int> rec_s(m);
        int rec_upper = 0;
        rec_s[lms_map[sorted_lms[0]]] = 0;
        for(int i = 1; i < m; i++) {
            int l = sorted_lms[i - 1], r = sorted_lms[i];
            int end_l = (lms_map[l] + 1 < m) ? lms[lms_map[l] + 1] : n;
            int end_r = (lms_map[r] + 1 < m) ? lms[lms_map[r] + 1] : n;
            bool same = true;
            if(end_l - l != end_r - r) {
                same = false;
            } else {
                while(l < end_l) {
                    if(s[l] != s[r]) { break; }
                    l++;
                    r++;
                }
                if(l == n || s[l] != s[r]) same = false;
            }
            if(!same) rec_upper++;
            rec_s[lms_map[sorted_lms[i]]] = rec_upper;
        }

        auto rec_sa = sa_is<THRESHOLD_NAIVE, THRESHOLD_DOUBLING>(rec_s, rec_upper);

        for(int i = 0; i < m; i++) { sorted_lms[i] = lms[rec_sa[i]]; }
        induce(sorted_lms);
    }
    return sa;
}

} // namespace internal

std::vector<int> suffix_array(const std::vector<int> &s, int upper) {
    assert(0 <= upper);
    for(int d : s) { assert(0 <= d && d <= upper); }
    auto sa = internal::sa_is(s, upper);
    return sa;
}

template <class T> std::vector<int> suffix_array(const std::vector<T> &s) {
    int n = int(s.size());
    std::vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int l, int r) { return s[l] < s[r]; });
    std::vector<int> s2(n);
    int now = 0;
    for(int i = 0; i < n; i++) {
        if(i && s[idx[i - 1]] != s[idx[i]]) now++;
        s2[idx[i]] = now;
    }
    return internal::sa_is(s2, now);
}

std::vector<int> suffix_array(const std::string &s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for(int i = 0; i < n; i++) { s2[i] = s[i]; }
    return internal::sa_is(s2, 255);
}

// Reference:
// T. Kasai, G. Lee, H. Arimura, S. Arikawa, and K. Park,
// Linear-Time Longest-Common-Prefix Computation in Suffix Arrays and Its
// Applications
template <class T> std::vector<int> lcp_array(const std::vector<T> &s, const std::vector<int> &sa) {
    int n = int(s.size());
    assert(n >= 1);
    std::vector<int> rnk(n);
    for(int i = 0; i < n; i++) { rnk[sa[i]] = i; }
    std::vector<int> lcp(n - 1);
    int h = 0;
    for(int i = 0; i < n; i++) {
        if(h > 0) h--;
        if(rnk[i] == 0) continue;
        int j = sa[rnk[i] - 1];
        for(; j + h < n && i + h < n; h++) {
            if(s[j + h] != s[i + h]) break;
        }
        lcp[rnk[i] - 1] = h;
    }
    return lcp;
}

std::vector<int> lcp_array(const std::string &s, const std::vector<int> &sa) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for(int i = 0; i < n; i++) { s2[i] = s[i]; }
    return lcp_array(s2, sa);
}

// Reference:
// D. Gusfield,
// Algorithms on Strings, Trees, and Sequences: Computer Science and
// Computational Biology
template <class T> std::vector<int> z_algorithm(const std::vector<T> &s) {
    int n = int(s.size());
    if(n == 0) return {};
    std::vector<int> z(n);
    z[0] = 0;
    for(int i = 1, j = 0; i < n; i++) {
        int &k = z[i];
        k = (j + z[j] <= i) ? 0 : std::min(j + z[j] - i, z[i - j]);
        while(i + k < n && s[k] == s[i + k]) k++;
        if(j + z[j] < i + z[i]) j = i;
    }
    z[0] = n;
    return z;
}

std::vector<int> z_algorithm(const std::string &s) {
    int n = int(s.size());
    std::vector<int> s2(n);
    for(int i = 0; i < n; i++) { s2[i] = s[i]; }
    return z_algorithm(s2);
}

} // namespace atcoder

int cnt[1000][1000], tmp[1000];
vi v[10001000];
template <typename T = long long, const int sz = 2 * 10000000> struct IO {
    char reader[sz], writer[sz];
    char *now, *now2 = writer;
    IO() {
        reader[fread(reader, sizeof(char), sizeof(char) * sz, stdin)];
        now = reader;
    }
    inline T read() {
        while(*now && *now <= 32) now++;
        if(*now == '-') {
            now++;
            T res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            return -res;
        } else {
            T res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            return res;
        }
    }
    inline void read(T &res) {
        while(*now && *now <= 32) now++;
        if(*now == '-') {
            now++;
            res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
            res = -res;
        } else {
            res = 0;
            while('0' <= *now and *now <= '9') { res = res * 10 + *now++ - '0'; }
        }
    }
    inline void read_str(string &res) {
        while(!*now or *now == '\n' or *now == ' ') now++;
        while(*now and *now != '\n' and *now != ' ') res += *now++;
        now++;
    }
    inline void write(T x, char margin = ' ') {
        if(x == 0) {
            putchar('0');
            putchar(margin);
            return;
        }
        if(x < 0) {
            putchar('-');
            x = -x;
        }
        while(x) {
            *now2 = '0' + x % 10;
            now2++;
            x /= 10;
        }
        do {
            now2--;
            putchar(*now2);
        } while(now2 != writer);
        putchar(margin);
    }
    inline void write_str(string s, char margin = ' ') {
        for(auto c : s) putchar(c);
        putchar(margin);
    }
};
IO<int> io;
inline ll read() { return io.read(); }
inline void read(int &a) { io.read(a); }
inline void write(ll x) { io.write(x); }
inline void write(ll x, char c) { io.write(x, c); }
string a[800];
main() {
    int n;
    read(n);
    rep(i, n) io.read_str(a[i]);
    rep(i, n) s += a[i], s += "c";
    sa = atcoder::suffix_array(s);
    int now = 0;
    vi inv(si(s));
    rep(i, si(s)) inv[sa[i]] = i;
    vi num(si(s));
    rep(i, n) { rep(j, si(a[i]) + 1) num[now++] = i; }
    now = 0;
    // cout << sa;
    // cout << s << endl;
    rep(i, n) {
        auto [l, r] = lower_upper_bound(a[i]);
        v[l].eb(i), v[r].eb(i);
        // cout << l << " " << r << " " << inv[now] << " " << sa[now] << endl;
        now += si(a[i]) + 1;
    }
    bitset<1000> watch;
    rep(i, si(s)) {
        for(auto e : v[i])
            if(watch[e]) {
                watch[e] = 0;
                rep(i, n) cnt[e][i] += tmp[i];
            } else {
                rep(i, n) cnt[e][i] -= tmp[i];
                watch[e] = 1;
            }
        tmp[num[sa[i]]]++;
    }
    HopcroftKarp match(n, n);
    rep(i, n) {
        rep(j, n) if(i != j and cnt[i][j]) {
            match.add_edge(i, j);
            // cout << i << " " << j << endl;
        }
    }
    int ans = n - match.bipartite_matching();
    vi node;
    vi rev(n);
    rep(i, n) {
        bool flag = true;
        for(auto &e : node) flag &= !cnt[e][i] and !cnt[i][e];
        if(!flag) continue;
        node.eb(i);
        vi w;
        rep(j, n) {
            flag = true;
            for(auto &e : node) flag &= !cnt[e][j] and !cnt[j][e] and j != e;
            if(flag) w.eb(j);
        }
        HopcroftKarp flow(si(w), si(w));
        rep(i, si(w)) rev[w[i]] = i;
        for(auto &j : w)
            for(auto &k : w)
                if(cnt[j][k] and j != k) flow.add_edge(rev[j], rev[k]);
        if(si(w) - flow.bipartite_matching() + node.size() == ans) continue;
        node.pop_back();
    }
    cout << ans << endl;
    for(auto &e : node) cout << ++e << " ";
    cout << endl;
}