#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e2+10, MOD = 1e9+7;

int r, s, p;
double dp[N][N][N];

void solve() {
    cin >> r >> s >> p;
    dp[r][s][p] = 1;
    for (int a = r; a >= 0; a--) {
        for (int b = s; b >= 0; b--) {
            for (int c = p; c >= 0; c--) {
                int sum = a + b + c;
                if (sum < 2) continue;

                auto p = [&](int x, int y) {
                    return ((double) x * y) / (a * b + b * c + a * c);
                };

                if (a >= 1 && b >= 1) {
                    dp[a][b-1][c] += dp[a][b][c] * p(a, b);
                }
                if (a >= 1 && c >= 1) {
                    dp[a-1][b][c] += dp[a][b][c] * p(a, c);
                }
                if (b >= 1 && c >= 1) {
                    dp[a][b][c-1] += dp[a][b][c] * p(b, c);
                }
            }
        }
    }
    double ar = 0, as = 0, ap = 0;
    for (int i = 0; i <= r; i++) ar += dp[i][0][0];
    for (int i = 0; i <= s; i++) as += dp[0][i][0];
    for (int i = 0; i <= p; i++) ap += dp[0][0][i];
    cout << fixed << setprecision(10);
    cout << ar << ' ' << as << ' ' << ap << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}