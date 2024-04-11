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
#include <queue>

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
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-5
#define mod 1000000007
#define inf 4000000000000000007ll
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
    void operator+=(const vec &a) {
        x += a.x; y += a.y;
    }
    void operator-=(const vec &a) {
        x -= a.x; y -= a.y;
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

struct line {
    ld a, b, c;
    line() {}
    line(vec v, vec u) {
        a = u.y - v.y;
        b = v.x - u.x;
        c = -(v.y * b + v.x * a);
    }
};

vec intersect(line a, line b) {
    return -vec(a.c * b.b - b.c * a.b, a.a * b.c - b.a * a.c) / (a.a * b.b - b.a * a.b);
}

vec intersect(vec a, vec b, vec c, vec d) {
    return intersect(line(a, b), line(c, d));
}

vec center(vec a, vec b, vec c) {
    vec ma = (b + c) / 2;
    vec mb = (a + c) / 2;
    vec oa = (b - c).orth();
    vec ob = (a - c).orth();
    return intersect(ma, ma + oa, mb, mb + ob);
}

const ld PI = 3.141592653589793;

signed main() {
    FAST; FIXED; RANDOM;
    vec a, b, c;
    cin >> a >> b >> c;
    vec mid = center(a, b, c);
    a -= mid;
    b -= mid;
    c -= mid;
    //cout << a.len() << ' ' << b.len() << ' ' << c.len() << '\n';
    ld a1 = atan2(a / b, a * b);
    ld a2 = atan2(b / c, b * c);
    ld a3 = atan2(c / a, c * a);
    for (int i = 3; i < 200; ++i) {
        ld a4 = 2 * PI / i;
        ld c1 = a1 / a4;
        ld c2 = a2 / a4;
        ld c3 = a3 / a4;
        if (abs(c1 - round(c1)) < eps && 
            abs(c2 - round(c2)) < eps && 
            abs(c3 - round(c3)) < eps) {
                vec newa = a;
                newa = newa.rot(2 * PI / i);
                ld al = atan2(a / newa, a * newa);
                cout << i * (a.len2() * sin(al)) / 2 << '\n';
                return 0;
        }
    }
    return 0;
}