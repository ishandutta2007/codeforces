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

struct sum {
    ll b, w;
    sum() {}
    sum(ll b, ll w) {
        this->b = b;
        this->w = w;
    }
    sum operator-(const sum &s) const {
        return sum(b - s.b, w - s.w);
    }
    sum operator+(const sum &s) const {
        return sum(b + s.b, w + s.w);
    }
    void operator+=(const sum &s) {
        b += s.b;
        w += s.w;
    }
    void operator-=(const sum &s) {
        b -= s.b;
        w -= s.w;
    }
    friend ostream& operator<<(ostream &stream, const sum &s) {
        return stream << s.w << ' ' << s.b;
    }
};

pll persegm(ll a, ll b, ll c, ll d) {
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }
    if (b < c) return {a, a - 1};
    if (d < b) return {c, d};
    return {c, b};
}

struct rect {
    ll x1, y1, x2, y2;
    rect() {}
    rect(ll x1, ll y1, ll x2, ll y2) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
    }
    ll s() {
        return (x2 - x1 + 1) * (y2 - y1 + 1);
    }
    friend rect per(rect a, rect b) {
        pll x = persegm(a.x1, a.x2, b.x1, b.x2);
        pll y = persegm(a.y1, a.y2, b.y1, b.y2);
        return rect(x.f, y.f, x.s, y.s);
    }
    friend istream& operator>>(istream &stream, rect &r) {
        return stream >> r.x1 >> r.y1 >> r.x2 >> r.y2;
    }
};

sum get(ll x1, ll y1, ll x2, ll y2) {
    ll a = (y2 - y1 + 1) * (x2 - x1 + 1);
    sum ans = sum(a / 2, a / 2);
    if (a % 2 != 0) {
        if ((x1 + y1) % 2 == 0) ++ans.w;
        else ++ans.b;
    }
    return ans;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    rect w, b;
    cin >> w >> b;
    sum ans = get(1, 1, n, m);
    ans -= get(w.x1, w.y1, w.x2, w.y2);
    ans -= get(b.x1, b.y1, b.x2, b.y2);
    rect p = per(b, w);
    ans += get(p.x1, p.y1, p.x2, p.y2);
    ans.w += w.s() - p.s();
    ans.b += b.s();
    cout << ans << '\n';
}

signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}