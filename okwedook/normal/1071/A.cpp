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

ll check(ll a, ll b, ll l) {
    ll ans = 0;
    for (int i = l; i >= 1; --i)
        if (b >= i) b -= i, ++ans;
        else if (a >= i) a -= i, ++ans;
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll a, b;
    cin >> a >> b;
    vector<ll> ansa, ansb;
    ll l = 1, r = 500000;
    while (r - l > 3) {
        ll m1 = l + (r - l) / 3, m2 = r - (r - l) / 3;
        if (check(a, b, m1) < check(a, b, m2)) l = m1;
        else r = m2;
    }
    ll ans = l;
    for (ll i = l; i <= r; ++i)
        if (check(a, b, i) > check(a, b, ans))
            ans = i;
    for (int i = ans; i >= 1; --i)
        if (b >= i) b -= i, ansb.pb(i);
        else if (a >= i) a -= i, ansa.pb(i);
    cout << sz(ansa) << '\n';
    for (auto i : ansa) cout << i << ' ';
    cout << '\n';
    cout << sz(ansb) << '\n';
    for (auto i : ansb) cout << i << ' ';
    return 0;
}