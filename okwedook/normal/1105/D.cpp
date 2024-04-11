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
int n, m, p;
vector<vector<char>> arr;
map<char, set<pii>> st;
vector<vector<int>> dp;

void add(pii pos, char c, int d) {
    if (pos.f < 0 || pos.s < 0 || pos.f >= n || pos.s >= m || arr[pos.f][pos.s] != '.') return;
    st[c].insert(pos);
    arr[pos.f][pos.s] = c;
    dp[pos.f][pos.s] = d;
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n >> m >> p;
    map<char, int> s;
    for (int c = '1'; c <= '0' + p; ++c) {
        int x;
        cin >> x;
        s[c] = x;
    }
    arr = vector<vector<char>> (n, vector<char>(m));
    dp = vector<vector<int>> (n, vector<int>(m, mod));
    cin >> arr;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (arr[i][j] >= '0' && arr[i][j] <= '9') {
                st[arr[i][j]].insert({i, j});
                dp[i][j] = 0;
            }
    for (int step = 0; step < n * m; ++step) {
        for (int c = '1'; c <= '0' + p; ++c) {
            for (int i = 0; i < s[c] && sz(st[c]) > 0; ++i) {
                set<pii> was = st[c];
                st[c].clear();
                for (auto i : was) {
                    add({i.f, i.s + 1}, c, dp[i.f][i.s]);
                    add({i.f, i.s - 1}, c, dp[i.f][i.s]);
                    add({i.f + 1, i.s}, c, dp[i.f][i.s]);
                    add({i.f - 1, i.s}, c, dp[i.f][i.s]);
                }
            }
        }
    }
    map<char, int> ans;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            ans[arr[i][j]]++;
    for (char c = '1'; c <= '0' + p; ++c) cout << ans[c] << ' ';
    return 0;
}