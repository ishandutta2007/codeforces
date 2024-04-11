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
typedef long double ld;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

signed main() {
    ll n, b;
    cin >> n >> b;
    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;
    vector<ll> cnt1(n), cnt2(n);
    ll curr = 0;
    for (int i = 0; i < n; ++i) 
        curr += arr[i] % 2, cnt1[i] = curr, cnt2[i] = i + 1 - curr;
    if (cnt1[n - 1] != cnt2[n - 1]) {
        cout << 0;
        return 0;
    }
    vector<ll> cuts;
    for (int i = 0; i < n - 1; ++i) 
        if (cnt1[i] == cnt2[i])
            cuts.pb(i);
    if (cuts.size() == 0) {
        cout << 0;
        return 0;
    }
    vector<vector<ll>> dp(cuts.size(), vector<ll>(b + 1, 0));
    if (abs(arr[cuts[0]] - arr[cuts[0] + 1]) <= b) dp[0][abs(arr[cuts[0]] - arr[cuts[0] + 1])] = 1;
    for (int i = 0; i < cuts.size(); ++i)
        for (int j = 0; j < i; ++j) 
            for (int k = 0; k <= b; ++k) {
                ll newind = k + abs(arr[cuts[i]] - arr[cuts[i] + 1]);
                if (newind <= b) 
                    checkmax(dp[i][newind], dp[j][k] + 1);
            }
    ll ans = 0;
    for (auto i : dp)
        for (auto j : i) checkmax(ans, j);
    cout << ans;
    return 0;
}