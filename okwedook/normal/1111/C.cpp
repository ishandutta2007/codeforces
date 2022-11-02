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

const int N = 7e6;

struct node {
    ll ans = 0;
    int cnt = 0;
    int l = 0, r = 0;
    void operator=(node a) { this->ans = a.ans; this->cnt = cnt; }
    node(int a = 0) { ans = a; }
};

ll A, B;

node merge(node a, node b, int vl, int vr) {
    node ans;
    ans.ans = a.ans + b.ans;
    ans.cnt = a.cnt + b.cnt;
    if (ans.cnt > 0) checkmin(ans.ans, B * ans.cnt * (vr - vl));
    return ans;
}

struct Tree {
    node t[N];
    int cnt = 2;
    void add(int &v) {
        if (v == 0) v = cnt++;
    }
    void update(int r, int v, int vl, int vr) {
        ++t[v].cnt;
        t[v].ans = B * t[v].cnt * (vr - vl);
        if (vl + 1 == vr) return;
        int vm = vl + vr >> 1;
        if (r < vm) add(t[v].l), update(r, t[v].l, vl, vm);
        else add(t[v].r), update(r, t[v].r, vm, vr);
        //if (v == 1 && r >= vm) cout << t[v].r << '\n';
        //cout << vl << ' ' << vr << ' ' << t[v].l << ' ' << t[v].r << ' ' << t[v].cnt << '\n';
        t[v] = merge(t[t[v].l], t[t[v].r], vl, vr);
    }
} t;

signed main() {
    FAST; FIXED; RANDOM;
    ll n, k;
    cin >> n >> k >> A >> B;
    t.t[0] = node(A);
    while (k--) {
        int pos;
        cin >> pos;
        --pos;
        t.update(pos, 1, 0, 1 << n);
    }
    cout << t.t[1].ans;
    return 0;
}