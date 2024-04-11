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

signed main() {
    int n;
    cin >> n;
    vector<pii> a(4 * n + 1);
    cin >> a;
    for (int i = 0; i < sz(a); ++i) {
        vector<pii> b;
        for (int j = 0; j < sz(a); ++j)
            if (i != j) {
                b.pb(a[j]);
            }
        int mxx = b[0].f, mnx = b[0].f, mxy = b[0].s, mny = b[0].s;
        for (auto i : b) {
            checkmax(mxx, i.f);
            checkmin(mnx, i.f);
            checkmax(mxy, i.s);
            checkmin(mny, i.s);
        }
        if (mxx - mnx == mxy - mny) {
            bool flag = true;
            for (auto i : b) {
                if (i.s == mxy || i.s == mny) {
                    if (!(mnx <= i.f && i.f <= mxx))
                        flag = false;
                } else if (i.f == mxx || i.f == mnx) {
                    if (!(mny <= i.s && i.s <= mxy))
                        flag = false;
                } else flag = false;
            }
            if (flag) {
                cout << a[i].f << ' ' << a[i].s << '\n';
                return 0;
            }
        }
    }
    return 0;
}