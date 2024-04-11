#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
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
#define mod 998244353
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

ll manh(ll x1, ll y1, ll x2, ll y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

set<pii> answer;

void add(pii a, pii to) {
    answer.insert(a);
    if (a == to) return;
    if (a.f < to.f) return add({a.f + 1, a.s}, to);
    if (a.f > to.f) return add({a.f - 1, a.s}, to);
    if (a.s < to.s) return add({a.f, a.s + 1}, to);
    if (a.s > to.s) return add({a.f, a.s - 1}, to);
}

signed main() {
    FAST; FIXED; RANDOM;
    ll xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ll ans = inf;
    pii to;
    for (int x = min(xa, xb); x <= max(xa, xb); ++x)
        for (int y = min(ya, yb); y <= max(ya, yb); ++y) {
            ll c = manh(x, y, xc, yc);
            if (c < ans) {
                ans = c;
                to = {x, y};
            }
        }
    add({xa, ya}, to);
    add({xb, yb}, to);
    add({xc, yc}, to);
    cout << sz(answer) << '\n';
    for (auto i : answer) cout << i.f << ' ' << i.s << '\n';
    return 0;
}