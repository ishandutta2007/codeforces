#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
 
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
#include <random>
#include <cassert>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
#define RANDOM srand(94385)
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
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T> inline T sorted(T a) { sort(a); return a; }

struct mex {
    set<int> vert, used, poss;
    int size() const {
        return sz(vert) + sz(used) + sz(poss);
    }
    mex() {}
    void addposs(int x) {
        if (!vert.count(x) && !used.count(x))
            poss.insert(x);
    }
    void addvert(int x) {
        vert.insert(x);
        poss.erase(x);
        addposs(x + 1);
    }
    void addused(int x) {
        used.insert(x);
        poss.erase(x);
        addposs(x + 1);
    }
    void clearused() {
        while (sz(used)) {
            int f = *used.begin();
            used.erase(f);
            addposs(f);
        }
    }
    int get() {
        return *poss.begin();
    }
};

vector<mex> st;
vector<int> p;

int getp(int v) {
    return v == p[v] ? v : p[v] = getp(p[v]);
}

int unite(int a, int b) {
    a = getp(a);
    b = getp(b);
    assert(a != b);
    if (sz(st[a]) > sz(st[b])) swap(a, b);
    p[a] = b;
    for (auto i : st[a].vert) st[b].addvert(i);
    vector<int> v;
    for (auto i : st[a].used)
        if (st[b].used.count(i)) v.pb(i);
    st[b].clearused();
    for (auto i : v) st[b].addused(i);
    return b;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    st = vector<mex>(n);
    for (int i = 0; i < n; ++i)
        st[i].addvert(i);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        if (a > b) swap(a, b);
        st[a].addused(b);
        st[b].addused(a);
    }
    p = vector<int>(n);
    for (int i = 0; i < n; ++i) p[i] = i;
    int ans = 0;
    vector<bool> used(n);
    for (int i = 0; i < n; ++i)
        if (!used[i]) {
            ++ans;
            used[i] = true;
            int head = i;
            while (true) {
                int x = st[head].get();
                if (x == n) break;
                used[x] = true;
                head = unite(x, head);
            } 
        }
    cout << ans - 1;
    return 0;
}