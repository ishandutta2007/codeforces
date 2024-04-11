#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(9)
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
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }

int main() {
    FAST; FIXED; RANDOM;
    ll n, h;
    cin >> n >> h;
    vector<pll> arr(n);
    for (auto &i : arr) cin >> i.f >> i.s;
    vector<pll> brr(n);
    for (int i = 1; i < n; ++i)
        brr[i - 1] = mp(arr[i - 1].s, arr[i].f);
    brr[n - 1] = mp(arr[n - 1].s, (ll)mod * 10ll);
    vector<ll> pref(n);
    for (int i = 0; i < n; ++i)
        pref[i] = brr[i].s - brr[i].f;
    for (int i = 1; i < n; ++i)
        pref[i] += pref[i - 1];
    ll ans = 0, curr = 0;
    for (int i = 0; i < n; ++i) {
        int l = i - 1, r = n;
        while (r - l > 1) {
            int m = r + l >> 1;
            if (pref[m] - curr >= h) r = m;
            else l = m;
        }
        checkmax(ans, brr[r].f - arr[i].f + (h - ((l >= 0 ? pref[l] : 0) - curr)));
        curr += brr[i].s - brr[i].f;
    }
    cout << ans;
    return 0;
}