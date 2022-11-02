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

struct cmp {
    bool operator()(const pair<pair<pii, int>, int> &a, const pair<pair<pii, int>, int> &b) {
        if (a.f.f.s != b.f.f.s) return a.f.f.s < b.f.f.s;
        return a < b;
    }
};

signed main() {
    FAST; FIXED; RANDOM;
    int q;
    cin >> q;
    vector<pair<pii, int>> que(q);
    int cnt = 0;
    for (auto &i : que) {
        cin >> i.f;
        i.s = cnt++;
    }
    int n;
    cin >> n;
    vector<pair<pair<pii, int>, int>> man(n);
    cnt = 0;
    for (auto &i : man) {
        cin >> i.f;
        i.s = cnt++;
    }
    sort(que);
    sort(man);
    int ptr = 0;
    set<pair<pair<pii, int>, int>, cmp> st; 
    vector<int> ans(q);
    for (auto i : que) {
        while (ptr < n && man[ptr].f.f.f <= i.f.f) st.insert(man[ptr++]);
        auto it = st.lower_bound({{{-mod, i.f.s}, -mod}, -mod});
        if (it == st.end()) {
            cout << "NO";
            return 0;
        }
        auto a = *it;
        //cout << a.f.f.f << ' ' << a.f.f.s << '\n';
        st.erase(a);
        ans[i.s] = a.s;
        if (--a.f.s > 0) st.insert(a);
    }
    cout << "YES\n";
    for (auto i : ans) cout << i + 1 << ' ';
    return 0;
}