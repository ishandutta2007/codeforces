#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <bitset>
#include <sstream>
#include <deque>
#include <queue>
#include <random>
#include <complex>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(94385)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define f first
#define s second
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

struct str {
    string s = "";
    int mx = 0;
    int curr = 0;
    void add(char c) {
        s += c;
        if (c == '(') ++curr;
        else --curr;
        checkmax(mx, curr);
    }
    bool can(char c) {
        if (c == '(') return true;
        return curr > 0;
    }
};

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    string s;
    cin >> s;
    str s1, s2;
    for (int i = 0; i < n; ++i) {
        if (s1.can(s[i]) && s2.can(s[i])) {
            if (s1.curr < s2.curr) s1.add(s[i]), cout << 0;
            else s2.add(s[i]), cout << 1;
        } else if (s1.can(s[i])) s1.add(s[i]), cout << 0;
        else if (s2.can(s[i])) s2.add(s[i]), cout << 1;
        else cout << "OHSHIT";
    }
    return 0;
}