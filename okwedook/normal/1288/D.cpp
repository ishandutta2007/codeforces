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
template<class T> inline T sorted(T a) { sort(a); return a; }

int n, m;
vector<vector<int>> a;
pii solve(int x) {
    vector<int> poss(1 << m, -1);
    for (int i = 0; i < n; ++i) {
        int mask = 0;
        for (int j = 0; j < m; ++j)
            if (a[i][j] >= x) mask |= 1 << j;
        poss[mask] = i;
    }
    for (int mask = (1 << m) - 1; mask >= 0; --mask)
        for (int j = 0; j < m && poss[mask] == -1; ++j)
            if (poss[mask | (1 << j)] != -1)
                poss[mask] = poss[mask | (1 << j)];
    for (int mask = 0; mask < (1 << m); ++mask)
        if (poss[mask] != -1 && poss[mask ^ ((1 << m) - 1)] != -1)
            return {poss[mask], poss[mask ^ ((1 << m) - 1)]};
    return {-1, -1};
}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n >> m;
    a = vector<vector<int>>(n, vector<int>(m));
    cin >> a;
    int l = 0, r = 1e9 + 1;
    while (r - l > 1) {
        int mid = r + l >> 1;
        if (solve(mid).f >= 0) l = mid;
        else r = mid;
    }
    auto ans = solve(l);
    cout << ans.f + 1 << ' ' << ans.s + 1 << '\n';
    return 0;
}