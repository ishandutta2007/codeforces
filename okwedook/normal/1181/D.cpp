#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <random>
 
using namespace std;
 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FIXED cout << fixed << setprecision(12);
#define RANDOM srand(235345)
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
#define f first
#define s second
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])
 
template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { if (y < x) return x = y, true; return false; }
template<class T, class U> inline bool ifmax(T &x, U y) { if (y > x) return x = y, true; return false; }
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline istream& operator>>(istream& str, pair<T, U> &p) { return str >> p.f >> p.s; }
template<class T> inline istream& operator>>(istream& str, vector<T> &a) { for (auto &i : a) str >> i; return str; }

struct Fenv {
    static const int n = 5e5 + 10;
    static const int L = log2(n);
    int fenv[n];
    void add(int r, int x) {
        for (; r < n; r |= r + 1)
            fenv[r] += x;
    }
    int kth(int k) {
        ++k;
        int ans = -1;
        for (int l = L; l >= 0; --l) {
            int next = ans + (1 << l);
            if (next < n && fenv[next] < k) {
                k -= fenv[next];
                ans = next;
            }
        }
        return ans + 1;
    }
} fenv;

signed main() {
    FAST; FIXED; RANDOM;
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n);
    cin >> a;
    vector<pair<ll, int>> was(m);
    for (auto &i : a) was[i - 1].f++;
    for (int i = 0; i < m; ++i) was[i].s = i;
    sort(was);
    was.pb({inf / m, m});
    vector<pair<ll, int>> query(q);
    int cnt = 0;
    for (auto &i : query) {
        cin >> i.f;
        i.f -= n + 1;
        i.s = cnt++;
    }
    sort(query);
    int ptr = 0;
    vector<int> ans(q);
    ll add = 0;
    for (int i = 0; i < m; ) {
        int j = i;
        for (; j < m && was[j].f == was[i].f; ++j) 
            fenv.add(was[j].s, 1);
        ll past = add;
        add += (was[j].f - was[i].f) * j;
        while (ptr < q && query[ptr].f < add) {
            ans[query[ptr].s] = fenv.kth((query[ptr].f - past) % j);
            ++ptr;
        }
        i = j;
    }
    for (auto i : ans) cout << i + 1 << '\n';
    return 0;
}