#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <deque>
#include <queue>
#include <random>
#include <sstream>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(15);
#define RANDOM srand(3654765)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>> 
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define eps 1e-9
#define mod 1000000007
#define inf 3000000000000000007ll
#define hashmap unordered_map
#define hashset unordered_set
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < n; ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }

bool intersect(pll a, pll b) {
    return a.s >= b.f;
}

pll merge(pll a, pll b) {
    return pll(b.f, a.s);
}

int get(vector<int> &pref, pll p) {
    if (p.f > p.s) return 0;
    if (p.f == 0) return pref[p.s];
    return pref[p.s] - pref[p.f - 1];
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, q;
    cin >> n >> q;
    vector<pll> arr(q);
    cin >> arr;
    for (auto &i : arr) --i.f, --i.s;
    sort(arr);
    vector<int> cnt(n);
    for (auto i : arr)
        for (int j = i.f; j <= i.s; ++j)
            ++cnt[j];
    vector<int> cntone(n), cnttwo(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) cntone[i] = cnt[i] == 1, cnttwo[i] = cnt[i] == 2, sum += cnt[i] > 0;
    for (int i = 1; i < n; ++i) cntone[i] += cntone[i - 1], cnttwo[i] += cnttwo[i - 1];
    int ans = 0;
    for (int i = 0; i < q; ++i)
        for (int j = i + 1; j < q; ++j) {
            if (intersect(arr[i], arr[j])) {
                if (arr[j].s < arr[i].s) checkmax(ans, sum - get(cntone, arr[i]) - get(cnttwo, arr[j]));
                else {
                    checkmax(ans, sum - get(cntone, arr[i]) - get(cntone, arr[j]) - get(cnttwo, pll(arr[j].f, arr[i].s)));
                }
            } else {
                checkmax(ans, sum - get(cntone, arr[i]) - get(cntone, arr[j]));
            }
        }
    cout << ans;
    return 0;
}