#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define checkmin(x, y) if (x > y) x = y
#define checkmax(x, y) if (x < y) x = y
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }

struct node {
    int val;
    int change = 2;
    int l = -1, r = -1;
    node() {}
    node(int val) {
        this->val = val;
    } 
    void c(int x, int vl, int vr) {
        change = x;
        val = x * (vr - vl);
    }
    void operator=(node n) {
        val = n.val;
        change = n.change;
    }
};

node merge(node a, node b) {
    return node(a.val + b.val);
}

struct myarray {
    node t[13000000];
    int sz = 1;
    void add(int &ind) {
        if (ind < 0) ind = sz++;
    }
    node& operator[](int ind) {
        return t[ind];
    }
};

struct Tree {
    myarray t;
    static const int n = 1 << 30;
    void push(int v, int vl, int vm, int vr) {
        if (t[v].change != 2) {
            t[t[v].l].c(t[v].change, vl, vm);
            t[t[v].r].c(t[v].change, vm, vr);
            t[v].change = 2;
        }
    }
    void upd(int l, int r, int x, int v = 0, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return;
        if (vl >= l && vr <= r) return t[v].c(x, vl, vr);
        t.add(t[v].l); t.add(t[v].r);
        int vm = vl + vr >> 1;
        push(v, vl, vm, vr);
        upd(l, r, x, t[v].l, vl, vm);
        upd(l, r, x, t[v].r, vm, vr);
        t[v] = merge(t[t[v].l], t[t[v].r]);
    }
    int get() {
        return t[0].val; 
    }
} t;

signed main() {
    FAST; FIXED; RANDOM;
    int n, q;
    cin >> n >> q;
    t.upd(0, n, 1);
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        t.upd(l - 1, r, k - 1);
        cout << t.get() << '\n';
    }
    return 0;
}