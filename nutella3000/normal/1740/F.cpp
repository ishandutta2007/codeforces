#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e9;
const ll mod = 998244353;
const int N = 2e3 + 3;

vector<int> a;

void add(ll& a, ll b) {
    a += b;
    if (a >= mod) a -= mod;
}

void run() {
    int n; cin >> n;
    {
        map<int, int> cnt;
        for (int i = 0; i < n; ++i) {
            int v; cin >> v; ++cnt[v];
        }
        vector<int> b;
        for (auto [q, w] : cnt)
            b.push_back(w);
        sort(all(b), [](int u, int v) { return u > v; });
        a.push_back(n);
        for (int i = 1; i < b.size(); ++i) {
            a.push_back(a.back() - b[i-1]);
        }
    }

    /*for (int sum = 0; sum <= n; ++sum) {
        for (int cnt = 0; cnt <= n; ++cnt) {
            if (cnt > sum) dp[sum][cnt] = dp[sum][sum];
            else if (cnt > 0) dp[sum][cnt] = dp[sum][cnt-1] + dp[sum - cnt][cnt];
            else {
                dp[sum][cnt] = (sum == 0);
            }
            dp[sum][cnt] %= mod;
        }
    }
    for (auto i : a)
        cout << i << ' ';
    cout << endl;

    ll res = 0;
    int c = 1;
    for (int i = 1; i < a.size(); ++i) {
        // n - c*i <= a[i]
        // c >= (n - a[i]) / i
        chmax(c, (n - a[i]) / i);
    }
    cout << n << ' ' << c << endl;
    res += dp[n][n] - dp[n][c-1];
    cout << (res % mod + mod) % mod << '\n';
    for (int i = 0; i <= n; ++i) {
        cout << i << ' ' << dp[n][i] << '\n';
    }*/

    vector<vector<ll>> dp(n+1, vector<ll>(n+1));
    vector<vector<ll>> ndp(n+1, vector<ll>(n+1));
    ndp[0][0] = 1;

    a.push_back(0);
    for (int k = a.size()-1; k >= 0; --k) {
        for (int c = 0; c <= n; ++c) {
            for (int sum = c*k; sum <= n; ++sum) {
                if (sum - c*k > a[k]) {
                    dp[c][sum] = 0;
                    continue;
                }
                dp[c][sum] = ndp[c][sum];
                if (c && sum - k >= 0)
                    add(dp[c][sum], dp[c-1][sum-k]);
            }
        }
        swap(dp, ndp);
    }
    ll res = 0;
    for (int c = 0; c <= n; ++c)
        res += dp[c][n];
    cout << res % mod << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}