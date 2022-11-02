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
    vector<ll> a(n);
    for (auto &i : a) cin >> i;
    if (n == 1) {
        cout << a[0];
        return 0;
    }
    ll mn = inf, s = 0;
    vector<ll> pref(n), suff(n);
    for (int i = 0; i < n; ++i) {
        checkmin(mn, a[i]);
        s += abs(a[i]);
        if (mn < 0) pref[i] = s;
        else pref[i] = s - 2 * abs(mn);
    }
    mn = inf, s = 0;
    for (int i = n - 1; i >= 0; --i) {
        checkmin(mn, a[i]);
        s += abs(a[i]);
        if (mn < 0) suff[i] = s;
        else suff[i] = s - 2 * abs(mn);
    }
    ll ans = max(a[0] + suff[1], a[n - 1] + pref[n - 2]);
    for (int i = 1; i < n - 1; ++i)
        checkmax(ans, a[i] + pref[i - 1] + suff[i + 1]);
    cout << ans;
    return 0;
}