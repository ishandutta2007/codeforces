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

const int N = 2001;
char a[N][N], check[N][N];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            check[i][j] = '.';
        }
    vector<int> mnx(26, m + 1), mxx(26, -1), mny(26, n + 1), mxy(26, -1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] >= 'a' && a[i][j] <= 'z') {
                checkmin(mnx[a[i][j] - 'a'], j);
                checkmax(mxx[a[i][j] - 'a'], j);
                checkmin(mny[a[i][j] - 'a'], i);
                checkmax(mxy[a[i][j] - 'a'], i);
            } 
    for (int i = 0; i < 26; ++i) {
        if (mxx[i] >= 0 && mxx[i] != mnx[i] && mxy[i] != mny[i]) {
            cout << "NO\n";
            return;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (mxx[i] == mnx[i]) {
            int x = mnx[i];
            char c = 'a' + i;
            for (int y = mny[i]; y <= mxy[i]; ++y)
                check[y][x] = c;
        } else {
            int y = mny[i];
            char c = 'a' + i;
            for (int x = mnx[i]; x <= mxx[i]; ++x)
                check[y][x] = c;
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (a[i][j] != check[i][j]) {
                cout << "NO\n";
                return;
            }
    cout << "YES\n";
    int pnx = -1, pny = -1, pxx = m + 1, pxy = n + 1;
    int ind = -1;
    for (int i = 25; i >= 0; --i) {
        if (mxx[i] != -1) {
            pnx = mnx[i];
            pxx = mxx[i];
            pny = mny[i];
            pxy = mxy[i];
            ind = i;
            break;
        }
    }
    for (int i = ind - 1; i >= 0; --i)
        if (mxx[i] == -1) {
            mnx[i] = pnx;
            mxx[i] = pxx;
            mny[i] = pny;
            mxy[i] = pxy;
        }
    int ans = 0;
    for (int i = 0; i < 26; ++i)
        ans += mxx[i] != -1;
    cout << ans << '\n';
    for (int i = 0; i < 26; ++i) 
        if (mxx[i] != -1) {
            cout << mny[i] + 1 << ' ' << mnx[i] + 1 << ' ' << mxy[i] + 1 << ' ' << mxx[i] + 1 << '\n';
        }
}


signed main() {
    FAST; FIXED; RANDOM;
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}