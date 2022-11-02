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

struct mex {
    set<int> poss, used;
    mex() { poss.insert(1); }
    void add(int x) { used.insert(x); poss.erase(x); if (!used.count(x + 1)) poss.insert(x + 1); }
    int get() { return *poss.begin(); }
};

graph G;
vector<int> color;

void dfs(int v, int p = -1) {
    mex ans;
    if (p >= 0) ans.add(color[p]);
    if (color[v] < 0) color[v] = ans.get();
    ans.add(color[v]);
    for (auto i : G[v])
        if (i != p) {
            color[i] = ans.get();
            ans.add(color[i]);
        }
    for (auto i : G[v]) if (i != p) dfs(i, v);
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    G = graph(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].pb(v);
        G[v].pb(u);
    }
    pii head = {-1, 0};
    for (int i = 0; i < n; ++i) checkmax(head, pii(sz(G[i]), i));
    color = vector<int>(n, -1);
    dfs(head.s);
    int ans = 0;
    for (auto i : color) checkmax(ans, i);
    cout << ans << '\n';
    for (auto i : color) cout << i << ' ';
    return 0;
}