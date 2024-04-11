#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>

template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int mod = 1e9 + 7;

void run() {
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> dp(n+1);

    auto func = [&](int r) {
        dp[r] = -inf;
        vector<int> cnt(n+1);
        int mx = 0;
        for (int l = r-1; l >= -1; --l) {
            if ((l == -1 || a[l] == a[r]) && (r - l - 1) >= 2*mx && (r - l & 1)) {
                chmax(dp[r], (l == -1 ? 0 : dp[l]) + 1);
            }
            if (l != -1) {
                ++cnt[a[l]];
                chmax(mx, cnt[a[l]]);
            }
        }
    };

    for (int r = 0; r < n; ++r) {
        func(r);
    }

    int res = 0;
    for (int i = 1; i <= n; ++i) {
        a[n] = i;
        func(n);
        chmax(res, dp[n]);
    }
    cout << res-1 << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}