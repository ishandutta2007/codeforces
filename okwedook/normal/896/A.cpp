#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(235345)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string before = "What are you doing while sending \"";
string middle = "\"? Are you busy? Will you send \"";
string endd = "\"?";
vector<ll> len;

char solve(ll n, ll k) {
    if (n == 0) return k < sz(f0) ? f0[k] : '.';
    if (k < sz(before)) return before[k];
    k -= sz(before);
    if (k < len[n - 1]) return solve(n - 1, k);
    k -= len[n - 1];
    if (k < sz(middle)) return middle[k];
    k -= sz(middle);
    if (k < len[n - 1]) return solve(n - 1, k);
    k -= len[n - 1];
    if (k < sz(endd)) return endd[k];
    return '.';
}

signed main() {
    FAST; FIXED; RANDOM;
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        len = vector<ll>(n + 1);
        len[0] = sz(f0);
        for (ll i = 1; i <= n; ++i) {
            len[i] = sz(before) + len[i - 1] + sz(middle) + len[i - 1] + sz(endd);
            checkmin(len[i], inf);
        }
        cout << solve(n, k - 1);
    }
    return 0;
}