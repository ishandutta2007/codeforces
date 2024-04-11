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
#include <complex>
#include <cassert>

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
#define mod 998244353
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

const int N = 1e6 + 10;
const int LOG = log2(N);

int link[LOG][N], dp[LOG][N], mx2[N], h[N];
bool used[N];
graph tree;

void dfs(int v, int d = 0) {
    h[v] = d;
    used[v] = true;
    for (auto i : tree[v]) 
        dfs(i, d + 1);
}

signed main() {
    FAST; FIXED; RANDOM;
    vector<int> a = {0, 2, 3, 13, 29, 30, 31, 64, 65, 66, 67, 92, 93, 94, 95, 256, 257, 258, 259, 284, 285, 286, 287, 320, 321, 322, 323, 348, 349, 350, 351, 1024, 1025, 1026, 1027, 1052, 1053, 1054, 1055, 1088, 1089, 1090, 1091, 1116, 1117, 1118, 1119, 1280, 1281, 1282, 1283, 1308, 1309, 1310, 1311, 1344, 1345, 1346, 1347, 1372, 1373, 1374, 1375, 4096, 4097, 4098, 4099, 4124, 4125, 4126, 4127, 4160, 4161, 4162, 4163, 4188, 4189, 4190, 4191, 4352, 4353, 4354, 4355, 4380, 4381, 4382, 4383, 4416, 4417, 4418, 4419, 4444, 4445, 4446, 4447, 5120, 5121, 5122, 5123, 5148 };
    vector<int> b = {1, 4, 8, 16, 32, 36, 40, 44, 128, 132, 136, 140, 160, 164, 168, 172, 512, 516, 520, 524, 544, 548, 552, 556, 640, 644, 648, 652, 672, 676, 680, 684, 2048, 2052, 2056, 2060, 2080, 2084, 2088, 2092, 2176, 2180, 2184, 2188, 2208, 2212, 2216, 2220, 2560, 2564, 2568, 2572, 2592, 2596, 2600, 2604, 2688, 2692, 2696, 2700, 2720, 2724, 2728, 2732, 8192, 8196, 8200, 8204, 8224, 8228, 8232, 8236, 8320, 8324, 8328, 8332, 8352, 8356, 8360, 8364, 8704, 8708, 8712, 8716, 8736, 8740, 8744, 8748, 8832, 8836, 8840, 8844, 8864, 8868, 8872, 8876, 10240, 10244, 10248, 10252 };
    cout << "? ";
    for (auto i : a) cout << i << ' ';
    cout << endl;
    int a1;
    cin >> a1;
    cout << "? ";
    for (auto i : b) cout << i << ' ';
    cout << endl;
    int a2;
    cin >> a2;
    for (int x = 0; x < (1 << 14); ++x)
        for (auto i : a)
            for (auto j : b)
                if (x == (i ^ a1) && x == (j ^ a2)) {
                    cout << "! " << x << endl;
                    return 0;
                }
    return 0;
}