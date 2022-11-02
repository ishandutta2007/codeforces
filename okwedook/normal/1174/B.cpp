#pragma GCC optimize("O3", "unroll-loops")
  
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <queue>
#include <bitset>
#include <random>
  
using namespace std;
  
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(392403285);
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define f first
#define s second
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define pb push_back
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
  
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
  
signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    set<pii> st[2];
    for (int i = 0; i < n; ++i)
        st[a[i] % 2].insert({a[i], i});
    if (sz(st[0]) == 0 || sz(st[1]) == 0) {
        for (auto i : a) cout << i << ' ';
        return 0;
    }
    sort(a);
    for (auto i : a) cout << i << ' ';
    return 0;
    for (int i = 0; i < n; ++i) {
        if (sz(st[(a[i] + 1) % 2]) > 0) {
            if (st[(a[i] + 1) % 2].begin()->f < a[i]) {
                pii f = {a[i], i};
                pii s = *st[(a[i] + 1) % 2].begin();
                st[a[i] % 2].erase(f);
                st[(a[i] + 1) % 2].erase(s);
                swap(a[f.s], a[s.s]);
                f.s = s.s;
                st[a[i] % 2].insert(f);
            }
        }
    }
    for (auto i : a) cout << i << ' ';
    return 0;   
}