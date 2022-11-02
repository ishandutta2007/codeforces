#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll int
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
#define checkmin(x, y) if (x > y) x = y
#define checkmax(x, y) if (x < y) x = y
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); } 

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    ll ans = 0;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    ll g = arr[0];
    for (auto i : arr) g = __gcd(g, i);
    for (auto &i : arr) i /= g;
    map<ll, ll> st;
    for (auto &i : arr) {
        for (ll j = 2; j * j <= i && n * j < 15000000; ++j)
            if (i % j == 0) {
                st[j]++;
                while (i % j == 0) i /= j;
            }
        if (i > 1) st[i]++;
    }
    ll mx = 0;
    for (auto i : st) 
        checkmax(mx, i.s);
    if (mx == 0) cout << -1;
    else cout << n - mx;
    return 0;
}