#pragma GCC optimize("Ofast", "unroll-loops")
 
#include <bits/stdc++.h>
using namespace std;
 
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
#define ll long long
#define ld long double
#define ui unsigned int
#define ull unsigned ll
#define pii pair<int, int>
#define pll pair<ll, ll>
#define graph vector<vector<int>>
#define eps 1e-9
#define mod 998244353
#define inf 1000000000000000007ll
#define intinf ((1 << 31) - 1)
#define f first
#define s second
#define checkmin(x, y) if (x > y) x = y
#define checkmax(x, y) if (x < y) x = y
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) int(a.size())
#define shuffle(a) \
    for (int i = -sz(a); i < sz(a); ++i) \
        swap(a[rand() % sz(a)], a[rand() % sz(a)])
 
template<class T> inline void sort(T &a) { sort(all(a)); }
template<class T> inline void rsort(T &a) { sort(rall(a)); }
template<class T> inline void reverse(T &a) { reverse(all(a)); } 

void sum(ll &a, ll b) {
    a += b;
    if (a >= mod) a -= mod; 
}

signed main() {
    FAST; FIXED; RANDOM;
    ll n, k;
    cin >> n >> k;
    vector<vector<vector<ll>>> dp(4, vector<vector<ll>> (n, vector<ll>(k + 5)));
    dp[0][0][1] = 1;
    dp[1][0][2] = 1;
    dp[2][0][2] = 1;
    dp[3][0][1] = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= k; ++j) 
            for (int t = 0; t < 4; ++t)
                for (int l = 0; l < 4; ++l)
                {
                    ll x = 0;
                    if (t == 0) {
                        if (l == 0) x = 0;
                        if (l == 1) x = 1;
                        if (l == 2) x = 1;
                        if (l == 3) x = 1;
                    } else if (t == 1) {
                        if (l == 0) x = 0;
                        if (l == 1) x = 0;
                        if (l == 2) x = 2;
                        if (l == 3) x = 0;
                    } else if (t == 2) {
                        if (l == 0) x = 0;
                        if (l == 1) x = 2;
                        if (l == 2) x = 0;
                        if (l == 3) x = 0;
                    } else if (t == 3) {
                        if (l == 0) x = 1;
                        if (l == 1) x = 1;
                        if (l == 2) x = 1;
                        if (l == 3) x = 0;
                    }
                    sum(dp[l][i][j + x], dp[t][i - 1][j]);
                }
    }
    ll ans = 0;
    for (int i = 0; i < 4; ++i)
        sum(ans, dp[i][n - 1][k]);
    cout << ans;
    return 0;
}