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

int main() {
    FAST; FIXED; RANDOM;
    ll n, k;
    cin >> n >> k;
    graph G(n);
    vector<ll> r(n);
    for (auto &i : r) cin >> i;
    vector<pll> arr(n);
    for (int i = 0; i < n; ++i) arr[i] = mp(r[i], i);
    sort(arr);
    ll curr = 0, add = 0, p = -1;
    vector<ll> ans(n);
    for (int i = 0; i < n; ++i) {
        if (arr[i].f != p) curr += add, add = 0;
        ans[arr[i].s] = curr;
        ++add;
        p = arr[i].f;
    }

    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        G[x].pb(y);
        G[y].pb(x);
    }
    for (int i = 0; i < n; ++i)
        for (auto j : G[i])
            if (r[j] < r[i])
                --ans[i];
    for (auto i : ans) cout << i << ' ';
    return 0;
}