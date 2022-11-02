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

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<pll> arr;
    arr.pb({0, 0});
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        arr.pb({u, v});
    }
    vector<pll> brr;
    pll past = {-10, -10};
    for (auto i : arr) {
        if (i != past) brr.pb(i);
        past = i;
    }
    arr = brr;
    n = sz(arr);
    /*if (n == 1) {
        cout << 1;
        return 0;
    }*/
    ll ans = 0;
    for (int i = 1; i < n; ++i) {
        ll pans = ans;
        ans += max(0ll, min(arr[i].f, arr[i].s) - max(arr[i - 1].f, arr[i - 1].s) + 1);
        //cout << ans - pans << '\n';
        if (arr[i].f == arr[i].s) --ans;
    }
    if (arr.back().f == arr.back().s) ++ans;
    cout << ans;
    return 0;
}