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
#define mod 1000007
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

ll n, m;

bool in(ll x, ll y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll r, c, x, y;
    cin >> n >> m >> r >> c >> x >> y;
    --r, --c;
    vector<string> arr(n);
    for (auto &i : arr) cin >> i;
    deque<pair<pll, pll>> deq;
    vector<vector<bool>> used(n, vector<bool>(m));
    used[r][c] = true;
    deq.pb(mp(mp(r, c), mp(x, y)));
    while (sz(deq) > 0) {
        auto fr = deq.front();
        deq.popf();
        ll x = fr.f.f, y = fr.f.s;
        if (in(x + 1, y) && arr[x + 1][y] == '.' && !used[x + 1][y]) {
            used[x + 1][y] = true;
            deq.pf(mp(mp(x + 1, y), fr.s));
        }
        if (in(x - 1, y) && arr[x - 1][y] == '.' && !used[x - 1][y]) {
            used[x - 1][y] = true;
            deq.pf(mp(mp(x - 1, y), fr.s));
        }
        if (in(x, y + 1) && arr[x][y + 1] == '.' && !used[x][y + 1] && fr.s.s > 0) {
            used[x][y + 1] = true;
            deq.pb(mp(mp(x, y + 1), mp(fr.s.f, fr.s.s - 1)));
        }
        if (in(x, y - 1) && arr[x][y - 1] == '.' && !used[x][y - 1] && fr.s.f > 0) {
            used[x][y - 1] = true;
            deq.pb(mp(mp(x, y - 1), mp(fr.s.f - 1, fr.s.s)));
        }
    }
    ll ans = 0;
    for (auto i : used) 
        for (auto j : i)
            ans += j; 
    cout << ans;
    return 0;
}