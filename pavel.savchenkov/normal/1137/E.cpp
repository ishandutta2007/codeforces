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
#include <array>


using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ld = long double;
using vi = std::vector<int>;
using pii = std::pair<int, int>;
using vvi = std::vector<vi>;
using vii = std::vector<pii>;
using vll = std::vector<ll>;
using pll = std::pair<ll, ll>;

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
#define left left___
#define right right___
#include <chrono>

template<typename T>
int sign(const T& t) {
    return (t > 0) - (t < 0);
}

template<typename T, typename U>
bool remax(T& a, U b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<typename T, typename U>
bool remin(T& a, U b) {
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

long long current_nanoseconds() {
    return std::chrono::steady_clock::now().time_since_epoch().count();
}

#ifdef LOCAL
long long default_seed = 1;
#else
long long default_seed = current_nanoseconds();
#endif

uint32_t mrand_32t() {
    static std::mt19937 rng(default_seed);
    return rng();
}

uint64_t mrand_64t() {
    static std::mt19937_64 rng(default_seed);
    return rng();
}

template<typename T>
void make_unique(std::vector<T>& v) {
    std::sort(std::begin(v), std::end(v));
    v.erase(std::unique(std::begin(v), std::end(v)), std::end(v));
}

#include <sstream>

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

template<size_t N>
string to_string(const bitset<N>& b) {
    string res(N, '0');
    for (size_t i = 0; i < N; ++i) {
        res[i] = '0' + b[i];
    }
    return res;
}

template <typename T>
string to_string(const T& t) {
    std::stringstream ss;
    ss << t;
    return ss.str();
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

using namespace std;

/* *************************** TEMPLATE CODE ENDS HERE ******************************** */

struct node;
using nodePtr = node*;
struct node {
    nodePtr l, r;
    ll b, s;

    node() {
        l = r = 0;
        b = s = 0;
    }

    nodePtr get_l() {
        if (!l) {
            l = new node();
        }
        return l;
    }

    nodePtr get_r() {
        if (!r) {
            r = new node();
        }
        return r;
    }
};

ll get_val(nodePtr v, int tl, int tr, int pos) {
    assert(v);
    if (tl == tr) {
        return v->b;
    }
    int tm = (tl + tr) >> 1;
    ll ans;
    if (pos <= tm) {
        ans = get_val(v->get_l(), tl, tm, pos);
    } else {
        ans = get_val(v->get_r(), tm + 1, tr, pos);
    }
    ans += v->b + v->s * (pos - tl);
    return ans;
}

void apply(nodePtr v, int tl, int tr, int l, int r, ll b, ll s) {
    assert(v);
    remax(l, tl);
    remin(r, tr);
    if (l > r) {
        return;
    }
    if (l == tl && r == tr) {
        v->b += b;
        v->s += s;
        return;
    }
    int tm = (tl + tr) >> 1;
    apply(v->get_l(), tl, tm, l, r, b, s);
    apply(v->get_r(), tm + 1, tr, l, r, b + (tm - tl + 1) * s, s);
}

int n, m;

bool read() {
    if (!(cin >> n >> m)) {
        return 0;
    }
    return 1;
}

const int MAX = 1e9;

nodePtr root;
set<int> alive;
int len;

void solve() {
    root = new node();
    alive.clear();
    alive.insert(0);
    len = n;
    set<pair<ll, int>> when_del;
    ll sum_s = 0;

    const auto update_when_del = [&](int i, int j) {
        assert(i < j);
        ll iv = get_val(root, 0, MAX, i);
        ll jv = get_val(root, 0, MAX, j);
        // iv <= jv + (j - i) * s
        // iv - jv <= (j - i) * s
        // s >= (iv - jv) / (j - i)
        ll num = iv - jv;
        ll denum = j - i;
        ll s = (num + denum - 1) / denum;
        when_del.insert(mp(sum_s + s, j));
    };

    const auto relax = [&]() {
        while (!when_del.empty() && when_del.begin()->fst <= sum_s) {
            const int i = when_del.begin()->snd;
            when_del.erase(when_del.begin());
            assert(i > 0);
            auto it = alive.find(i);
            if (it == alive.end()) {
                continue;
            }
            auto prev_it = it; --prev_it;
            auto next_it = it; ++next_it;
            if (next_it == alive.end()) {
                alive.erase(it);
                continue;
            }
            int prev = *prev_it;
            int next = *next_it;
            alive.erase(it);
            update_when_del(prev, next);
        }
    };

    forn(i, m) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            cin >> k;
            root = new node();
            alive.clear();
            alive.insert(0);
            len += k;
            sum_s = 0;
            when_del.clear();
        } else if (type == 2) {
            int k;
            cin >> k;
            len += k;
            alive.insert(len - k);
            assert(sz(alive) > 1);
            auto prev = alive.rbegin();
            ++prev;
            update_when_del(*prev, len - k);
            relax();
        } else if (type == 3) {
            int b, s;
            cin >> b >> s;
            apply(root, 0, MAX, 0, len - 1, b, s);
            sum_s += s;
            relax();
        }

        assert(!alive.empty());
        int pos = *alive.rbegin();
        ll val = get_val(root, 0, MAX, pos);
        cout << pos + 1 << " " << val << "\n";
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
    }

    return 0;
}