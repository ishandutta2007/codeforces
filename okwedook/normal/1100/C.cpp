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
#define ld double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define lowb lower_bound
#define upb upper_bound
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
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

struct vec {
    ld x, y;
    vec() {}
    vec(ld x, ld y) {
        this->x = x;
        this->y = y;
    }
    vec operator+(const vec &a) const {
        return vec(x + a.x, y + a.y);
    }
    vec operator-(const vec &a) const {
        return vec(x - a.x, y - a.y);
    }
    ld len2() const {
        return x * x + y * y;
    }
    ld len() const {
        return sqrt(len2());
    }
    vec norm(ld k) const {
        ld l = len();
        return vec(x * k / l, y * k / l);
    }
    friend istream& operator>>(istream& stream, vec &v) {
        return stream >> v.x >> v.y;
    }
    friend ostream& operator<<(ostream& stream, const vec &v) {
        return stream << v.x << ' ' << v.y;
    }
};

const ld PI = 3.141592653589793;

signed main() {
    FAST; FIXED; RANDOM;
    int n, R;
    cin >> n >> R;
    ld l = 0, r = 1e5;
    vec v1(R, 0), v2(cos(PI * 2 / n) * R, sin(PI * 2 / n) * R);
    while (r - l > eps) {
        ld m = (r + l) / 2;
        if ((v1.norm(R + m) - v2.norm(R + m)).len() < 2 * m) r = m;
        else l = m;
    }
    cout << r;
    return 0;
}