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
#define eps 1e-9
#define mod 999999677
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

struct zet {
    int val;
    zet(ll x = 0) { val = x % mod; if (val < 0) val += mod; }
    zet(ll a, ll b) { *this += a; *this /= b; }

    zet& operator+=(zet const &b) { val += b.val; if (val >= mod) val -= mod; return *this; }
    zet& operator-=(zet const &b) { val -= b.val; if (val < 0) val += mod; return *this; }
    zet& operator*=(zet const &b) { val = (val * (ll)b.val) % mod; return *this; }

    friend zet mypow(zet a, ll n) {
        zet res = 1;
        while (n) { if (n & 1) res *= a; a *= a; n >>= 1; }
        return res;
    }
    friend zet inv(zet a) { return mypow(a, mod - 2); }
    zet& operator/=(zet const& b) { return *this *= inv(b); }
    friend zet operator+(zet a, const zet &b) { return a += b; }
    friend zet operator-(zet a, const zet &b) { return a -= b; }
    friend zet operator-(zet a) { return 0 - a; }
    friend zet operator*(zet a, const zet &b) { return a *= b; }
    friend zet operator/(zet a, const zet &b) { return a /= b; }
    friend istream& operator>>(istream& stream, zet &a) { return stream >> a.val; }
    friend ostream& operator<<(ostream& stream, const zet &a) { return stream << a.val; }
    friend bool operator==(zet const &a, zet const &b) { return a.val == b.val; }
    friend bool operator!=(zet const &a, zet const &b) { return a.val != b.val; }
};

vector<zet> h;

zet get(int r) {
    if (r < 0) return 0;
    return h[r];
}

zet get(int l, int r) {
    return get(r) - get(l - 1) * mypow(zet(10), r - l + 1);
}

string s;

void check(int ind1, int ind2) {
    if (ind1 >= ind2) return;
    if (ind1 < 0 || ind2 >= sz(s)) return;
    if (ind2 == sz(s) - 1) return;
    if (ind1 + 1 != ind2 && s[ind1 + 1] == '0') return;
    if (ind2 < sz(s) - 2 && s[ind2 + 1] == '0') return;
    if (ind1 > 0 && s[0] == '0') return; 
    if (get(0, ind1) + get(ind1 + 1, ind2) == get(ind2 + 1, sz(s) - 1)) {
        cout << s.substr(0, ind1 + 1) << '+';
        cout << s.substr(ind1 + 1, ind2 - ind1) << '=';
        cout << s.substr(ind2 + 1, sz(s) - ind2);
        exit(0);
    }
} 

signed main() {
    FAST; FIXED; RANDOM;
    cin >> s;
    int n = sz(s);
    h = vector<zet>(n);
    zet curr = 0;
    for (int i = 0; i < n; ++i) {
        curr = curr * 10 + (s[i] - '0');
        h[i] = curr;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i - 3; j < i + 3; ++j)
            check(i, n - j);
        for (int j = -3; j < 3; ++j)
            check(i, i + (n - i) / 2 + j);
    }

    return 0;
}