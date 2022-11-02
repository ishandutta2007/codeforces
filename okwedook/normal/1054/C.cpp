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
    ll n;
    cin >> n;
    vector<ll> l(n), r(n);
    for (auto &i : l) cin >> i;
    for (auto &i : r) cin >> i;
    for (int i = 0; i < n; ++i)
        if (l[i] > i) {
            cout << "NO";
            return 0;
        }
    reverse(r);
    for (int i = 0; i < n; ++i)
        if (r[i] > i) {
            cout << "NO";
            return 0;
        }
    reverse(r);
    vector<int> ans(n, -1001);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (l[i] == 0 && r[i] == 0)
            ++cnt, ans[i] = n;
    for (int curr = n - 1; curr >= 1; --curr) {
        int currcnt = 0, add = 0;
        for (int i = 0; i < n; ++i) {
            if (ans[i] > curr) ++currcnt;
            if (l[i] == currcnt && r[i] == cnt - currcnt) ans[i] = curr, ++add;
        }
        cnt += add;
    } 
    for (int i = 0; i < n; ++i)
        if (ans[i] < 1) {
            cout << "NO";
            return 0;
        }
    cout << "YES\n";
    for (auto i : ans) cout << i << ' ';
    return 0;
}