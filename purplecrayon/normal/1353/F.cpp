#include "bits/stdc++.h"
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 1e2+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
struct my_hash {
    const uint64_t RANDOM = chrono::steady_clock::now().time_since_epoch().count();
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        return splitmix64(x + RANDOM);
    }
};

int n, m;
ll a[MAXN][MAXN], dp[MAXN][MAXN];
void solve(){
    gp_hash_table<ll,int,my_hash> mp;
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j], mp[a[i][j]-i-j]=1;
    ll ans=1e18+10;
    for (auto& it : mp) if (it.first <= a[0][0]) {
        dp[0][0]=a[0][0]-it.first;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (i||j) {
            ll c=it.first+i+j;
            dp[i][j]=1e18+10;
            if (i) dp[i][j] = min(dp[i][j], a[i][j]-c+dp[i-1][j]);
            if (j) dp[i][j] = min(dp[i][j], a[i][j]-c+dp[i][j-1]);
            if (c > a[i][j]) dp[i][j]=1e18+10;
        }
        ans = min(ans, dp[n-1][m-1]);
        // cout << it.first << ' ' << dp[n-1][m-1] << '\n';
    }
    cout << ans << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t=1;
    cin >> t;
    while (t--) solve();
}