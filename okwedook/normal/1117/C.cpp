#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

signed main() {
    FAST; FIXED; RANDOM;
    ll x1, y1, x2, y2;
    ll n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    string s;
    cin >> s;
    x2 -= x1;
    y2 -= y1;
    ll sumx = 0, sumy = 0;
    vector<ll> px(n), py(n);
    int cnt = 0;
    for (auto i : s) {
        if (i == 'U') sumy++;
        if (i == 'D') sumy--;
        if (i == 'R') sumx++;
        if (i == 'L') sumx--;
        px[cnt] = sumx;
        py[cnt] = sumy;
        ++cnt;
    }
    ll mx = 2e18 + 100;
    ll l = 0, r = mx;
    while (r - l > 1) {
        ll m = r + l >> 1;
        ll posx = m / n * sumx + (m % n > 0 ? px[m % n - 1] : 0);
        ll posy = m / n * sumy + (m % n > 0 ? py[m % n - 1] : 0);
        if (abs(posx - x2) + abs(posy - y2) <= m) r = m;
        else l = m;
    }
    if (r == mx) cout << -1;
    else cout << r;
    return 0;
}