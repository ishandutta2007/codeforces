#pragma GCC optimize("Ofast", "unroll-loops")

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

bool cmp(const pair<pll, int> &a, const pair<pll, int> &b) {
    return a.f.s < b.f.s;
}

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    sort(a);
    int q;
    cin >> q;
    vector<pair<pll, int>> que(q);
    int cnt = 0;
    for (auto &i : que) {
        cin >> i.f;
        i.f.s -= i.f.f - 1;
        i.s = cnt++;
    }
    sort(all(que), cmp);
    vector<ll> t;
    for (int i = 0; i < n - 1; ++i) t.pb(a[i + 1] - a[i]);
    sort(t);
    ll curr = n, sum = 0;
    int ptr = 0;
    vector<ll> ans(q);
    for (auto &i : que) {
        while (ptr < sz(t) && i.f.s >= t[ptr]) sum += t[ptr], ++ptr, --curr;
        ans[i.s] = i.f.s * curr + sum;
    }
    for (auto i : ans) cout << i << ' ';
    return 0;
}