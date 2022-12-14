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
#define eps 1e-15
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

struct vec {
    ll x[5];
    vec operator+=(const vec &v) { for (int i = 0; i < 5; ++i) x[i] += v.x[i]; return *this; }
    vec operator-=(const vec &v) { for (int i = 0; i < 5; ++i) x[i] -= v.x[i]; return *this; }
    friend vec operator+(vec a, const vec &b) { return a += b; }
    friend vec operator-(vec a, const vec &b) { return a -= b; }
    ll len2() const { return *this * *this; }
    ll operator*(const vec &v) const {
        ll ans = 0;
        for (int i = 0; i < 5; ++i) ans += x[i] * v.x[i];
        return ans;
    }
    friend istream& operator>>(istream& str, vec &v) {
        for (int i = 0; i < 5; ++i) str >> v.x[i];
        return str;
    }
};

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<vec> arr(n);
    if (n > 100) {
        cout << 0;
        return 0;
    }
    cin >> arr;
    vector<bool> can(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (i != j)
                for (int k = 0; k < n; ++k)
                    if (i != k && j != k) {
                        if ((arr[j] - arr[i]) * (arr[k] - arr[i]) > 0)
                            can[i] = false;
                    }
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i)
        if (can[i]) ans.pb(i + 1);
    cout << sz(ans) << '\n';
    for (auto i : ans) cout << i << ' ';
    return 0;
}