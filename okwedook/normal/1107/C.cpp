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
#define eps 1e-13
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

struct mx {
    deque<pll> deq;
    ll k;
    void add(ll x, ll i) {
        while (sz(deq) > 0 && deq.back().f > x) deq.popb();
        deq.pb({x, i});
    }
    ll get(ll i) {
        while (sz(deq) > 0 && deq.front().s <= i - k) deq.popf();
        if (sz(deq) == 0) return 0;
        return deq.front().f;
    }
};  

signed main() {
    FAST; FIXED; RANDOM;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    cin >> a;
    string s;
    cin >> s;
    char past = -1;
    vector<pair<char, vector<ll>>> arr;
    vector<ll> curr(0, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] != past) {
            if (sz(curr) > 0) arr.pb({past, curr});
            curr.resize(0);
        }
        past = s[i];
        curr.pb(a[i]);
    }
    arr.pb({past, curr}); 
    ll ans = 0;
    for (auto &i : arr) {
        rsort(i.s);
        for (int j = 0; j < sz(i.s) && j < k; ++j) {
            ans += i.s[j];
        }
    }
    cout << ans;
    return 0;
}