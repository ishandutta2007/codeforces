#pragma GCC optimize("O3", "unroll-loops")

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <cmath>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>

using namespace std;

#define FIXED cout << fixed << setprecision(15)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RANDOM srand(85453532)
#define ll long long
#define ld long double
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define pb push_back
#define popb pop_back
#define pf push_front
#define popf pop_front
#define hashmap unordered_map
#define hashset unordered_set
#define sz(a) int(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define eps 1e-9
#define mod 1000000007
#define inf 4000000000000000007ll
#define f first
#define s second
#define shuffle(a) \
    for (int i = 0; i < sz(a); ++i) \
        swap(a[i], a[rand() % sz(a)])

template<class T, class U> inline void checkmin(T &x, U y) { if (y < x) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (y > x) x = y; }
template<class T, class U> inline bool ifmin(T &x, U y) { 
    if (y < x) return x = y, true;
    return false; 
}
template<class T, class U> inline bool ifmax(T &x, U y) { 
    if (y > x) return x = y, true;
    return false; 
}
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T> inline istream& operator>>(istream &stream, vector<T> &a) { 
    for (auto &i : a) stream >> i;
    return stream;
}

int n, m;
graph G1, G2;
vector<pii> mid;
const int half = 20;
int cntmask = 1 << half;
vector<int> popc(cntmask);
bool used[half];

bool check1(int mask) {
    int n = sz(G1);
    for (int i = n; i < half; ++i) 
        if (mask >> i & 1) return false;
    for (int i = 0; i < n; ++i)
        used[i] = mask >> i & 1;
    for (int i = 0; i < n; ++i)
        if (used[i])
            for (auto j : G1[i])
                if (used[j]) return false;
    return true;
}

bool check2(int mask) {
    int n = sz(G2);
    for (int i = n; i < half; ++i) 
        if (mask >> i & 1) return false;
    for (int i = 0; i < n; ++i)
        used[i] = mask >> i & 1;
    for (int i = 0; i < n; ++i)
        if (used[i])
            for (auto j : G2[i])
                if (used[j]) return false;
    return true;

}

signed main() {
    FAST; FIXED; RANDOM;
    cin >> n >> m;
    set<string> st;
    set<string> used;
    set<pair<string, string>> link;
    while (n--) {
        int mode;
        cin >> mode;
        if (mode == 1) {
            for (auto i : st)
                for (auto j : st)
                    if (i < j) link.insert({i, j});
            st.clear();
        } else {
            string s;
            cin >> s;
            st.insert(s);
            used.insert(s);
        }
    }
    for (int i = 0; i < sz(popc); ++i)
        popc[i] = __builtin_popcount(i);
    for (auto i : st)
        for (auto j : st)
            if (i < j) link.insert({i, j});
    st.clear();
    map<string, int> ind;
    int curr = 0;
    for (auto &i : used) ind[i] = curr++;
    G1.resize(min(m, half));
    G2.resize(max(m - half, 0));
    for (auto i : link) {
        int a = ind[i.f];
        int b = ind[i.s];
        if (a > b) swap(a, b);
        if (a < half && b < half) G1[a].pb(b), G1[b].pb(a);
        else if (a >= half && b >= half) {
            a -= half;
            b -= half;
            G2[a].pb(b), G2[b].pb(a);
        }
        else mid.pb({a, b});
    }
    vector<int> mask(cntmask);
    for (int i = 0; i < sz(mask); ++i)
        mask[i] = i;
    sort(all(mask), [&] (const int &a, const int &b) {
        return popc[a] < popc[b];
    });
    vector<int> ans1(cntmask), ans2(cntmask);
    for (int i = 0; i < (cntmask); ++i) {
        bool c = check1(mask[i]);
        if (c) ans1[mask[i]] = popc[mask[i]];
        else {
            for (int j = 0; j < half; ++j)
                if (mask[i] >> j & 1) checkmax(ans1[mask[i]], ans1[mask[i] ^ (1 << j)]);
        }
        c = check2(mask[i]);
        if (c) ans2[mask[i]] = popc[mask[i]];
        else {
            for (int j = 0; j < half; ++j)
                if (mask[i] >> j & 1) checkmax(ans2[mask[i]], ans2[mask[i] ^ (1 << j)]);
        }
    }
    int allone = (cntmask) - 1;
    int ans = 0;
    for (int i = 0; i < (cntmask); ++i) {
        int checkmask = (cntmask) - 1;
        for (auto j : mid) 
            if (mask[i] >> j.f & 1)
                checkmask &= allone ^ (1 << (j.s - half));
        checkmax(ans, ans1[mask[i]] + ans2[checkmask]);
    }
    cout << ans;
    return 0;
}