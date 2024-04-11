#include<bits/stdc++.h>

using namespace std;

mt19937 rnd(51);

#define ll long long
#define pb push_back
#define ld long double

const int N = 3e5 + 10;
int now;
int go[30 * N][2];
int dp[30 * N][2][2];

int add(int a, int i) {
    int v = 0, ans = 0;
    vector<int> arr;
    for (int j = 29; j >= 0; j--) {
        if ((1 << j) & (a ^ i)) {
            int u;
            if (go[v][1]) {
                u = go[v][1];
            } else {
                u = go[v][1] = now++;
            }
            if (go[v][0]) {
                ans = max(ans, dp[go[v][0]][(bool)((1 << j) & i)][!(bool)((1 << j) & a)]);
            }
            v = u;
        } else {
            int u;
            if (go[v][0]) {
                u = go[v][0];
            } else {
                u = go[v][0] = now++;
            }
            if (go[v][1]) {
                ans = max(ans, dp[go[v][1]][(bool)((1 << j) & i)][!(bool)((1 << j) & a)]);
            }
            v = u;
        }
        arr.pb(v);
    }
    reverse(arr.begin(), arr.end());
    for (int j = 0; j < 30; j++) {
        dp[arr[j]][(bool)((1 << j) & a)][(bool)((1 << j) & i)] = max(dp[arr[j]][(bool)((1 << j) & a)][(bool)((1 << j) & i)], ans + 1);
    }
    return ans + 1;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < now; i++) {
            go[i][0] = go[i][1] = 0;
            dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = 0;
        }
        now = 1;
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, add(a[i], i));
        }
        cout << ans << endl;
    }
    return 0;
}