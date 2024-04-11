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

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<ll> a, b, all, none;
    for (auto &i : arr) {
        string s;
        cin >> s;
        ll x;
        cin >> x;
        if (s == "11") all.pb(x);
        else if (s == "10") a.pb(x);
        else if (s == "01") b.pb(x);
        else none.pb(x);
    }
    ll ans = 0;
    rsort(a);
    rsort(b);
    rsort(none);
    for (auto &i : all) ans += i;
    for (ll i = 0; i < min(sz(a), sz(b)); ++i)
        ans += a[i] + b[i];
    for (ll i = min(sz(a), sz(b)); i < sz(a); ++i) none.pb(a[i]);
    for (ll i = min(sz(a), sz(b)); i < sz(b); ++i) none.pb(b[i]);
    rsort(none);
    for (ll i = 0; i < sz(none) && i < sz(all); ++i) ans += none[i];
    cout << ans;
    return 0;
}