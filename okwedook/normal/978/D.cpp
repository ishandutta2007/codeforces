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
    ll n;
    cin >> n;
    if (n < 3) {
        cout << 0;
        return 0;
    }
    ll ans = inf;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    for (ll d1 = -1; d1 <= 1; ++d1)
        for (ll d2 = -1; d2 <= 1; ++d2) {
            vector<ll> check(n);
            check[0] = arr[0] + d1;
            check[1] = arr[1] + d2;
            for (int i = 2; i < n; ++i)
                check[i] = 2 * check[i - 1] - check[i - 2];
            ll checkans = 0;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (abs(check[i] - arr[i]) > 1) {
                    flag = false;
                    break;
                }
                checkans += abs(check[i] - arr[i]);
            }
            if (flag) checkmin(ans, checkans);
        }
    if (ans == inf) cout << -1;
    else cout << ans;
    return 0;
}