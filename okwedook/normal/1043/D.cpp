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

signed main() {
    FAST; FIXED; RANDOM;
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> arr(m, vector<ll>(n));
    for (auto &i : arr)
        for (auto &j : i)
            cin >> j, --j;
    vector<vector<ll>> pos(m, vector<ll>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            pos[i][arr[i][j]] = j; 
    vector<int> ptr(m, 0);
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int mx = n;
        if (ptr[0] <= i)
            for (int j = 0; j < m; ++j) {
                ptr[j] = pos[j][arr[0][i]];
                checkmin(mx, n - ptr[j]);
            }
        mx += i;
        while (ptr[0] < mx && ptr[0] < n) {
            bool flag = true;
            for (int j = 0; j < m; ++j)
                if (arr[j][ptr[j]] != arr[0][ptr[0]]) {
                    flag = false;
                    break;
                }
            if (!flag) break;
            for (auto &i : ptr) ++i;
        }
        ans += ptr[0] - i;

    }
    cout << ans;
    return 0;
}