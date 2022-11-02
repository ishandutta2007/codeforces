#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")

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
#include <cassert>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
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
#define sz(a) signed(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()

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
    map<int, int> st;
    for (auto i : s) ++st[i];
    for (auto i : t) ++st[i];
    for (auto &i : st)
    	if (i.s % 2 != 0) {
    		cout << -1;
    		return 0;
    	}
   	map<pair<char, char>, vector<int>> p;
   	for (int i = 0; i < n; ++i) 
   		if (s[i] != t[i]) p[{s[i], t[i]}].pb(i);
   	vector<pii> ans;
   	for (auto &i : p)
   		if (i.f.f != i.f.s) {
   			while (sz(i.s) >= 2) {
   				int a = i.s.back();
   				i.s.popb();
   				int b = i.s.back();
   				i.s.popb();
   				ans.pb({a, b});
   				swap(s[a], t[b]);
   			}
   		}
   	p.clear();
   	for (int i = 0; i < n; ++i) 
   		if (s[i] != t[i]) p[{s[i], t[i]}].pb(i);
   	for (auto &i : p) 
   		if (i.f.f != i.f.s) {
   			vector<int> &v = p[{i.f.s, i.f.f}];
   			if (sz(i.s) && sz(v)) {
   				int a = v.back();
   				v.popb();
   				int b = i.s.back();
   				i.s.popb();
   				ans.pb({a, a});
   				swap(s[a], t[a]);
   				ans.pb({a, b});
   				swap(s[a], t[b]);
   			}
   		}
   	cout << sz(ans) << '\n';
   	for (auto i : ans) cout << i.f + 1 << ' ' << i.s + 1 << '\n';
    return 0;
}