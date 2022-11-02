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

bool cmp(const pair<pll, ll> &a, const pair<pll, ll> &b) {
    return a.f.f - b.f.f < a.f.s - b.f.s;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, m;
    cin >> n >> m;
    vector<pair<pll, ll>> arr(n);
    int cnt = 0;
    for (auto &i : arr) cin >> i.f.f >> i.f.s, i.s = cnt++;
    vector<pll> start(n);
    for (int i = 0; i < n; ++i)
        start[i] = arr[i].f;
    sort(all(arr), cmp);
    vector<ll> ans(n);
    ll curr = 0;
    for (int i = 0; i < n; ++i) {
        ans[arr[i].s] += curr + arr[i].f.s * i;
        curr += arr[i].f.f;
    }
    curr = 0;
    for (int i = n - 1; i >= 0; --i) {
        ans[arr[i].s] += curr + arr[i].f.f * (n - i - 1);
        curr += arr[i].f.s;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        if (start[x].f + start[y].s < start[x].s + start[y].f) {
            ans[x] -= start[y].s + start[x].f;
            ans[y] -= start[y].s + start[x].f;
        } else {
            ans[x] -= start[y].f + start[x].s;
            ans[y] -= start[y].f + start[x].s;
        }
    }
    for (auto i : ans) cout << i << ' ';
    return 0;
}