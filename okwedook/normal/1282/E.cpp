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

void dele(map<pii, set<int>> &edge, pii curr, int ind) {
    if (sz(edge[curr]) == 1) edge.erase(curr);
    else edge[curr].erase(ind);
}

void solve() {
    static vector<pii> d = {
        {0, 1},
        {1, 2},
        {0, 2}
    };
    static vector<int> left = {
        2,
        0,
        1
    };
    int n;
    cin >> n;
    vector<vector<int>> a(n - 2, vector<int>(3));
    for (auto &i : a) {
        cin >> i;
        sort(i);
    }
    vector<map<pii, set<int>>> edge(3);
    for (int i = 1; i < sz(a); ++i)
        for (int j = 0; j < 3; ++j)
            edge[j][{a[i][d[j].f], a[i][d[j].s]}].insert(i);
    map<int, int> right;
    right[a[0][0]] = a[0][1];
    right[a[0][1]] = a[0][2];
    right[a[0][2]] = a[0][0];
    set<pii> currst = {
        {a[0][0], a[0][1]},
        {a[0][1], a[0][2]},
        {a[0][0], a[0][2]}
    };
    vector<int> del = {0};
    while (sz(currst)) {
        auto curr = *currst.begin();
        currst.erase(curr);
        for (int j = 0; j < 3; ++j)
            if (edge[j].count(curr)) {
                int ind = *edge[j][curr].begin();
                for (int k = 0; k < 3; ++k)
                    dele(edge[k], {a[ind][d[k].f], a[ind][d[k].s]}, ind);
                for (int k = 0; k < 3; ++k)
                    currst.insert({a[ind][d[k].f], a[ind][d[k].s]});
                if (right[curr.f] != curr.s) swap(curr.f, curr.s);
                right[curr.f] = a[ind][left[j]];
                right[a[ind][left[j]]] = curr.s;
                del.pb(ind);
                break;
            }
    }
    reverse(del);
    int x = a[0][0];
    for (int i = 0; i < n; ++i) {
        cout << x << ' ';
        x = right[x];
    }
    cout << '\n';
    for (auto i : del) cout << i + 1 << ' ';
    cout << endl;
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}