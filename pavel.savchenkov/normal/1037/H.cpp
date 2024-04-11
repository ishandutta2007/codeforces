#ifdef LOCAL
    #define _GLIBCXX_DEBUG
#endif



#include <cstdio>
#include <iostream>
#include <cmath>
#include <utility>
#include <memory>
#include <memory.h>
#include <cstdlib>
#include <set>
#include <map>
#include <cassert>
#include <bitset>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <numeric>
#include <algorithm>
#include <complex>
#include <vector>
#include <random>
#include <ctime>
#include <ostream>
#include <queue>


using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using vvi = std::vector<vi>;
using vii = std::vector<pii>;

#define MAKE_FINAL_NAME_HELPER(A, B) A ## B
#define MAKE_FINAL_NAME(NAME, NUM) MAKE_FINAL_NAME_HELPER(NAME ## _, NUM)
#define ARGUMENTS_SIZE_HELPER(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, COUNT, ...) COUNT
#define ARGUMENTS_SIZE(...) ARGUMENTS_SIZE_HELPER(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define SELECT_MACRO(NAME, ...) MAKE_FINAL_NAME(NAME, ARGUMENTS_SIZE(__VA_ARGS__))(__VA_ARGS__)

#define pb push_back
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define mp(x, y) make_pair(x, y)
#define fst first
#define snd second

#define ford(...) SELECT_MACRO(ford, __VA_ARGS__)
#define ford_3(i, s, n) for (int i = int(n) - 1; i >= int(s); --i)
#define ford_2(i, n) ford_3(i, 0, n)

#define forn(...) SELECT_MACRO(forn, __VA_ARGS__)
#define forn_3(i, s, n) for (int i = int(s); i < int(n); ++i)
#define forn_2(i, n) forn_3(i, 0, n)

#define y1 y1___
#define prev prev___
#define next next___
#define hash hash___


template<typename T>
int sign(const T& t) {
    return (t > 0) - (t < 0);
}

template<typename T>
bool remax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool remin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
T gcd(T a, T b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

template<typename T>
T lcm(T a, T b) {
    a = std::abs(a);
    b = std::abs(b);
    return a / gcd(a, b) * b;
}

double get_time() {
    return static_cast<double>(clock()) / CLOCKS_PER_SEC;
}

uint32_t mrand_32t() {
    static std::random_device rd;
    // TODO: seed with 19937 bits, not with 32
    static std::mt19937 rng(rd());
    return rng();
}

uint64_t mrand_64t() {
    static std::random_device rd;
    // TODO: seed with 19937 bits, not with 32
    static std::mt19937_64 rng(rd());
    return rng();
}

template<typename T>
void make_unique(std::vector<T>& v) {
    std::sort(std::begin(v), std::end(v));
    v.erase(std::unique(std::begin(v), std::end(v)), std::end(v));
}


namespace std {

template<typename A, typename B>
string to_string(const pair <A, B>& p) {
    string str;
    str += "(";
    str += to_string(p.first);
    str += ", ";
    str += to_string(p.second);
    str += ")";
    return str;
}

string to_string(bool value) {
    return value ? "true" : "false";
}

template<typename T>
string to_string(const vector <T>& vec) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : vec) {
        if (!first) {
            str += ", ";
        }
        str += to_string(it);
        first = false;
    }
    str += " }";
    return str;
}

template<typename T>
string to_string(const set <T>& s) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : s) {
        if (!first) {
            str += ", ";
        }
        str += to_string(it);
        first = false;
    }
    str += " }";
    return str;
}


template<typename K, typename V>
string to_string(const map <K, V>& m) {
    string str = "{ ";
    bool first = true;
    for (const auto& it : m) {
        if (!first) {
            str += ", ";
        }
        first = false;
        str += to_string(it.first);
        str += " -> ";
        str += to_string(it.second);
    }
    str += " }";
    return str;
}

string to_string(const string& s) {
    return "\"" + s + "\"";
}

string to_string(const char* s) {
    return to_string(string(s));
}

string to_string(char ch) {
    return "\'" + string(1, ch) + "\'";
}

}

void debug_out() {
    std::cerr << std::endl;
}

template<typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    std::cerr << " " << std::to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
    #define debug(...) std::cerr << "[" << #__VA_ARGS__ <<  "]:", debug_out(__VA_ARGS__);
#else
    #define eprintf(...)
    #define cerr if (false) cerr
    #define debug(...)
#endif

#include <array>
#include <string>

template<int MAXLEN, int Lc = 'a', int Rc = 'z'>
class SuffixAutomaton {
public:
    static constexpr int A = Rc - Lc + 1;
    static constexpr int MAXN = MAXLEN * 2;

    struct node;
    using nodePtr = node*;

private:
    std::vector<node> pool{};
    int ptr_pool{};

public:
    struct node {
        std::array<nodePtr, A> to{};
        nodePtr link{};
        int len{};

        node() = default;

        void* operator new(size_t) = delete;
    };

    nodePtr newNode() {
        int pos = ptr_pool++;
        assert(pos < MAXN);
        pool[pos] = node();
        return pool.data() + pos;
    }

    SuffixAutomaton() : pool(MAXN) {
        dropNodesPool();
    }

    void dropNodesPool() {
        ptr_pool = 0;
    }

    nodePtr root;

    void build(const std::string& s) {
        std::vector<int> ss(s.size());
        for (size_t i = 0; i < s.size(); ++i) {
            ss[i] = static_cast<int>(s[i]);
        }
        build(ss);
    }

    void build(const std::vector<int>& s) {
        root = newNode();
        nodePtr last = root;
        for (const auto& c : s) {
            add_c(encode(c), last);
        }
    }

    int id_node(const nodePtr v) const {
        return v ? v - pool.data() : -1;
    }

    nodePtr get_node(const int id) {
        assert(id != -1);
        return pool.data() + id;
    }

    int cnt_alive_nodes() const {
        return ptr_pool;
    }

    static int encode(const int c) {
        return c - Lc;
    }

    static int decode(const int c) {
        return c + Lc;
    }

    void output(std::ostream& os) const {
        assert(root);
        std::map<nodePtr, std::vector<std::string>> S;

        const std::function<void(nodePtr, std::string)> dfs = [&](nodePtr v, std::string cur = "") {
            if (!v) {
                return;
            }
            S[v].push_back(cur);
            for (int c = Lc; c <= Rc; ++c) {
                nodePtr to = v->to[encode(c)];
                if (!to) {
                    continue;
                }
                cur.push_back(c);
                dfs(to, cur);
                cur.pop_back();
            }
        };

        dfs(root, "");

        for (const auto& it : S) {
            const nodePtr v = it.first;
            const int id = id_node(v);
            os << id << ": ";

            auto ss = S[v];
            std::sort(ss.begin(), ss.end(), [](const std::string& a, const std::string& b) { return a.size() < b.size(); });
            std::string prev;
            for (const auto& s : ss) {
                if (!prev.empty()) {
                    assert(s.size() == prev.size() + 1);
                    assert(prev == s.substr(1));
                }
                prev = s;
            }

            if (!ss.empty()) {
                const auto a = ss.front();
                const auto b = ss.back();
                os << "[" << b.substr(0, b.size() - a.size()) << "[" << a << "]";
            }
            os << ", ";
            os << "link = " << id_node(v->link) << ", len = " << v->len << std::endl;
        }
    }

private:
    void add_c(const int c, nodePtr& last) {
        nodePtr p = last;
        nodePtr nw = newNode();
        nw->len = last->len + 1;
        last = nw;

        for (; p && !p->to[c]; p = p->link) {
            p->to[c] = nw;
        }

        if (!p) {
            nw->link = root;
            return;
        }

        const nodePtr q = p->to[c];
        if (q->len == p->len + 1) {
            nw->link = q;
            return;
        }

        nodePtr clone = newNode();
        clone->to = q->to;
        clone->len = p->len + 1;
        clone->link = q->link;
        nw->link = q->link = clone;
        for (; p && p->to[c] == q; p = p->link) {
            p->to[c] = clone;
        }
    }
};
using namespace std;

/* *************************** TEMPLATE CODE ENDS HERE ******************************** */

const int MAXLEN = int(1e5) + 10;

using SuffAut = SuffixAutomaton<MAXLEN, 'a', 'z'>;
SuffAut aut;

using nodePtr = SuffAut::nodePtr;

struct SegmTree {
    vi t;
    int sz;

    SegmTree(int n = 0) {
        sz = 1;
        while (sz < n) sz *= 2;
        t.assign(sz * 2, -1);
    }

    int get_max(int l, int r) {
        l += sz;
        r += sz;
        int res = -1;
        while (l <= r) {
            remax(res, t[l]);
            remax(res, t[r]);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
        return res;
    }

    void upd(int pos, int val) {
        int v = sz + pos;
        remax(t[v], val);
        v >>= 1;
        while (v) {
            t[v] = -1;
            remax(t[v], t[v * 2]);
            remax(t[v], t[v * 2 + 1]);
            v >>= 1;
        }
    }
};

struct Query {
    int l, r;
    string x;
    int id;

    bool read(int i) {
        if (!(cin >> l >> r >> x)) {
            return 0;
        }
        --l;
        --r;
        id = i;
        return 1;
    }
};

string s;
vector<Query> qs;

bool read() {
    if (!(cin >> s)) {
        return 0;
    }
    int q;
    cin >> q;
    qs.resize(q);
    forn(i, q) {
        assert(qs[i].read(i));
    }
    return 1;
}

int N;
vi tin;
vi tout;
int timer;
vvi g;

void dfs(int v) {
    tin[v] = timer++;
    for (int to : g[v]) {
        dfs(to);
    }
    tout[v] = timer;
}

void solve() {
    aut.build(s);
    N = aut.cnt_alive_nodes();
    tin.resize(N);
    tout.resize(N);

    g.clear();
    g.resize(N);
    forn(i, N) {
        auto v = aut.get_node(i);
        if (v->link) {
            g[aut.id_node(v->link)].pb(aut.id_node(v));
        }
    }

    timer = 0;
    dfs(0);
    assert(timer == N);

    vvi who(sz(s));
    for (const auto& q : qs) {
        who[q.r].pb(q.id);
    }

    SegmTree T(N);
    forn(i, N) {
        T.upd(i, -1);
    }

    const auto get_last = [&](nodePtr v) -> int {
        int id = aut.id_node(v);
        int l = tin[id];
        int r = tout[id] - 1;
        int ans = T.get_max(l, r);
        return ans;
    };

    vector<string> ans(sz(qs));
    nodePtr ptr = aut.get_node(0);
    forn(i, sz(s)) {
        ptr = ptr->to[s[i] - 'a'];
        assert(ptr);
        {
            int pos = tin[aut.id_node(ptr)];
            T.upd(pos, i);
        }

        for (int id : who[i]) {
            nodePtr v = aut.get_node(0);
            const int l = qs[id].l;
            const auto& x = qs[id].x;

            int pref = 0;
            int pref_nxt = -1;
            forn(j, sz(x) + 1) {
                const char ch = (j == sz(x)) ? 0 : x[j];
                for (char nxt = max('a', char(ch + 1)); nxt <= 'z'; ++nxt) {
                    nodePtr u = v->to[nxt - 'a'];
                    if (!u) {
                        continue;
                    }
                    int R = get_last(u);
                    if (R == -1) {
                        continue;
                    }
                    assert(R <= i);
                    int L = R - j;
                    if (L < l) {
                        continue;
                    }
                    pref = j;
                    pref_nxt = nxt - 'a';
                    break;
                }
                if (!ch) {
                    break;
                }
                v = v->to[ch - 'a'];
                if (!v) {
                    break;
                }
            }

            if (pref == 0 && pref_nxt == -1) {
                ans[id].clear();
            } else {
                ans[id] = x.substr(0, pref);
                ans[id] += 'a' + pref_nxt;
            }
        }
    }

    forn(i, sz(qs)) {
        if (ans[i].empty()) {
            cout << "-1" << "\n";
        } else {
            cout << ans[i] << "\n";
        }
    }
    cout << endl;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cout.precision(12);
    cout << fixed;

#ifdef LOCAL
    #define FILE_NAME "a"
    assert(freopen(FILE_NAME ".in", "r", stdin));
//    freopen(FILE_NAME ".out", "w", stdout);
#endif

    while (read()) {
        solve();

        break;
    }

    return 0;
}