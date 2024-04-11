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
    ll n, m;
    cin >> n >> m;
    vector<ll> arr(n), brr(m);
    for (auto &i : arr) cin >> i;
    for (auto &j : brr) cin >> j;
    ll x;
    cin >> x;
    vector<pll> aarr, bbrr;
    for (int i = 0; i < n; ++i) {
        ll curr = 0;
        for (int k = i; k < n; ++k)
            curr += arr[k], aarr.pb(mp(k - i + 1, curr));
    }
    sort(aarr);
    map<ll, ll> st;
    for (int i = 0; i < m; ++i) {
        ll curr = 0;
        for (int k = i; k < m; ++k) {
            curr += brr[k];
            if (st.count(k - i + 1)) {
                checkmin(st[k - i + 1], curr);
            } else st[k - i + 1] = curr;
        }
    }
    for (auto i : st) bbrr.pb(mp(i.s, i.f));
    sort(bbrr);
    ll ans = 0;
    for (auto i : aarr) {
        ll l = -1, r = sz(bbrr);
        while (r - l > 1) {
            ll m = r + l >> 1;
            if (x / bbrr[m].f >= i.s) l = m;
            else r = m;
        }
        if (l >= 0) checkmax(ans, bbrr[l].s * i.f);
    }
    cout << ans;
    return 0;
}