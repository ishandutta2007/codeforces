#include <bits/stdc++.h>
#define MAXN 300000

using namespace std;

vector <int> obj[4];

struct Data {
    long long cost;
    int cnt1;
    int cnt2;
}dp[MAXN + 1];

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n, m, w, p;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> w >> p;
        obj[w].push_back(p);
    }
    for(i = 1; i <= 3; i++)
        sort(obj[i].begin(), obj[i].end(), greater <int>());
    dp[0] = {0, 0, 0};
    for(i = 1; i <= m; i++) {
        if(dp[i - 1].cnt1 < obj[1].size()) {
            dp[i].cost = dp[i - 1].cost + obj[1][dp[i - 1].cnt1];
            dp[i].cnt1 = dp[i - 1].cnt1 + 1;
            dp[i].cnt2 = dp[i - 1].cnt2;
        }
        if(i - 2 >= 0 && dp[i - 2].cnt2 < obj[2].size() && dp[i].cost < dp[i - 2].cost + obj[2][dp[i - 2].cnt2]) {
            dp[i].cost = dp[i - 2].cost + obj[2][dp[i - 2].cnt2];
            dp[i].cnt1 = dp[i - 2].cnt1;
            dp[i].cnt2 = dp[i - 2].cnt2 + 1;
        }
    }
    for(i = 1; i <= m; i++)
        dp[i].cost = max(dp[i].cost, dp[i - 1].cost);
    long long ans = 0;
    long long sum = 0;
    for(i = 0; 3 * i <= m && i <= obj[3].size(); i++) {
        if(i - 1 >= 0)
          sum += obj[3][i - 1];
        ans = max(ans, sum + dp[m - 3 * i].cost);
    }
    cout << ans;
   // cin.close();
   // cout.close();
    return 0;
}