#pragma GCC optimize("O3", "unroll-all-loops")
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
#include <complex>
 
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
 
vector<int> ans;
 
bool canadd(int x) {
    return sz(ans) == 0 || abs(ans.back() - x) == 1;
}
 
void addback(int x) {
    assert(canadd(x));
    ans.pb(x);
}
 
void clear() {
    ans.clear();
}
 
void addpair(int a, int b) {
    assert(abs(a - b) == 1);
    assert(canadd(a) || canadd(b));
    if (canadd(a)) addback(a), addback(b);
    else addback(b), addback(a);
}
 
mt19937 gen;
 
int rand(int a) {
    return gen() % a;
}
 
int rand(int a, int b) {
    uniform_int_distribution<int> uni(a, b);
    return uni(gen);
}

vector<pii> poss = {{0, 1}, {1, 2}, {2, 3}};
 
void solve(vector<int> a) {
    if (!next_permutation(all(poss))) {
        cout << "NO\n";
        exit(0);
    }
    clear();
    shuffle(all(poss), gen);
    for (auto i : poss) {
        int l = i.f, r = i.s;
        if (rand(0, 1)) swap(l, r);
        while (a[l] > 0 && a[r] > 0 && (canadd(l) || canadd(r))) {
            addpair(l, r);
            --a[l];
            --a[r];
        }
    }
    for (int t = 0; t < 4; ++t)
        for (int i = 0; i < sz(a); ++i)
            if (a[i] && canadd(i)) addback(i), --a[i];
    for (auto i : a)
        if (i != 0) return;
    cout << "YES\n";
    for (auto i : ans) cout << i << ' ';
    exit(0);
}

signed main() {
    FAST; FIXED; RANDOM;
    sort(poss);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    while (true) solve({a, b, c, d});
    return 0;
}