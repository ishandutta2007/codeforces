#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
using lint = long long;
int memo[105][105][105];
int dp(int a, int b, int c) {
    if (memo[a][b][c] != -1) return memo[a][b][c];
    int res = 0;
    if (a >= 1 && b >= 2) {
        res = max(res, 3 + dp(a - 1, b - 2, c));
    }
    if (b >= 1 && c >= 2) {
        res = max(res, 3 + dp(a, b - 1, c - 2));
    }
    return memo[a][b][c] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(memo, -1, sizeof(memo));
    int t; cin >> t; while (t--) {
        int a, b, c; cin >> a >> b >> c;
        cout << dp(a, b, c) << "\n";
    }


}