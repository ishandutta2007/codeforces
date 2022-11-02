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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    vector<vector<bool>> can(5, vector<bool>(n));
    vector<vector<ll>> dp(5, vector<ll>(n));
    for (int i = 0; i < 5; ++i) {
        can[i][0] = true;
        dp[i][0] = -1;
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i] > arr[i - 1]) {
            for (int j = 0; j < 5; ++j)
                for (int k = j + 1; k < 5; ++k)
                    if (can[j][i - 1]) {
                        can[k][i] = true;
                        dp[k][i] = j;
                    }
        }
        if (arr[i] < arr[i - 1]) {
            for (int j = 0; j < 5; ++j)
                for (int k = j - 1; k >= 0; --k)
                    if (can[j][i - 1]) {
                        can[k][i] = true;
                        dp[k][i] = j;
                    }
        }
        if (arr[i] == arr[i - 1]) {
            for (int j = 0; j < 5; ++j)
                for (int k = 4; k >= 0; --k)
                    if (k != j && can[j][i - 1]) {
                        can[k][i] = true;
                        dp[k][i] = j;
                    }
        }
    }
    int ind = 0;
    for (int i = 0; i < 5; ++i)
        if (can[i][n - 1]) ind = i;
    if (can[ind][n - 1] == false) cout << -1;
    else {
        vector<ll> ans(n);
        for (int i = n - 1; i >= 0; --i)
            ans[i] = ind, ind = dp[ind][i];
        for (auto i : ans) cout << i + 1 << ' ';
    }
    return 0;
}