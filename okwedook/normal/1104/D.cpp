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

#define int long long

int a = 1000000000;

bool ask(int x, int y) {
    if (x > 2e9 || y > 2e9) return false;
    cout << "? " << x << ' ' << y << endl;
    char c;
    cin >> c;
    return c == 'x';
}

/*
bool ask(int x, int y) {
    if (x > 2e9 || y > 2e9) return false;
    return x % a >= y % a;
}
*/


void answer(int a) {
    cout << "! " << a << endl; 
}

signed main() {
    FAST; FIXED; RANDOM;
    string s;
    while (cin >> s) {
        if (s == "end") return 0;
        int curr = 1;
        while (curr * 2 < 1e9) {
            if (ask(curr, 2 * curr)) break;
            curr *= 2;
        }
        if (curr == 1) {
            if (!ask(4, 3)) answer(2);
            else answer(1);
            continue;
        }
        int l = curr, r = 2 * curr + 1;
        while (r - l > 1) {
            int m = r + l >> 1;
            if (ask(m, 2 * m)) l = m;
            else r = m;
        }
        answer(l);
    }
    return 0;
}