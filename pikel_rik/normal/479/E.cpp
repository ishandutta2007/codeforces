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
const int N = 5e3 + 5;

int n, a, b, k;
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> a >> b >> k;

    for (int i = 1; i <= n; i++)
        dp[i][0] = 0;
    dp[a][0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i][0] += dp[i-1][0];
    }

    for (int c = 0; c < k; c++) {
        for (int i = 1; i <= n; i++) {
            if (a < b) {
                int lb = 1, rb = (i + b - 1) / 2;
                int amt = ((dp[rb][c] - dp[lb - 1][c] - (dp[i][c] - dp[i-1][c])) % mod + mod) % mod;

                dp[i][c+1] = amt;
            }
            else if (a > b) {
                int lb = ((i + b) % 2 == 0 ? (i + b) / 2 + 1 : (i + b + 1) / 2), rb = n;
                int amt = ((dp[rb][c] - dp[lb-1][c] - (dp[i][c] - dp[i-1][c])) % mod + mod) % mod;

                dp[i][c+1] = amt;
            }
        }

        for (int i = 1; i <= n; i++) {
            dp[i][c+1] = (dp[i][c+1] + dp[i-1][c+1]) % mod;
        }
    }

    if (a < b) cout << dp[b-1][k];
    else cout << (dp[n][k] - dp[b][k] + mod) % mod;

    return 0;
}