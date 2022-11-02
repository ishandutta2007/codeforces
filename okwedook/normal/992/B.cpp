#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
 
#include <bits/stdc++.h>
using namespace std;
 
template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void rsort(T1 &arr) { sort(arr.rbegin(), arr.rend()); }
template<typename T1> inline void shuffle(T1 &arr) {
    for (int i = -int(arr.size()); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

ll gcd(ll a, ll b) {
    return a > 0 ? gcd(b % a, a) : b;
}

signed main() {
    FAST;
    ll l, r, x, y;
    cin >> l >> r >> x >> y;
    if (y % x != 0) {
        cout << 0;
        return 0;
    }
    y /= x;
    ll ans = 0;
    for (ll i = 1; i * i <= y; ++i) {
        if (y % i == 0 && i * x >= l && i * x <= r && (y / i) * x >= l && (y / i) * x <= r && 
            gcd(i, y / i) == 1) {
            ans += 2;
            if (i * i == y) --ans;
        }
    }
    cout << ans;
    return 0;
}