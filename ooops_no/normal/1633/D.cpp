#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 1010, INF = 1e18;

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector<int> dp(N + 1, INF);
    dp[1] = 0;
    for (int i = 1; i < N; i++) {
        for (int x = 1; i / x > 0; x++) {
            if (i + i / x < N) {
                dp[i + i / x] = min(dp[i + i / x], dp[i] + 1);
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> b(n), c(n);
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> c[i];
        }
        vector<int> mx(min(n * 12 + 1, k + 1), -INF);
        int m = mx.size();
        mx[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = m - dp[b[i]] - 1; j >= 0; j--) {
                mx[j + dp[b[i]]] = max(mx[j + dp[b[i]]], mx[j] + c[i]);
            }
        }
        cout << *max_element(mx.begin(), mx.end()) << endl;
    }
    return 0;
}