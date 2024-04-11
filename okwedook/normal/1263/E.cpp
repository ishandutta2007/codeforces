#pragma GCC optimize("O3", "unroll-all-loops")
//#pragma GCC target("avx2")
 
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
#include <complex>
 
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
template<class T> inline T sorted(T a) { sort(a); return a; }
 
struct node {
    int mx = 0, mn = 0, bal = 0;
    node() {}
    node(char c) {
        if (c == '(') ++mx, ++bal;
        if (c == ')') --mn, --bal;
    }
};
 
void mergeleft(node &left, node &right) {
	checkmax(left.mx, left.bal + right.mx);
	checkmin(left.mn, left.bal + right.mn);
	left.bal += right.bal;
}
 
struct Tree {
    static const int n = 1 << 20;
    node t[2 * n + 5];
    void upd(int r, char c) {
        r += n;
        t[r] = c;
        for (r >>= 1; r > 0; r >>= 1) {
        	t[r] = t[r + r];
            mergeleft(t[r], t[r + r + 1]);
        }
    }
    node get() { return t[1]; }
} t;
 
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    int curr = 0;
    string s;
    getline(cin, s);
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
        char c = s[i];
        if (c == 'R') ++curr;
        else if (c == 'L') --curr;
        else t.upd(curr, c);
        checkmax(curr, 0);
        auto ans = t.get();
        if (ans.mn < 0 || ans.bal != 0) cout << -1 << ' ';
        else cout << ans.mx << ' ';
    }
    return 0;
}