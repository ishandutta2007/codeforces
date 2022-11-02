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
 
void answer(int x) {
    cout << "! " << x << endl;
    exit(0);
}
 
pii ask(vector<int> ind) {
    cout << "? ";
    for (auto i : ind) cout << i + 1 << ' ';
    cout << endl;
    int x, val;
    cin >> x >> val;
    return {x - 1, val};
}
 
pii ask(set<int> ind) {
    cout << "? ";
    for (auto i : ind) cout << i + 1 << ' ';
    cout << endl;
    int x, val;
    cin >> x >> val;
    return {x - 1, val};
}
 
void erase(vector<int> &a, int val) {
    for (int i = 0; i < sz(a); ++i)
        if (a[i] == val) {
            a.erase(a.begin() + i);
            return;
        }
}
 
void generate(const vector<int> &val, vector<int> &minus, vector<int> &notminus) {
    minus.clear();
    notminus.clear();
    for (int i = 0; i < sz(val); ++i)
        if (val[i] == -1) minus.pb(i);
        else notminus.pb(i);
    sort(all(notminus), [&](int i, int j){
        return val[i] < val[j];
    });
}
 
signed main() {
    FAST; FIXED; RANDOM;
    int n, k;
    cin >> n >> k;
    if (k == 1) answer(1);
    vector<int> val(n, -1);
    for (int i = 0; i <= n - k; ++i) {
        int left = k;
        vector<int> ind;
        for (int j = 0; j < n && left > 0; ++j)
            if (val[j] == -1) --left, ind.pb(j);
        assert(left == 0);
        auto ans = ask(ind);
        val[ans.f] = ans.s;
    }
    vector<int> minus, notminus;
    generate(val, minus, notminus);
    if (sz(notminus) >= k) {
        vector<int> ind;
        for (int i = 0; i < k; ++i)
            ind.pb(notminus[i]);
        auto ans = ask(ind);
        for (int i = 0; i < k; ++i)
            if (notminus[i] == ans.f) answer(i + 1);
        assert(false);
    }
    assert(sz(minus) == k - 1);
    int ans = 0;
    for (int i = 0; i < sz(minus); ++i) {
        auto ind = minus;
        erase(ind, minus[i]);
        ind.pb(notminus[0]);
        ind.pb(notminus[1]);
        if (ask(ind).f != notminus[0]) ++ans;
    }
    answer(ans + 1);
    return 0;
}