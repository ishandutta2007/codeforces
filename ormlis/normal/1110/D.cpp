#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;

const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e6 + 1;
const int md = 998244353;
const int md2 = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

ll dp[maxN][5][5];
int a[maxN];

void solve() {
    int n, m; cin >> n >> m;
    range(i, n) {
        int k; cin >> k;
        a[k]++;
    }
    range(e, maxN) range(i, 5) range(j, 5) dp[e][i][j] = -INF;
    dp[0][0][0] = 0;
    for(int i = 1; i <= m; ++i) {
        int add = max(0, a[i] - 6) / 3;
        int ost = a[i] - add * 3;
        range(prev1, 5) {
            range(prev2, 5) {
                range(z, ost / 3 + 1) {
                    int ost2 = ost - z * 3;
                    range(w, min(ost2, min(prev1, prev2)) + 1) {
                        dp[i][prev2 - w][min(ost2 - w, 4)] = max(dp[i][prev2 - w][min(ost2 - w, 4)], dp[i-1][prev1][prev2] + add + z + w);
                    }
                }
            }
        }
    }
    ll ans = 0;
    range(i, 5) range(j, 5) ans = max(ans, dp[m][i][j]);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests=1;
    range(_, tests) {
        solve();
    }
    return 0;
}