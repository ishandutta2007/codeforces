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
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
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
vector<ll> color;
graph G, tree;
vector<ll> c2, c1;
bool flag = false;

void orient(int v, int p = -1) {
    for (auto i : G[v])
        if (i != p) {
            tree[v].pb(i);
            orient(i, v);
        }
}

void dfscount(int v) {
    c2[v] = color[v] == 2;
    c1[v] = color[v] == 1;
    for (auto i : tree[v]) {
        dfscount(i);
        c2[v] += c2[i];
        c1[v] += c1[i];
    }
}

ll dfsadd(int v, ll c) {
    ll ans = 0;
    if (c > 0 && c2[v] == c && c1[v] == 0) ++ans;
    if (c2[v] < c && c2[v] > 0 && c1[v] > 0) flag = true;
    for (auto i : tree[v])
        ans += dfsadd(i, c);
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    color = vector<ll>(n);
    cin >> color;
    G = tree = graph (n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    ll head = -1;
    for (int i = 0; i < n; ++i)
        if (color[i] == 1) head = i;
    orient(head);
    c1 = c2 = vector<ll>(n);
    ll ans = 0;
    for (auto i : tree[head]) {
        dfscount(i);
        flag = false;
        ll add = dfsadd(i, c2[i]);
        if (ans > 0 && add > 0 || flag) {
            ans = 0;
            break;
        }
        ans += dfsadd(i, c2[i]);
    }
    cout << ans;
    return 0;
}