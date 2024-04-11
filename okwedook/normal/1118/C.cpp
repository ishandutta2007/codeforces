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

void ex() {
    cout << "NO";
    exit(0);
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n;
    cin >> n;
    vector<ll> arr(n * n);
    cin >> arr;
    map<ll, ll> cnt;
    for (auto i : arr) cnt[i]++;
    set<pii> st;
    vector<vector<ll>> ans(n, vector<ll> (n));
    for (auto i : cnt) st.insert({i.s, i.f});
    for (int i = 0; i < n / 2; ++i)
        for (int j = 0; j < n / 2; ++j) {
            pii b = *(--st.end());
            st.erase(b);
            if (b.f < 4) ex();
            ans[i][j] = ans[n - i - 1][j] = ans[i][n - 1 - j] = ans[n - 1 - i][n - 1 - j] = b.s;
            b.f -= 4;
            if (b.f) st.insert(b);
        }
    if (n & 1) {
        for (int i = 0; i < n / 2; ++i) {
                pii b = *(--st.end());
                st.erase(b);
                if (b.f < 2) ex();
                ans[i][n >> 1] = ans[n - i - 1][n >> 1] = b.s;
                b.f -= 2;
                if (b.f) st.insert(b);
        }
        for (int i = 0; i < n / 2; ++i) {
                pii b = *(--st.end());
                st.erase(b);
                if (b.f < 2) ex();
                ans[n >> 1][i] = ans[n >> 1][n - i - 1] = b.s;
                b.f -= 2;
                if (b.f) st.insert(b);
        }
        ans[n >> 1][n >> 1] = st.begin()->s;
    }   
    cout << "YES\n";
    for (auto i : ans) {
        for (auto j : i) cout << j << ' ';
        cout << '\n';
    }
    return 0;
}