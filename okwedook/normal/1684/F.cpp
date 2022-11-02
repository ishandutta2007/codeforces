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

struct node {
    vector<int> sr;
    node() {}
    int query(int ql, int qr) {
        // dbg(st, ql, qr);
        // if need speedup, then replace with sr.end()
        return upper_bound(all(sr), qr) - lower_bound(all(sr), ql);
        // return sz(sr) > 0 && sr.back() >= ql;
    }
};

node merge(const node &a, const node &b) {
    node ans;
    ans.sr.resize(sz(a.sr) + sz(b.sr));
    merge(all(a.sr), all(b.sr), ans.sr.begin());
    return ans;
}

template<class node, node (*merge)(const node&, const node&) = merge>
struct Tree {
    int n = 1;
    vector<node> t;
    node& operator[](int ind) { return t[ind + n]; }
    const node& operator[](int ind) const { return t[ind + n]; }
    void submerge(int v) { // merge v's sons to v
        if (v >= n) return;
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    void resize(int sz) { // allocation
        while (n < sz) n <<= 1;
        t.resize(2 * n + 1);
    }
    void blank() { // default values
        for (int i = 0; i < 2 * n; ++i)
            t[i] = node();
    }
    void build() {
        for (int i = n - 1; i > 0; --i)
            submerge(i);
    }
    template<class T>
    void assign(const vector<T> &a) { // copy of a
        resize(sz(a));
        for (int i = 0; i < sz(a); ++i)
            t[i + n] = a[i];
        for (int i = sz(a); i < n; ++i)
            t[i + n] = node();
        build();
    }
    Tree() {} // empty
    Tree(int sz) { resize(sz); blank(); } // size, default values
    template<class T> Tree(const vector<T> &a) { assign(a); } // copy of a
    template<class T>
    void updup(int i, const T &val) { // upd at i with val, doesn't support push
        i += n;
        t[i].upd(val);
        for (i >>= 1; i > 0; i >>= 1)
            submerge(i);
    }
    node getup(int l, int r) { // get at [l, r), doesn't support push
        l += n;
        r += n;
        int cr = r;
        node left, right;
        bool lf = true, rf = true;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left = lf ? lf = false, t[l++] : merge(left, t[l++]);
            if (r & 1) right = rf ? rf = false, t[--r] : merge(t[--r], right);
        }
        if (lf) return right;
        if (rf) return left;
        return merge(left, right);
    }
    void push(int v) {
        if (t[v].updated()) {
            t[v + v].upd(t[v]);
            t[v + v + 1].upd(t[v]);
            t[v].unupdate();
        }
    }
    // update [l, r) with value x, supports push
    template<class T>
    void upd(int l, int r, const T &x, int v, int vl, int vr) { 
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].upd(x);
        push(v);
        int vm = vl + vr >> 1;
        upd(l, r, x, v + v, vl, vm);
        upd(l, r, x, v + v + 1, vm, vr);
        submerge(v);
    }
    template<class T>
    void upd(int l, int r, const T &x) { upd(l, r, x, 1, 0, n); } 
    
    // get at [l, r), supports push
    node get(int l, int r, int v, int vl, int vr) {
        if (vl >= r || vr <= l) return node();
        if (vl >= l && vr <= r) return t[v];
        push(v);
        int vm = vl + vr >> 1;
        if (r <= vm) return get(l, r, v + v, vl, vm);
        if (l >= vm) return get(l, r, v + v + 1, vm, vr);
        return merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
    }
    node get(int l, int r) { return get(l, r, 1, 0, n); }

    int query(int l, int r, int ql, int qr) { // get at [l, r), doesn't support push
        if (l >= r || ql >= qr) return 0;
        l += n;
        r += n;
        int cr = r;
        int left = 0, right = 0;
        bool lf = true, rf = true;
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) left = lf ? lf = false, t[l++].query(ql, qr) : left + t[l++].query(ql, qr);
            if (r & 1) right = rf ? rf = false, t[--r].query(ql, qr) : t[--r].query(ql, qr) + right;
        }
        if (lf) return right;
        if (rf) return left;
        return left + right;
    }
};

vector<pii> at_least_one(int n, const vector<pii> &segm, const vector<pii> &near) {
    vector<int> mx(n, -1);
    for (auto [l, r] : segm) {
        chmax(mx[l], r);
    }
    vector<vector<int>> query(n);
    for (auto [l, r] : near) {
        query[l].pb(r);
    }
    int cmx = -1;
    vector<pii> ans;
    for (int l = 0; l < n; ++l) {
        chmax(cmx, mx[l]);
        for (auto r : query[l]) {
            if (cmx >= r) {
                ans.pb({l, r});
            }
        }
    }
    return ans;
}

void shrink(vector<int> &a) {
    auto c = sorted(a);
    c.resize(unique(all(c)) - c.begin());
    for (auto &i : a) {
        i = lower_bound(all(c), i) - c.begin();
    }
}

void solve() {
    int n, m;
    read(n, m);
    vector<int> a(n);
    read(a);
    shrink(a);
    vector<pii> segm(m);
    read(segm);
    for (auto &[l, r] : segm) {
        --l, --r;
    }
    vector<vector<int>> occ(n);
    for (int i = 0; i < n; ++i) {
        occ[a[i]].pb(i);
    }
    vector<pii> near;
    for (int val = 0; val < n; ++val) {
        const auto &ind = occ[val];
        for (int i = 0; i + 1 < sz(ind); ++i) {
            near.pb({ind[i], ind[i + 1]});
        }
    }
    near = at_least_one(n, segm, near);
    dbg(near);
    if (sz(near) == 0) {
        println(0);
        return;
    }
    for (int val = 0; val < n; ++val) {
        auto &ind = occ[val];
        ind.insert(ind.begin(), -1);
        ind.insert(ind.end(), n);
    }
    int mxl = n;
    int mnr = -1;
    for (auto [l, r] : near) {
        chmin(mxl, r);
        chmax(mnr, l);
    }
    int ansl = max(0, mnr - mxl + 1) - 1;
    int ansr = n;
    Tree<node> tree(n);
    for (auto [l, r] : segm) {
        tree[l].sr.pb(r);
    }
    for (int i = 0; i < n; ++i) {
        sort(tree[i].sr);
    }
    tree.build();
    auto query = [&](int vl, int vr) {
        return tree.query(0, vl + 1, vr, n);
    };
    ll sum = 0;
    vector<int> vl, vr;
    auto upd_vl = [&](int i, int newvl) {
        sum -= query(vl[i], vr[i]);
        vl[i] = newvl;
        sum += query(vl[i], vr[i]);
    };
    auto upd_vr = [&](int i, int newvr) {
        sum -= query(vl[i], vr[i]);
        vr[i] = newvr;
        sum += query(vl[i], vr[i]);
    };
    // dbg(query(1, 1));
    // return;
    auto check = [&](int len) -> bool {
        dbg(len);
        vl = vector<int>(n, -1);
        vr = vector<int>(n, n);
        sum = 0;
        // for (int i = 0; i < n; ++i) {
        //     sum += query(vl[i], vr[i]);   
        // }
        bool flag = false;
        for (int l = 0; l <= mxl; ++l) {
            int r = l + len - 1;
            if (r < mnr) continue;
            if (r >= n) continue;
            if (!flag) {
                flag = true;
                for (int i = 0; i < l; ++i) {
                    upd_vl(a[i], i);
                }
                for (int i = n - 1; i > r; --i) {
                    upd_vr(a[i], i);
                }
            }
            // dbg(l, r, len, sum);
            // dbg(vl);
            // dbg(vr);
            upd_vr(a[r], *upper_bound(all(occ[a[r]]), r));
            dbg(len, l, r, sum);
            dbg(vl, vr);
            // dbg(vl);
            // dbg(vr);
            if (sum == 0) {
                return true;
            }
            upd_vl(a[l], l);
        }
        return false;
    };
    while (ansr - ansl > 1) {
        int mid = ansl + ansr >> 1;
        if (check(mid)) ansr = mid;
        else ansl = mid;
    }
    println(ansr);
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