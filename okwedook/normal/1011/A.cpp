#pragma GCC optimize("O3","unroll-loops")
#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define RANDOM srand(time(NULL))
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

template<class T1, class T2> inline void checkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<class T1, class T2> inline void checkmax(T1 &x, T2 y) { if (x < y) x = y; }
template<class T1> inline void sort(T1 &arr) { sort(arr.begin(), arr.end()); }
template<class T1> inline void rsort(T1 &arr) { sort(arr.rbegin(), arr.rend()); }
template<class T1> inline void reverse(T1 &arr) { reverse(arr.begin(), arr.end()); }
template<class T1> inline void shuffle(T1 &arr) { 
    for (int i = -int(arr.size()); i < int(arr.size()); ++i)
        swap(arr[rand() % arr.size()], arr[rand() % arr.size()]);
}
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

signed main() {
    FAST; FIXED; RANDOM;
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<bool> used(26);
    for (auto &i : s) used[i - 'a'] = true;
    vector<vector<ll>> dp(26, vector<ll>(k, inf));
    for (int i = 0; i < 26; ++i)
        if (used[i]) dp[i][0] = i + 1;
    for (int i = 0; i < 26; ++i)
        if (used[i])
            for (int j = 0; j < i - 1; ++j)
                if (used[j])
                    for (int t = 0; t < k - 1; ++t)
                        checkmin(dp[i][t + 1], dp[j][t] + i + 1);
    ll ans = dp[0][k - 1];
    for (int i = 0; i < 26; ++i)
        checkmin(ans, dp[i][k - 1]);
    if (ans == inf) cout << -1;
    else cout << ans;
    return 0; 
}