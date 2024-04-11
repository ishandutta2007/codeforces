#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

struct node {
    ll mn, add;
    node() {}
    node(ll k) { mn = k; add = 0; }
    void a(int x) { add += x; }
    ll get() { return mn + add; }
};

node merge(node a, node b) {
    return node(min(a.get(), b.get()));
}

struct Tree {
    static const int n = 1 << 18;
    node t[2 * n + 5];
    void push(int v) {
        if (t[v].add != 0) {
            t[v + v].a(t[v].add);
            t[v + v + 1].a(t[v].add);
            t[v].add = 0;
        }
    }
    void add(int l, int r, int x, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].a(x);
        int vm = vl + vr >> 1;
        push(v);
        add(l, r, x, v + v, vl, vm);
        add(l, r, x, v + v + 1, vm, vr);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    node get(int l, int r, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return node(inf);
        if (vl >= l && vr <= r) return t[v];
        int vm = vl + vr >> 1;
        push(v);
        node ans = merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
        t[v] = merge(t[v + v], t[v + v + 1]);
        return ans;
    } 
} t;

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        t.add(i, i + 1, a);
    }
    int m;
    cin >> m;
    string s;
    getline(cin, s);
    while (m--) {
        getline(cin, s);
        int cnt = 0;
        for (auto i : s)
            if (i == ' ') ++cnt;
        stringstream ss;
        ss << s;
        if (cnt == 2) {
            int l, r, v;
            ss >> l >> r >> v;
            if (l <= r) {
                t.add(l, r + 1, v);
            } else {
                t.add(0, r + 1, v);
                t.add(l, n, v);
                //cout << 0 << ' ' << r + 1 << '\n';
                //cout << l << ' ' << n << '\n';
            }
        } else {
            int l, r;
            ss >> l >> r;
            if (l <= r) {
                cout << t.get(l, r + 1).mn << '\n';
            } else {
                cout << merge(t.get(0, r + 1), t.get(l, n)).get() << '\n';
            }
        }
    }
    return 0;
}