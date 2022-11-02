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
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)]);
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }
 
struct Fenv {
    static const int n = 3e5 + 10;
    ll fenv[n];
    void add(int r, int x) {
        for (; r < n; r |= r + 1) fenv[r] += x;
    }
    ll get(int r) {
        ll ans = 0;
        for (; r >= 0; r = (r & r + 1) - 1)
            ans += fenv[r];
        return ans;
    }
    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
} one, two, other;
 
const int N = 1e7 + 10;
int D[N] = {0};
 
constexpr int add(int j, int i) {
    return j < N ? ++D[j], add(j + i, i) : j;
}
 
constexpr int precalc(int i) {
    return i < N ? add(i, i), precalc(i + 1) : i;
}
 
signed main() {
    FAST; FIXED; RANDOM;  
    precalc(1);  
    int n, m;
    cin >> n >> m;
    set<int> pos;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] == 1) one.add(i, 1);
        if (a[i] == 2) two.add(i, 2);
        if (a[i] > 2) {
            other.add(i, a[i]);
            pos.insert(i);
        }
    }
    while (m--) {
        int mode;
        cin >> mode;
        if (mode == 2) {
            int l, r;
            cin >> l >> r;
            --l, --r;
            cout << one.get(l, r) + two.get(l, r) + other.get(l, r) << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            auto it = pos.lower_bound(l);
            while (it != pos.end() && *it <= r) {
                other.add(*it, -a[*it]);
                a[*it] = D[a[*it]];
                if (a[*it] == 2) {
                    two.add(*it, 2);
                    auto old = it;
                    ++it;
                    pos.erase(old);
                } else other.add(*it, a[*it]), ++it;
            }
        }
    }
    return 0;
}