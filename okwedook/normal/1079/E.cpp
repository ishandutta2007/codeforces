#pragma GCC optimize("O3", "unroll-loops")
 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <ctime>
#include <complex>
#include <random>
#include <bitset>
#include <algorithm>
#include <fstream>
#include <tuple>
#include <sstream>
#include <functional>
using namespace std;
 
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(nullptr))
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); }
template<class T, class U> inline void checkmin(T &x, U y) { if (x > y) x = y; }
template<class T, class U> inline void checkmax(T &x, U y) { if (x < y) x = y; }

signed main() {
    FAST; FIXED; RANDOM;
    int n;
    cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    sort(arr);
    int ans = 0;
    map<int, int> cnt;
    for (auto i : arr) cnt[i]++;
    if (sz(cnt) <= 2) {
        cout << n;
        return 0;
    }
    for (int c = n; c >= 1; --c) {
        for (auto i : cnt)
            if (i.s >= c) {
                int left = i.s - c + 1;
                int sum = c * i.f, currsum = 0;
                vector<vector<bool>> can(c + 1, vector<bool>(sum + 1));
                can[0][0] = true;
                vector<int> brr;
                for (auto j : arr) {
                    if (j == i.f && left > 0) {
                        --left;
                        continue;
                    }
                    brr.pb(j);
                    for (int i = c; i > 0; --i) {
                        for (int k = 0; k + j <= sum; ++k)
                            if (can[i - 1][k])
                                can[i][k + j] = true;
                    }
                }
                if (!can[c][sum]) {
                    checkmax(ans, c);
                }
            }
    }
    cout << ans;
    return 0;
}