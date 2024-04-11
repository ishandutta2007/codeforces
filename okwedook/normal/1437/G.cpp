#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <complex>
#include <random>
#include <cassert>
#include <chrono>
#include <functional>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
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
    template<class T> void pdbg(const T &x) { print(x); }
    template<class T, class U> void pdbg(const pair<T, U> &p) {
        print('{');
        pdbg(p.f);
        print(',');
        pdbg(p.s); 
        print('}');
    }
    void pdbg(const string &s) { print("\"" + s + "\""); }
    template<class It> void pdbg(It begin, It end, string d);
    template<class T> void pdbg(const vector<T> &a) { pdbg(all(a), ""); }
    template<class T> void pdbg(const vector<vector<T>> &a) { pdbg(all(a), "\n"); }
    template<class T> void pdbg(const vector<vector<vector<T>>> &a) { pdbg(all(a), "\n\n"); }
    template<class T> void pdbg(const set<T> &a) { pdbg(all(a), ""); }
    template<class T> void pdbg(const hashset<T> &a) { pdbg(all(a), ""); }
    template<class T, class U> void pdbg(const map<T, U> &a) { pdbg(all(a), ""); }
    template<class T, class U> void pdbg(const hashmap<T, U> &a) { pdbg(all(a), ""); }
    template<class It> void pdbg(It begin, It end, string d) {
        print('{');
        if (begin != end) pdbg(*begin++);
        while (begin != end)
            print(",", d), pdbg(*begin++);
        print('}');
    }
    template<class T> void dbgout(const T &x) { pdbg(x); }
    template<class T, class... U>
    void dbgout(T const &t, const U &... u) {
        pdbg(t);
        print(", ");
        dbgout(u...);
    }
    #define dbg(...) print("[", #__VA_ARGS__, "] = "), dbgout(__VA_ARGS__), flushln()
#else
    #define dbg(...) 0
#endif

template<class T, class U> inline bool chmin(T &x, const U& y) { return y < x ? x = y, 1 : 0; }
template<class T, class U> inline bool chmax(T &x, const U& y) { return y > x ? x = y, 1 : 0; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

#include <cstring>

namespace Aho {

    const int N = 3e5 + 100;
    int ptr = 1;

    struct node {
        vector<int> go;
        int suf = 0, par = 0, sup = 0;
        char last;
        multiset<int> st;
        vector<int> term;
        node() { go.resize(26); }
        int getmx() const {
            return sz(st) == 0 ? -1 : *st.rbegin();
        }
    };


    node t[N];

    int addlink(int v, char c) {
        if (t[v].go[c]) return t[v].go[c];
        int u = ptr++;
        t[u].par = v;  
        t[u].last = c;
        return t[v].go[c] = u;
    }

    int getlink(int v, int c) {
        if (t[v].go[c]) return t[v].go[c];
        if (v == 0) return v;
        return getlink(t[v].suf, c);
    }

    vector<int> pos;

    void addstring(const string &s, int ind) {
        int v = 0;
        for (auto i : s)
            v = addlink(v, i - 'a');
        t[v].term.pb(ind);
        pos[ind] = v;
    }

    void countsuf(int v) {
        queue<int> que({v});
        while (sz(que)) {
            auto f = que.front();
            que.pop();
            if (t[f].par != 0) {
                t[f].suf = getlink(t[t[f].par].suf, t[f].last);
                if (sz(t[t[f].suf].term)) t[f].sup = t[f].suf;
                else t[f].sup = t[t[f].suf].sup;
            }
            for (int i = 0; i < 26; ++i)
                if (t[f].go[i]) que.push(t[f].go[i]);
        }
    }
};

namespace HLD {
    struct node {
        int mx = -1;
        node() {}
        void a(int k) { mx = k; }
    };

    node merge(node a, node b) {
        node ans;
        ans.mx = max(a.mx, b.mx);
        return ans;
    }

    struct Tree {
        static const int n = 1 << 19;
        node t[2 * n + 5];
        void add(int r, int x) {
            r += n;
            t[r].a(x);
            r >>= 1;
            while (r > 0) {
                t[r] = merge(t[r + r], t[r + r + 1]);
                r >>= 1;
            }
        }
        node get(int l, int r) {
            l += n;
            r += n + 1;
            node left, right;
            while (l < r) {
                if (l & 1) left = merge(left, t[l++]);
                if (r & 1) right = merge(t[--r], right);
                l >>= 1;
                r >>= 1;
            }
            return merge(left, right);
        }
    } t;

    vector<int> h, sub, ind, head, par;
    int curr = 0;
    graph G;

    void orient(int v = 0, int p = -1, int d = 0) {
        h[v] = d;
        par[v] = p;
        sub[v] = 1;
        for (auto i : G[v])
            if (i != p) {
                orient(i, v, d + 1);
                sub[v] += sub[i];
            }
        for (int i = 0; i < sz(G[v]); ++i)
            if (G[v][i] != p && sub[G[v][i]] * 2 >= sub[v])
                swap(G[v][0], G[v][i]);
    }

    void buildhld(int v = 0, int path = 0) {
        head[v] = path;
        ind[v] = curr++;
        for (auto i : G[v])
            if (i != par[v]) {
                if (sub[i] * 2 >= sub[v]) buildhld(i, path);
                else buildhld(i, i);
            }
    }

    int lca(int u, int v) {
        while (head[u] != head[v])
            if (h[head[u]] > h[head[v]]) u = par[head[u]];
            else v = par[head[v]];
        return h[u] < h[v] ? u : v;
    }

    node getw(int u, int v) {
        node ans;
        while (head[u] != head[v]) ans = merge(ans, t.get(ind[head[u]], ind[u])), u = par[head[u]];
        return merge(ans, t.get(ind[v], ind[u]));
    }

    node getwo(int u, int v) {
        node ans;
        while (head[u] != head[v]) ans = merge(ans, t.get(ind[head[u]], ind[u])), u = par[head[u]];
        if (ind[v] + 1 > ind[u]) return ans;
        return merge(ans, t.get(ind[v] + 1, ind[u]));
    }

    void resize(int n) {
        G = graph(n);
        h = sub = ind = head = par = vector<int>(n);
    }
};

signed main() {
    FAST; FIXED;
    int n, m;
    read(n, m);
    Aho::pos.resize(n);
    for (int i = 0; i < n; ++i) {
        string s;
        read(s);
        Aho::addstring(s, i);
    }
    Aho::countsuf(0);
    vector<int> val(n);
    for (int i = 0; i < n; ++i)
        Aho::t[Aho::pos[i]].st.insert(0);
    HLD::resize(Aho::ptr);
    for (int i = 1; i < Aho::ptr; ++i) {
        int u = Aho::t[i].suf, v = i;
        dbg(u, v);
        HLD::G[u].pb(v);
    }
    HLD::orient(0);
    HLD::buildhld(0);
    for (int i = 0; i < Aho::ptr; ++i) {
        dbg(i, Aho::t[i].getmx());
        HLD::t.add(HLD::ind[i], Aho::t[i].getmx());
    }
    while (m--) {
        int mode;
        read(mode);
        if (mode == 1) {
            int i, v;
            read(i, v);
            --i;
            int p = Aho::pos[i];
            Aho::t[p].st.erase(Aho::t[p].st.find(val[i]));
            val[i] = v;
            Aho::t[p].st.insert(val[i]);
            HLD::t.add(HLD::ind[p], Aho::t[p].getmx());
        }
        if (mode == 2) {
            string q;
            read(q);
            int ans = -1;
            int v = 0;
            for (auto i : q) {
                v = Aho::getlink(v, i - 'a');
                chmax(ans, HLD::getw(v, 0).mx);
            }
            println(ans);
        }
    }
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}