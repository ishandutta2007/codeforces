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
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

int main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<pair<pair<string, set<char>>, int>> arr;
    for (int i = 0; i < n; ++i) {
    	set<char> st;
    	string s, t;
    	cin >> s >> t;
    	for (auto i : t) st.insert(i);
    	while (sz(s) && st.count(s.back())) s.popb();
    	arr.pb({{s, st}, i});
    }
    sort(arr);
    auto past = arr[0];
    vector<vector<int>> ans(1);
    for (auto i : arr) {
    	if (i.f != past.f) ans.pb(vector<int>());
    	ans[sz(ans) - 1].pb(i.s);
    	past = i;
    }
    cout << sz(ans) << '\n';
    for (auto i : ans) {
    	cout << sz(i) << ' ';
    	for (auto j : i) cout << j + 1 << ' ';
    	cout << '\n';
    }
    return 0;
}