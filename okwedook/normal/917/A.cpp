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

bool open(char c) {
    return c == '(' || c == '?';
}

bool close(char c) {
    return c == ')' || c == '?';
}

signed main() {
    FAST; FIXED; RANDOM;
    string s;
    cin >> s;
    int n = sz(s);
    vector<vector<int>> pref(n, vector<int>(n)), suff(n, vector<int>(n));
    string t = s, d = s;
    for (auto &i : t) 
        if (i == '?') i = '(';
    for (auto &i : d) 
        if (i == '?') i = ')';
    for (int i = 0; i < n; ++i) {
        int curr = 0;
        for (int j = i; j < n; ++j) {
            if (curr == -1) pref[i][j] = -1;
            else {
                if (t[j] == '(') ++curr;
                else if (d[j] == ')') --curr;
                pref[i][j] = curr;
            }
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        int curr = 0;
        for (int j = i; j >= 0; --j) {
            if (curr == -1) suff[j][i] = -1;
            else {
                if (d[j] == ')') ++curr;
                else --curr;
                suff[j][i] = curr;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> que;
        int co = 0, ptr = 0;
        for (int j = i; j < n; ++j) {
            if (s[j] == '?') que.pb(j);
            co += s[j] == '(';
            int len = j - i + 1;
            if (len % 2 == 0 && co <= len / 2 && co + sz(que) >= len / 2) {
                while (co + ptr < len / 2) ++ptr;
                while (co + ptr > len / 2) --ptr;
                bool flag = false;
                if (ptr == 0) {
                    flag |= suff[i][j] == 0;
                } else if (ptr == sz(que)) {
                    flag |= pref[i][j] == 0;
                } else {
                    int left = pref[i][que[ptr] - 1];
                    int right = suff[que[ptr]][j];
                    flag |= left >= 0 && left == right;
                }
                ans += flag;
                //if (flag) cout << i << ' ' << j << '\n';
            }
        }
    }
    cout << ans;
    return 0;
}