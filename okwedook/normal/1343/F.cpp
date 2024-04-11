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
#include <complex>
#include <random>
#include <cassert>
#include <chrono>

using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(12)
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

#ifdef DEBUG
    mt19937 gen(857204);
#else
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

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

namespace debug {
    #ifdef DEBUG
        template<class T> T to_dbg(T x) { return x; }
        template<class T, class U> string to_dbg(pair<T, U> p) {
            stringstream ss;
            ss << '{' << p.f << ',' << p.s << '}';
            return ss.str();
        }
        string to_dbg(string s) { return "\"" + s + "\""; }
        template<class T> string to_dbg(vector<T> a) {
            stringstream ss;
            ss << '{';
            if (sz(a)) ss << to_dbg(a[0]);
            for (int i = 1; i < sz(a); ++i)
                ss << "," << to_dbg(a[i]);
            ss << '}';
            return ss.str();
        }
        template<class T>
        void dbgout(T x) { cout << to_dbg(x) << endl; }
        template<class T, class... U>
        void dbgout(T t, U... u) {
            cout << to_dbg(t) << ", ";
            dbgout(u...);
        }
        #define dbg(...) cout << "[" << #__VA_ARGS__ << "] = ", dbgout(__VA_ARGS__);
    #else
        #define dbg(...) 0
    #endif
}; using namespace debug;

vector<int> tr(vector<vector<int>> s, int lst, int fst = -1) {
    int n = sz(s) + 1;
    map<int, int> cnt;
    for (auto i : s)
        for (auto j : i)
            cnt[j]++;
    vector<int> ans(n);
    for (int i = n - 1; i > 0; --i) {
        for (auto j : cnt)
            if (j.s == 1 && j.f != fst && (i < n - 1 || j.f == lst)) {
                ans[i] = j.f;
                for (int t = 0; t < sz(s); ++t)
                        for (auto x : s[t])
                            if (x == j.f) {
                                for (auto x : s[t])
                                    --cnt[x];
                                s.erase(s.begin() + t);
                                goto go;
                            }
                go: break;
            }
    }
    ans[0] = n * (n + 1) / 2;
    for (int i = 1; i < n; ++i) ans[0] -= ans[i];
    return ans;
}

bool check(vector<vector<int>> s, vector<int> ans) {
    set<vector<int>> st(all(s));
    for (int i = 1; i < sz(ans); ++i) {
        vector<int> x;
        bool flag = false;
        for (int j = i; j >= 0; --j) {
            x.insert(lower_bound(all(x), ans[j]), ans[j]);
            if (st.count(x)) {
                st.erase(x);
                flag = true;
                break;
            }
        }
        if (!flag) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> s(n - 1);
    map<int, int> cnt;
    for (auto &i : s) {
        int k;
        cin >> k;
        i.resize(k);
        cin >> i;
        for (auto j : i) ++cnt[j];
    }
    vector<int> poss;
    for (auto i : cnt)
        if (i.s == 1)
            poss.pb(i.f); 
    //dbg(poss);
    for (auto lst : poss) {
        for (int fst = 1; fst <= n; ++fst) {
            auto ans = tr(s, lst, fst);
            //dbg(fst, lst, ans);
            if (check(s, ans)) {
                for (auto i : ans) cout << i << ' ';
                cout << '\n';
                return;
            }
        }
    }
}

signed main() {
    FAST; FIXED;
    int t;
    cin >> t;
    while (t--) solve();
    #ifdef DEBUG
        cerr << "Runtime is: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
    #endif
    return 0;
}