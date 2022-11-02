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

int len(int a, int b, int c, int d) {
    return max(b, d) - min(a, c);
}

signed main() {
    FAST; FIXED; RANDOM;
    string s;
    cin >> s;
    map<string, vector<int>> ind;
    for (int i = 0; i < sz(s); ++i) {
        string news = "";
        for (int j = i; j < i + 4 && j < sz(s); ++j) {
            news += s[j];
            ind[news].pb(i);
        }
    }
    int q;
    cin >> q;
    map<pair<string, string>, int> counted;
    while (q--) {
        string s1, s2;
        cin >> s1 >> s2;
        if (sz(ind[s1]) > sz(ind[s2])) swap(s1, s2);
        vector<int> &a1 = ind[s1], &a2 = ind[s2];
        if (counted.count({s1, s2})) cout << counted[{s1, s2}];
        else {
            int t = mod;
            for (auto j : a1) {
                int l = -1, r = sz(a2);
                while (r - l > 1) {
                    int mid = r + l >> 1;
                    if (a2[mid] >= j) r = mid;
                    else l = mid;
                }
                if (r < sz(a2)) checkmin(t, len(j, j + sz(s1), a2[r], a2[r] + sz(s2)));
                if (l >= 0) checkmin(t, len(j, j + sz(s1), a2[l], a2[l] + sz(s2)));
            }
            if (t == mod) t = -1;
            counted[{s1, s2}] = t;
            cout << t;
        }
        cout << '\n';
    }
    return 0;
}