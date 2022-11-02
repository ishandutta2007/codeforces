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

const int LOG = 18;
const int N = 2e5 + 10;

int link[LOG][N];

signed main() {
    FAST; FIXED; RANDOM;
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> p(n), a(m);
    cin >> p >> a;
    vector<pair<pii, int>> que(q);
    int cnt = 0;
    for (auto &i : que) {
        cin >> i.f;
        --i.f.f, --i.f.s;
        i.s = cnt++;
    } 
    sort(que);
    vector<int> ans(q);
    map<int, int> past;
    for (int i = n - 1; i >= 0; --i) past[p[i]] = p[(i + 1) % n];
    map<int, int> next;
    for (int i = m - 1; i >= 0; --i) {
        if (past.count(a[i]) && next.count(past[a[i]])) link[0][i] = next[past[a[i]]];
        else link[0][i] = -1;
        next[a[i]] = i;
    }
    for (int l = 1; l < LOG; ++l) 
        for (int i = 0; i < m; ++i) 
            link[l][i] = link[l - 1][i] < 0 ? -1 : link[l - 1][link[l - 1][i]];
    vector<pii> arr;
    --n;
    for (int i = 0; i < m; ++i) {
        int c = i;
        for (int l = LOG - 1; l >= 0 && c >= 0; --l) 
            if (n >> l & 1) c = link[l][c];
        if (c >= 0) arr.pb({i, c});
    }
    multiset<int> st;
    for (auto i : arr) st.insert(i.s);
    int ptr = 0;
    for (auto i : que) {
        while (ptr < sz(arr) && arr[ptr].f < i.f.f) st.erase(st.lower_bound(arr[ptr].s)), ++ptr;
        if (sz(st) && *(st.begin()) <= i.f.s) ans[i.s] = 1;
    }
    for (auto i : ans) cout << i;
    return 0;
}