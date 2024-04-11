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
#include <complex>
#include <cassert>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
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
#define mod 998244353
#define inf 3000000000000000007ll
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

const int N = 1e6 + 10;
const int LOG = log2(N);

int h[N], in[N], sub[N];
bool used[N];
int currt = 0;
int link[LOG][N];
graph tree;

void dfs(int v, int p, int d = 0) {
    in[v] = currt++;
    sub[v] = 1;
    link[0][v] = p;
    h[v] = d;
    for (auto i : tree[v]) {
        dfs(i, v, d + 1);
        sub[v] += sub[i];
    }
}

struct Tree {
    static const int n = 1 << 20;
    int t[2 * n + 5];
    void upd(int r, int x) {
        for (r += n, t[r] = x, r >>= 1; r > 0; r >>= 1)
            t[r] = max(t[r + r], t[r + r + 1]);
    }
    int get(int l, int r) {
        l += n;
        r += n;
        int ans = 0;
        while (l < r) {
            if (l & 1) checkmax(ans, t[l++]);
            if (r & 1) checkmax(ans, t[--r]);
            l >>= 1;
            r >>= 1; 
        }
        return ans;
    }
} t;

int get(int v) {
    return t.get(in[v], in[v] + sub[v]) - h[v] + 1;
}
 
void upd(int v, int val) {
    t.upd(in[v], val);
}

void read(int &a) {
    a = 0;
    static char c;
    while (c = getchar(), c >= '0')
        a = (a << 3) + (a << 1) + (c - '0');
}

void print(int a) {
    if (a >= 10) print(a / 10);
    putchar(a % 10 + '0');
}
 
signed main() {
    FAST;
    int n, k;
    read(n); read(k);
    vector<int> a(n), st;
    for (auto &i : a) read(i);
    tree = graph(n);
    for (int i = 0; i < n; ++i) {
        while (sz(st) && a[st.back()] < a[i]) {
            if (i - st.back() + 1 <= k) tree[i].pb(st.back());
            st.popb();
        }
        st.pb(i);
    }
    for (int i = n - 1; i >= 0; --i)
        if (link[0][i] == 0) dfs(i, i);
    for (int l = 1; l < LOG; ++l)
        for (int i = 0; i < n; ++i)
            link[l][i] = link[l - 1][link[l - 1][i]];
    for (int i = 0; i < k; ++i) upd(i, h[i]);
    multiset<int> can;
    for (int i = k - 1; i >= 0; --i)
        if (link[0][i] >= k || link[0][i] == i) {
            used[i] = true;
            can.insert(get(i));
        }
    print(*(--can.end()));
    putchar(' ');
    for (int i = k; i < n; ++i) {
        int add = i, del = i - k;
        int head = del;
        for (int l = LOG - 1; l >= 0; --l)
            if (link[l][head] <= add) head = link[l][head];
        if (used[head]) {
            can.erase(can.lower_bound(get(head)));
            upd(del, 0);
            used[del] = false;
            if (used[head]) can.insert(get(head));
        } else upd(del, 0);
        for (auto i : tree[add]) {
            used[i] = false;
            can.erase(can.lower_bound(get(i)));
        }
        upd(add, h[add]);
        can.insert(get(add));
        used[add] = true;
        print(*(--can.end()));
        putchar(' ');
    }
    return 0;
}