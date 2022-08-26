#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

typedef long long ll;

using namespace std;
const int maxN = 1e6 + 100;
const int INFi = 2e9;

int dp[maxN];
int mx[maxN];
int cnt[maxN];
int p[maxN];

void solve() {
    int n;
    cin >> n;
    for (int i = 2; i <= n + 1; ++i) {
        cin >> p[i];
        dp[i] = 1;
        int x = i;
        while (x != 1) {
            int u = p[x];
            if (mx[u] < dp[x]) {
                mx[u] = dp[x];
                cnt[u] = 1;
                if (dp[u] == mx[u]) break;
                dp[u] = mx[u];
                x = u;
                continue;
            }
            if (dp[x] < mx[u]) break;
            if (dp[x] == mx[u]) {
                cnt[u]++;
                if (dp[u] == mx[u] + 1) break;
                dp[u] = mx[u] + 1;
            }
            x = u;
        }
        cout << mx[1] << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}