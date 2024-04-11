#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e2+10, MOD = 998244353;

bool dp[N][N][2][2][2]; // evens, odds, A, B, turn (0 = A, 1 = B) = alice wins

void pre() {
    for (int b : {0, 1}) for (int turn : {0, 1})
        dp[0][0][0][b][turn] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) if (i || j) {
            for (int a : {0, 1}) {
                for (int b : {0, 1}) {
                    // turn = 0 (alice)
                    dp[i][j][a][b][0] = 0;
                    if (i) dp[i][j][a][b][0] |= dp[i-1][j][a][b][1];
                    if (j) dp[i][j][a][b][0] |= dp[i][j-1][a^1][b][1];
                    
                    // turn = 1 (bob)
                    dp[i][j][a][b][1] = 1;
                    if (i) dp[i][j][a][b][1] &= dp[i-1][j][a][b][0];
                    if (j) dp[i][j][a][b][1] &= dp[i][j-1][a][b^1][0];
                }
            }
        }
    }
}
void solve() {
    int n; cin >> n;
    int e = 0, o = 0;
    while (n--) {
        int x; cin >> x;
        x = ((x % 2) + 2) % 2;
        if (x) o++;
        else e++;
    }
    cout << (dp[e][o][0][0][0] ? "Alice" : "Bob") << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    pre();
    int T = 1;
    cin >> T;
    while (T--) solve();
}