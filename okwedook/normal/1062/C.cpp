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
#define mod 1000000007
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

ll n, q;

struct Fenv {
    static const int n = 1000000;
    ll fenv[n];
    void add(int r) {
        for (; r < n; r |= r + 1) ++fenv[r];
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ans += fenv[r];
        return ans;
    }
    ll get(ll l, ll r) {
        return get(r) - get(l - 1);
    }
} fenv[2];

ll binpow(ll a, ll n) {
    if (n < 0) return 0;    
    if (n == 0) return 1;
    if (n & 1) return (a * binpow(a, n - 1)) % mod;
    ll k = binpow(a, n / 2);
    return (k * k) % mod;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
        fenv[s[i] - '0'].add(i);
    while (q--) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        ll c1 = fenv[1].get(l, r);
        ll c0 = fenv[0].get(l, r);
        if (c1 == 0) cout << 0 << '\n';
        else cout << (binpow(2, c1) - 1 + (binpow(2, c0) - 1) * (binpow(2, c1) - 1)) % mod << '\n';
    }
    return 0;
}