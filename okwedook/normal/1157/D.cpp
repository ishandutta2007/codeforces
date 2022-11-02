#pragma GCC optimize("Ofast", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <bitset>
#include <random>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(38242)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define f first
#define s second
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define hashmap unordered_map
#define hashset unordered_set
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

void ex() {
    cout << "NO";
    exit(0);
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, k;
    cin >> n >> k;
    if (k * (k + 1) / 2 > n) ex();
    vector<ll> a(k);
    for (int i = 0; i < k; ++i) a[i] = i + 1;
    n -= k * (k + 1) / 2;
    ll add = 0;
    for (ll i = 0; i < k; ++i) {
        ll d = n / (k - i);
        a[i] += add;
        if (i > 0) checkmin(d, 2 * a[i - 1] - a[i]);
        n -= d * (k - i);
        a[i] += d;
        add += d;
    }
    if (n != 0) ex();
    cout << "YES\n";
    for (auto i : a) cout << i << ' ';
    return 0;
}