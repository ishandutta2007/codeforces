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
template<class T, class U> inline istream& operator>>(istream &stream, pair<T, U> &a) { return stream >> a.f >> a.s; }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) {
    for (auto &i : a) stream >> i;
    return stream;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n, m;
    cin >> n >> m;
    graph G(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    vector<bool> used(n);
    used[0] = true;
    set<int> que;
    que.insert(0);
    vector<int> ans(0, 0);
    while (sz(que)) {
        int fr = *que.begin();
        que.erase(fr);
        ans.pb(fr);
        for (auto i : G[fr])
            if (!used[i]) {
                used[i] = true;
                que.insert(i);
            }
    }
    for (auto i : ans) cout << i + 1 << ' ';
    return 0;
}