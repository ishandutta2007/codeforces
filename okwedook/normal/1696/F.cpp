#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void initIO() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(12);
}

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using graph = vector<vector<int>>;

const ld eps = 1e-9;
const int mod = 1000000007;
const ll inf = 3000000000000000007ll;

#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define sz(a) signed((a).size())
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

void flush() { cout << flush; }
void flushln() { cout << endl; }
void println() { cout << '\n'; }
template<class T> void print(const T &x) { cout << x; }
template<class T> void read(T &x) { cin >> x; }
template<class T, class ...U> void read(T &x, U& ... u) { read(x); read(u...); }
template<class T, class ...U> void print(const T &x, const U& ... u) { print(x); print(u...); }
template<class T, class ...U> void println(const T &x, const U& ... u) { print(x); println(u...); }

#ifdef DEBUG
    namespace TypeTraits {
        template<class T> constexpr bool IsString = false;
        template<> constexpr bool IsString<string> = true;
        template<class T, class = void> struct IsIterableStruct : false_type{};
        template<class T>
        struct IsIterableStruct<
            T,
            void_t<
                decltype(begin(declval<T>())),
                decltype(end(declval<T>()))
            >
        > : true_type{};
        template<class T> constexpr bool IsIterable = IsIterableStruct<T>::value;
        template<class T> constexpr bool NonStringIterable = !IsString<T> && IsIterable<T>;
        template<class T> constexpr bool DoubleIterable = IsIterable<decltype(*begin(declval<T>()))>;
    };
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<!TypeTraits::NonStringIterable<T>, string> {
        stringstream ss;
        ss << x;
        return ss.str();
    }
    template<class T, class U>
    string pdbg(const pair<T, U> &x) {
        return "{" + pdbg(x.f) + "," + pdbg(x.s) + "}";
    }
    string pdbg(const string &x) {
        return "\"" + x + "\"";
    }
    template<class T>
    auto pdbg(const T &x) -> enable_if_t<TypeTraits::NonStringIterable<T>, string> {
        auto begin = x.begin();
        auto end = x.end();
        string del = "";
        if (TypeTraits::DoubleIterable<T>) {
            del = "\n";
        }
        string ans;
        ans += "{" + del;
        if (begin != end) ans += pdbg(*begin++);
        while (begin != end) {
            ans += "," + del + pdbg(*begin++);
        }
        ans += del + "}";
        return ans;
    }
    template<class T> string dbgout(const T &x) { return pdbg(x); }
    template<class T, class... U>
    string dbgout(T const &t, const U &... u) {
        string ans = pdbg(t);
        ans += ", ";
        ans += dbgout(u...);
        return ans;
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = ", dbgout(__VA_ARGS__)), flushln()
    #define msg(...) print("[", __VA_ARGS__, "]"), flushln()
#else
    #define dbg(...) 0
    #define msg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

template<int Dim, class T>
struct MultiVector : public vector<MultiVector<Dim - 1, T>> {
    static_assert(Dim >= 1, "Vector dimension has to be positive");
    template<typename... Args>
    MultiVector(size_t n = 0, Args... args) : vector<MultiVector<Dim - 1, T>>(n, MultiVector<Dim - 1, T>(args...)) {}
};

template<class T>
struct MultiVector<1, T> : public vector<T> {
    MultiVector(size_t n = 0, const T& val = T()) : vector<T>(n, val) {}
};

using bs = bitset<100>;
MultiVector<2, bs> same;
vector<pii> edge;
vector<int> color;
graph Gans;

vector<int> dist(int s) {
    vector<int> ans(sz(Gans), -1);
    ans[s] = 0;
    queue<int> que;
    que.push(s);
    while (sz(que)) {
        auto f = que.front();
        que.pop();
        for (auto i : Gans[f]) {
            if (ans[i] == -1) {
                ans[i] = ans[f] + 1;
                que.push(i);
            }
        }
    }
    return ans;
}

int n;

#define iter_over_bs(i, st) for (int i = st._Find_first(); i < sz(st); i = st._Find_next(i)) 

bool rec(bs vert) {
    map<int, int> cnt;
    map<int, map<int, int>> mid;
    bool flag = true;
    vector<int> ind_vert;
    while (flag) {
        flag = false;
        cnt.clear();
        ind_vert.clear();
        iter_over_bs(i, vert) {
            ind_vert.pb(i);
        }
        for (auto i : ind_vert) {
            for (auto j : ind_vert) {
                if (j > i) {
                    auto inter = same[i][j] & vert;
                    if (inter.count() > 1) {
                        if (!rec(inter)) {
                            return false;
                        }
                        vert ^= inter;
                        int ans_first = -1;
                        iter_over_bs(first, inter) {
                            iter_over_bs(neigh, vert) {
                                bool flag = true;
                                for (auto x : Gans[first]) {
                                    if (!same[neigh][x][first]) {
                                        flag = false;
                                    }
                                }
                                if (flag) {
                                    ans_first = first;
                                }
                            }
                        }
                        if (ans_first == -1) {
                            return false;
                        }
                        vert[ans_first] = true;
                        flag = true;
                        goto go;
                    } else if (inter.count() == 1) {
                        int x = inter._Find_first();
                        ++cnt[x];
                        mid[i][j] = mid[j][i] = x;
                    }
                }
            }
        }
        go:;
    }
    vector<int> vert_order;
    int v = -1;
    for (auto i : ind_vert) {
        if (cnt[i] == 0) {
            v = i;
        }
    }
    set<int> st(all(ind_vert));
    st.erase(v);
    vert_order.pb(v);
    for (auto i : ind_vert) {
        if (i != v && color[i] == color[v]) {
            int x = mid[i][v];
            vert_order.pb(x);
            st.erase(x);
        }
    }
    sort(all(vert_order), [&](int i, int j) {
        return cnt[i] < cnt[j];
    });
    vector<int> other(all(st));
    sort(all(other), [&](int i, int j) {
        return cnt[i] > cnt[j];
    });
    vert_order.insert(vert_order.end(), all(other));
    for (int i = 1; i < sz(vert_order); ++i) {
        int u = vert_order[i - 1];
        int v = vert_order[i];
        if (color[u] == color[v]) {
            return false;
        }
        // msg("ADD TO ANS: ", u, ' ', v);
        Gans[u].pb(v);
        Gans[v].pb(u);
        edge.pb({u, v});
    }
    return true;
}

MultiVector<2, pii> colorG;

bool dfs_color(int v, int c) {
    if (color[v] != -1) {
        return color[v] == c;
    }
    color[v] = c;
    for (auto [u, change] : colorG[v]) {
        if (!dfs_color(u, c ^ change)) {
            return false;
        }
    }
    return true;
}

void solve() {
    read(n);
    same = MultiVector<2, bs>(n, n, bs());
    colorG = MultiVector<2, pii>(n);
    for (int x = 0; x < n; ++x) {
        for (int y = x + 1; y < n; ++y) {
            string s;
            read(s);
            for (int z = 0; z < n; ++z) {
                same[x][y][z] = same[y][x][z] = s[z] - '0';
            }
            bool diff = !same[x][y].any();
            colorG[x].pb({y, diff});
            colorG[y].pb({x, diff});
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = x + 1; y < n; ++y) {
            if (same[x][y][x] || same[x][y][y]) {
                println("No");
                return;
            }
        }
    }
    color = vector<int>(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (!dfs_color(i, 0)) {
                println("No");
                return;
            }
        }
    }
    // dbg(color);
    bs vert;
    for (int i = 0; i < n; ++i) {
        vert[i] = true;
    }
    edge.clear();
    Gans = graph(n);
    if (!rec(vert)) {
        println("No");
        return;
    }
    for (int u = 0; u < n; ++u) {
        for (int v = u + 1; v < n; ++v) {
            auto du = dist(u);
            auto dv = dist(v);
            for (int i = 0; i < n; ++i) {
                if ((du[i] == dv[i]) != same[u][v][i]) {
                    println("No");
                    return;
                }
            }
        }
    }
    println("Yes");
    for (auto [u, v] : edge) {
        println(u + 1, ' ', v + 1);
    }
}

signed main() {
    initIO();
    int t;
    read(t);
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}