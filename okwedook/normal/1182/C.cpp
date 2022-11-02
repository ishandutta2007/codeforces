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
        swap(a[i], a[rand() % sz(a)]);

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

bool is(char c) {
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

char last(string s) {
    char ans = '0';
    for (auto i : s) 
        if (is(i)) ans = i;
    return ans;
}

int cnt(string s) {
    int ans = 0;
    for (auto i : s)
        ans += is(i);
    return ans;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    map<char, map<int, vector<string>>> st;
    map<int, multiset<string>> a;
    while (n--) {
        string s;
        cin >> s;
        st[last(s)][cnt(s)].pb(s);
        a[cnt(s)].insert(s);
    }
    vector<pair<string, string>> p;
    for (auto &i : st) {
        for (auto &j : i.s) {
            for (int t = 0; t + 2 <= sz(j.s); t += 2) {
                a[cnt(j.s[t])].erase(a[cnt(j.s[t])].lower_bound(j.s[t]));
                a[cnt(j.s[t + 1])].erase(a[cnt(j.s[t + 1])].lower_bound(j.s[t + 1]));
                p.pb({j.s[t], j.s[t + 1]});
            }
        }
    }
    vector<pair<string, string>> b;
    for (auto &i : a) {
        while (sz(i.s) % 2 != 0) {
            i.s.erase(i.s.begin());
        }
        auto it = i.s.begin();
        while (it != i.s.end()) {
            string f = *it;
            ++it;
            string s = *it;
            ++it;
            b.pb({f, s});
        }
    }
    if (sz(b) > sz(p)) {
        cout << sz(p) << '\n';
        for (int i = 0; i < sz(p); ++i) {
            cout << b[i].f << ' ' << p[i].f << '\n';
            cout << b[i].s << ' ' << p[i].s << '\n';
        }
    } else {
        cout << sz(b) + (sz(p) - sz(b)) / 2 << '\n';
        for (int i = 0; i < sz(b); ++i) {
            cout << b[i].f << ' ' << p[i].f << '\n';
            cout << b[i].s << ' ' << p[i].s << '\n';
        }
        for (int i = sz(b); i + 1 < sz(p); i += 2) {
            cout << p[i].f << ' ' << p[i + 1].f << '\n';
            cout << p[i].s << ' ' << p[i + 1].s << '\n';
        }
    }

    return 0;
}