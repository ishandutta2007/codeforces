#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
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
#define mod 998244353
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

vector<vector<pii>> G;
int cnt = 0;
vector<bool> used;
set<int> arr1, arr2;
vector<int> add;
int cut = 0;

void dfscnt(int v) {
    cnt += add[v];
    used[v] = true;
    for (auto i : G[v])
        if (i.s <= cut && !used[i.f])
            dfscnt(i.f);
}

void add1(int v) {
    arr1.insert(v);
    used[v] = true;
    for (auto i : G[v])
        if (i.s <= cut && !used[i.f])
            add1(i.f);
}

void add2(int v) {
    arr2.insert(v);
    used[v] = true;
    for (auto i : G[v])
        if (i.s <= cut && !used[i.f])
            add2(i.f);
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, m, k;
    cin >> n >> m >> k;
    G.resize(n);
    add.resize(n);
    vector<int> x(k);
    for (auto &i : x) cin >> i, --i, add[i] = 1;
    int l = -1, r = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].pb({v, w});
        G[v].pb({u, w});
        checkmax(r, w);
    }
    while (r - l > 1) {
        cut = r + l >> 1;
        used = vector<bool>(n);
        cnt = 0;
        dfscnt(x[0]);
        if (cnt == k) r = cut;
        else l = cut;
    }
    cut = r;
    used = vector<bool>(n);
    for (int i = 0; i < n; ++i)
        for (auto j : G[i])
            if (j.s == cut) {
                used[i] = true;
                used[j.f] = true;
                add1(i);
                add2(j.f);
                break;
            }
    for (auto i : x) {
        cout << cut << ' ';
    }
    return 0;
}