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

vector<int> p;
vector<vector<int>> arr;

void makeset(int v) {
    if (p[v] < 0) p[v] = v;
}

int findset(int v) {
    return v == p[v] ? v : p[v] = findset(p[v]);
}

void unite(int a, int b) {
    a = findset(a);
    b = findset(b);
    if (sz(arr[a]) > sz(arr[b])) swap(a, b);
    for (auto i : arr[a]) arr[b].pb(i);
    p[a] = b;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    arr = vector<vector<int>> (n);
    p = vector<int> (n, -1);
    for (int i = 0; i < n; ++i) 
        makeset(i);
    for (int i = 0; i < n; ++i) arr[i].pb(i);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        unite(u, v);
    }
    int a = findset(0);
    for (auto i : arr[a]) cout << i + 1 << ' ';
    return 0;
}