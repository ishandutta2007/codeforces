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

signed main() {
    FAST;
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    map<ll, ll> mapp;
    for (auto i : arr) mapp[i]++;
    pll ans = mp(0, 1);
    ll anscnt = mapp[ans.f - 1] + mapp[ans.f] + mapp[ans.f + 1];
    for (int i = 0; i < n; ++i) {
        ll checkans = mapp[arr[i]];
        ll d = 1;
        while (d <= 2e9) {
            ll k = (mapp.count(arr[i] - d) ? mapp[arr[i] - d] : 0) + (mapp.count(arr[i] + d) ? mapp[arr[i] + d] : 0);
            if (checkans + k > anscnt) {
                anscnt = checkans + k;
                ans = mp(arr[i], d);
            }
            d *= 2;
        }
    }
    cout << mapp[ans.f - ans.s] + mapp[ans.f] + mapp[ans.f + ans.s] << '\n';
    for (ll i = mapp[ans.f - ans.s]; i > 0; --i) cout << ans.f - ans.s << ' ';
    for (ll i = mapp[ans.f]; i > 0; --i) cout << ans.f << ' ';
    for (ll i = mapp[ans.f + ans.s]; i > 0; --i) cout << ans.f + ans.s << ' ';
    return 0;
}