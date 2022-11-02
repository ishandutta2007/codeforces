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

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    map<char, set<int>> ss, st;
    for (int i = 0; i < n; ++i) ss[s[i]].insert(i), st[t[i]].insert(i);
    vector<pii> answer;
    for (int i = 0; i < n; ++i) {
        if (s[i] != '?' && ss[s[i]].count(i)) {
            if (sz(st[s[i]])) {
                answer.pb({i, *st[s[i]].begin()});
                ss[s[i]].erase(answer.back().f);
                st[s[i]].erase(answer.back().s);
            } else if (sz(st['?'])) {
                answer.pb({i, *st['?'].begin()});
                ss[s[i]].erase(answer.back().f);
                st['?'].erase(answer.back().s);
            }
        }
        if (t[i] != '?' && st[t[i]].count(i)) {
            if (sz(ss[t[i]])) {
                answer.pb({*ss[t[i]].begin(), i});
                ss[t[i]].erase(answer.back().f);
                st[t[i]].erase(answer.back().s);
            } else if (sz(ss['?'])) {
                answer.pb({*ss['?'].begin(), i});
                ss['?'].erase(answer.back().f);
                st[t[i]].erase(answer.back().s);
            }
        }
    }
    while (sz(st['?']) && sz(ss['?'])) {
        answer.pb({*ss['?'].begin(), *st['?'].begin()});
        ss['?'].erase(answer.back().f);
        st['?'].erase(answer.back().s);
    }
    cout << sz(answer) << '\n';
    for (auto i : answer) cout << i.f + 1 << ' ' << i.s + 1 << '\n';
    return 0;
}