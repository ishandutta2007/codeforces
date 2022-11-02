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

struct Fenv {
    static const ll n = 200005;
    ll fenv[n];
    void add(ll r, ll x) {
        for (; r < n; r |= r + 1) fenv[r] += x;
    }
    ll get(ll r) {
        ll ans = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ans += fenv[r];
        return ans;
    }
    ll get(ll l, ll r) {
        return get(r) - get(l - 1);
    }
};

Fenv price, cnt;
ll allsum;
ll n, t;

ll get(ll r) {
    if (r < 0) return 0;
    return (r / n) * allsum + price.get(r % n);
}

ll get(ll l, ll r) {
    return get(r) - get(l - 1);
}

ll getcnt(ll r) {
    if (r < 0) return 0;
    return (r / n) * cnt.get(n - 1) + cnt.get(r % n);
}

ll getcnt(ll l, ll r) {
    return getcnt(r) - getcnt(l - 1);
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n >> t;
    for (int i = 0; i < n; ++i) cnt.add(i, 1);
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    for (auto i : arr) allsum += i;
    for (int i = 0; i < n; ++i) price.add(i, arr[i]);
    ll curr = 0, ans = 0;
    while (t > 0 && allsum > 0) {
        ll l = curr - 1, r = curr + t / allsum * n + n + 2;
        while (r - l > 1) {
            ll m = r + l >> 1;
            ll x = get(curr, m);
            if (x > t) r = m;
            else l = m;
        }
        t -= get(curr, r) - arr[r % n];
        price.add(r % n, -arr[r % n]);
        ans += getcnt(curr, r) - 1;
        cnt.add(r % n, -1);
        allsum -= arr[r % n];
        curr = r;
    }
    cout << ans;
    return 0;
}