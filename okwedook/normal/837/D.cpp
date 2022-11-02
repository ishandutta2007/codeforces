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
    ll n, k;
    cin >> n >> k;
    vector<ll> arr(n);
    vector<pll> brr(n);
    for (auto &i : arr) cin >> i;
    for (int i = 0; i < n; ++i) {
        while (arr[i] % 2 == 0) brr[i].s++, arr[i] /= 2;
        while (arr[i] % 5 == 0) brr[i].f++, arr[i] /= 5;
    }
    hashmap<ll, ll> st[201];
    vector<pair<pll, ll>> st1;
    ll cnt = 1;
    for (auto i : brr) {
        st1.clear();
        for (int m = 1; m < cnt && m < k; ++m) {
            for (auto j : st[m]) 
                st1.pb(mp(mp(m + 1, j.f + i.s), j.s + i.f));
        }
        for (auto i : st1) checkmax(st[i.f.f][i.f.s], i.s);
        checkmax(st[1][i.s], i.f);
        ++cnt;
    }
    ll ans = 0;
    for (int m = 1; m <= k; ++m)
        for (auto j : st[m])
            checkmax(ans, min(j.f, j.s));
    cout << ans;
    return 0;
}