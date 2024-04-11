#pragma GCC optimize("O3", "unroll-loops")

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
#define mod 1000000007
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

int n;

vector<int> inverse(vector<int> a) {
    vector<bool> used(n);
    vector<int> b;
    for (auto i : a) used[i] = true;
    for (int i = 0; i < n; ++i)
        if (!used[i]) b.pb(i);
    return b;
}

bool sub(vector<int> a, vector<int> b) {
    int ptr = 0;
    for (auto i : a) {
        while (ptr < sz(b) && b[ptr] < i) ++ptr;
        if (ptr == sz(b)) return false;
        if (b[ptr] != i) return false;
        ++ptr;
    }
    return sz(a) < sz(b);
}

map<vector<int>, vector<vector<int>>> G;
map<vector<int>, int> color;

void dfs(vector<int> v) {
    color[v] = 1;
    for (auto i : G[v]) {
        if (color[i] == 1) {
            cout << "impossible";
            exit(0);
        }
        if (color[i] != 2) dfs(i);
    }
    color[v] = 2;
}

signed main() {
    FAST; FIXED; RANDOM;
    int m;
    cin >> m >> n;
    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        vector<int> a(s);
        cin >> a;
        for (auto &i : a) --i;
        sort(a);
        G[inverse(a)].pb(a);
        G[a];
    }
    vector<vector<int>> a;
    for (auto i : G) a.pb(i.f);
    for (int i = 0; i < sz(a); ++i)
        for (int j = 0; j < sz(a); ++j)
            if (sub(a[i], a[j])) G[a[i]].pb(a[j]);
    for (auto i : G)
        if (!color[i.f]) dfs(i.f);
    cout << "possible";
    return 0;
}