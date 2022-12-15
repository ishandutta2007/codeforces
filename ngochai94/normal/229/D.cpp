#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

int n, lis[5555], dp[5555][5555], dps[5555][5555], pre[5555];

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    FOR (i, 1, n) {
        cin >> lis[i];
        pre[i] = pre[i - 1] + lis[i];
    }
    reset(dp, -11);
    reset(dps, -11);
    dp[0][0] = dps[0][0] = 0;
    FOR (i, 1, n) FORD (j, i, 1) {
        if (pre[i] - pre[j - 1] < lis[j - 1]) {
            if (j != i) dps[i][j] = dps[i][j + 1];
            continue;
        }
        int low = 0;
        int high = j - 2;
        while (low < high) {
            int chs = (low + high) / 2;
            if (pre[i] - pre[j - 1] >= pre[j - 1] - pre[chs]) high = chs;
            else low = chs + 1;
        }
        // if (i == 3 && j == 3) BUG(high);
        if (dps[j - 1][high + 1] >= 0) dp[i][j] = dps[j - 1][high + 1] + 1;
        dps[i][j] = max(dp[i][j], dps[i][j + 1]);
        // cout << i << ' ' << j << ' ' << dp[i][j] << endl;
    }
    // BUG(dps[0][0]);
    cout << n - dps[n][1];
}