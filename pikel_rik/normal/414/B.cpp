#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

ll dp[2001][2001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    ll ans = 0;
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++) dp[1][i] = 1;

    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            for (int num = j; num <= n; num += j) {
                dp[i][num] = (dp[i][num] + dp[i-1][j]) % mod;
            }
        }
    }

    for (int i = 1; i <= n; i++)
        ans = (ans + dp[k][i]) % mod;

    cout << ans << "\n";
    return 0;
}