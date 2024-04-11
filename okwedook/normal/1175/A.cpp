#pragma GCC optimize("O3", "unroll-loops")
  
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <bitset>
#include <random>
  
using namespace std;
  
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(392403285);
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define f first
#define s second
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define pb push_back
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
  
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

void solve() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    while (n > 0) {
        ans += n % k;
        n -= n % k;
        if (n == 0) break;
        ++ans;
        n /= k;
    }
    cout << ans << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    ll t;
    cin >> t;
    while (t--) solve();
    return 0;   
}