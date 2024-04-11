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
#define ld double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define lowb lower_bound
#define upb upper_bound
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
    int ans = 0;
    int open = 0, close = 0;
    node() {}
    node(char c) {
        if (c == '(') ++open;
        else ++close;
    }
};

node merge(node a, node b) {
    node ans;
    ans.ans = a.ans + b.ans + min(a.open - a.ans / 2, b.close - b.ans / 2) * 2;
    ans.close = a.close + b.close;
    ans.open = b.open + a.open;
    return ans; 
}

struct Tree {
    static const int n = 1 << 20;
    node t[2 * n + 5];
    void upd(int l, char c, int v = 1, int vl = 0, int vr = n) {
        if (vl > l || vr <= l) return;
        if (vl >= l && vr <= l + 1) return void(t[v] = node(c));
        int vm = vl + vr >> 1;
        upd(l, c, v + v, vl, vm);
        upd(l, c, v + v + 1, vm, vr);
        t[v] = merge(t[v + v], t[v + v + 1]);
    }
    node get(int l, int r, int v = 1, int vl = 0, int vr = n) {
        if (vl >= r || vr <= l) return node();
        if (vl >= l && vr <= r) return t[v];
        int vm = vl + vr >> 1;
        return merge(get(l, r, v + v, vl, vm), get(l, r, v + v + 1, vm, vr));
    }
} t;

signed main() {
    FAST; FIXED; RANDOM;
    string s;
    cin >> s;
    for (int i = 0; i < sz(s); ++i) 
        t.upd(i, s[i]);
    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << t.get(l - 1, r).ans << '\n';
    }
    return 0;
}