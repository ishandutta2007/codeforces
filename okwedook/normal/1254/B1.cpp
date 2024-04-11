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

vector<ll> ind, sumind;

void makepref() {
    for (int i = 1; i < sz(sumind); ++i)
        sumind[i] += sumind[i - 1];
}

ll getsum(int r) {
    if (r < 0) return 0;
    if (r >= sz(sumind)) return sumind.back();
    return sumind[r];
}

ll getsum(int l, int r) {
    return getsum(r) - getsum(l - 1);
}

ll getcnt(int l, int r) {
    return r - l + 1;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    int sum = 0;
    for (auto i : a) sum += i;
    if (sum == 1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; ++i)
        if (a[i] == 1) ind.pb(i), sumind.pb(i);
    makepref();
    ll ans = n * (ll)n;
    for (int d = 2; d <= sum; ++d)
        if (sum % d == 0) {
            ll check = 0;
            for (int i = 0; i < sum; i += d) {
                check += getcnt(i, i + d / 2) * ind[i + d / 2] - getsum(i, i + d / 2);
                check += getsum(i + d / 2, i + d - 1) - getcnt(i + d / 2, i + d - 1) * ind[i + d / 2];
            }
            checkmin(ans, check);
        }
    cout << ans;
    return 0;
}