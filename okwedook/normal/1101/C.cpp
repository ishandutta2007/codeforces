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

void ex() {
    cout << -1;
    exit(0);
}

bool intersect(pll a, pll b) {
    if (a.f > b.f) swap(a, b);
    return a.s >= b.f;
}

void solve() {
    int n;
    cin >> n;
    vector<pair<pll, ll>> arr(n);
    for (auto &i : arr) cin >> i.f.f >> i.f.s;
    for (int i = 0; i < n; ++i) arr[i].s = i; 
    sort(arr);  
    vector<int> ans(n, 2);
    ans[0] = 1;
    for (int i = 1; i < n; ++i)
        if (intersect(arr[0].f, arr[i].f)) {
            checkmax(arr[0].f.s, arr[i].f.s);
            ans[i] = 1;
        }
    bool flag = false;
    for (int i = 0; i < n; ++i) 
        flag = flag || ans[i] == 2;
    if (!flag) cout << -1 << '\n';
    else {
        vector<int> newans(n);
        for (int i = 0; i < n; ++i)
            newans[arr[i].s] = ans[i];
        for (auto i : newans) cout << i << ' ';
        cout << '\n';
    }
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}