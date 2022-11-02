#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second

#include <bits/stdc++.h>
using namespace std;

template<typename T1, typename T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<typename T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < arr.size(); ++i) {
        int f = ((rand() << 16) + rand()) % arr.size(), s = ((rand() << 16) + rand()) % arr.size();
        swap(arr[f], arr[s]);
    }
}
template<typename T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

signed main() {
    FAST; FIXED;
    vector<string> arr(2);
    for (auto &i : arr) cin >> i;
    int n = arr[0].size();
    vector<vector<ll>> dp(n, vector<ll>(4));
    for (int i = 1; i < n; ++i) {
        dp[i] = dp[i - 1];
        if (arr[0][i] == '0' && arr[1][i] == '0') {
            ll past = 0;
            if (i > 1)
                for (auto j : dp[i - 2]) checkmax(past, j);
            if (arr[0][i - 1] == '0' && arr[1][i - 1] == '0') {
                checkmax(dp[i][1], past + 1);
                checkmax(dp[i][2], past + 1);
            }
            if (arr[0][i - 1] == '0') {
                checkmax(dp[i][0], past + 1);
                checkmax(dp[i][0], dp[i - 1][2] + 1);
            }
            if (arr[1][i - 1] == '0') {
                checkmax(dp[i][0], past + 1); 
                checkmax(dp[i][0], dp[i - 1][3] + 1);
            }
        }
        else if (arr[0][i] == '0') {
            ll past = 0;
            if (i > 1)
                for (auto j : dp[i - 2]) checkmax(past, j);
            if (arr[0][i - 1] == '0' && arr[1][i - 1] == '0') {
                checkmax(dp[i][1], past + 1);
            }
        }
        else if (arr[1][i] == '0') {
            ll past = 0;
            if (i > 1)
                for (auto j : dp[i - 2]) checkmax(past, j);
            if (arr[0][i - 1] == '0' && arr[1][i - 1] == '0') {
                checkmax(dp[i][2], past + 1);
            }
        }
    }
    ll ans = 0;
    for (auto i : dp[n - 1]) checkmax(ans, i);
    cout << ans;
    return 0;
}