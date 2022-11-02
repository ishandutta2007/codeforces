#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ull = unsigned long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9;
const ll mod = 998244353;

void run() {
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> rs(n);
    vector<bool> dp(n+1, 0);
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i - a[i] >= 0) rs[i - a[i]].push_back(i+1);
    }
    for (int i = 0; i < n; ++i) {
        if (!dp[i]) continue;
        for (int j : rs[i]) {
            dp[j] = true;
        }
        if (i + a[i] < n) dp[i + a[i] + 1] = true;
    }
    cout << (dp[n] ? "YES" : "NO") << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}