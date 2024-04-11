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
    vector<vector<pll>> arr(n);
    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        --a, --b, c *= 2;
        arr[a].pb(mp(b, c));
        arr[b].pb(mp(a, c));
    }
    vector<ll> ans(n);
    for (auto &i : ans) cin >> i;
    set<pll> st;
    for (int i = 0; i < n; ++i) st.insert(mp(ans[i], i));
    vector<bool> used(n);
    while (sz(st)) {
        pll beg = *(st.begin());
        st.erase(st.begin());
        if (used[beg.s]) continue;
        used[beg.s] = true;
        for (auto i : arr[beg.s]) {
            if (ans[i.f] > beg.f + i.s) {
                st.erase(mp(ans[i.f], i.f));
                ans[i.f] = beg.f + i.s;
                st.insert(mp(ans[i.f], i.f));
            }
        }
    }
    for (auto i : ans) cout << i << ' ';
    return 0;
}