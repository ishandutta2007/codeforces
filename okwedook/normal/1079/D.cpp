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

bool eq(ld a, ld b) {
    return fabs(a - b) < eps;
}

struct vec {
    ld x, y;
    vec() { x = y = 0; }
    vec(ld x, ld y) {
        this->x = x;
        this->y = y;
    }
    ld len2() {
        return x * x + y * y;
    }
    ld len() {
        return sqrt(len2());
    }
    vec orth() {
        return vec(-y, x);
    }
    vec operator+(const vec &a) const {
        return vec(x + a.x, y + a.y);
    }
    vec operator-(const vec &a) const {
        return vec(x - a.x, y - a.y);
    }
    vec operator-() {
        return vec(-x, -y);
    }
    vec operator*(ld k) {
        return vec(x * k, y * k);
    }
    vec operator/(ld k) {
        return vec(x / k, y / k);
    }
    vec norm() {
        ld l = len();
        if (eq(l, 0)) return vec(1, 0);
        return *this / l;
    }
    vec rot(ld sina, ld cosa) {
        return orth() * sina + *this * cosa;
    }
    vec rot(ld alpha) {
        return rot(sin(alpha), cos(alpha));
    }
    bool operator==(const vec &a) const {
        return eq(x, a.x) && eq(y, a.y);
    }
    bool operator<(const vec &a) const {
        if (eq(x, a.x)) return y < a.y;
        return x < a.x;
    }
    ld operator*(const vec &a) const {
        return x * a.x + y * a.y;
    }
    ld operator/(const vec &a) const {
        return x * a.y - y * a.x;
    }
    friend istream& operator>>(istream& stream, vec &a) {
        stream >> a.x >> a.y;
        return stream;
    }
    friend ostream& operator<<(ostream& stream, vec a) {
        stream << a.x << ' ' << a.y;
        return stream;
    }
};

ld manh(vec a, vec b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

ld dist(vec a, vec b) {
    return (a - b).len();
}

ld a, b, c;

ld byx(ld x) {
    return (-a / b) * x - c / b;
}

ld byy(ld y) {
    return (-b / a) * y - c / a;
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> a >> b >> c;
    vec f, t;
    cin >> f >> t;
    if (b == 0 || a == 0) {
        cout << manh(f, t);
        return 0;
    }
    ld ans = manh(f, t);
    vector<vec> A(4);
    A[0] = vec(f.x, byx(f.x));
    A[1] = vec(byy(f.y), f.y);
    A[2] = vec(t.x, byx(t.x));
    A[3] = vec(byy(t.y), t.y);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            checkmin(ans, manh(f, A[i]) + dist(A[i], A[j]) + manh(t, A[j]));
    cout << ans;
    return 0;
}