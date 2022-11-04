#include <bits/stdc++.h>
#define MAXN 5000
#define x first
#define cnt second

using namespace std;

int mouse[MAXN + 1];
pair <int, int> hole[MAXN + 1];

long long dp[2][MAXN + 1];
pair <long long, int> deq[MAXN + 1];

int main() {
  //  fstream cin("A.in");
  //  ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++)
        cin >> mouse[i];
    sort(mouse + 1, mouse + n + 1);
    int sum = 0;
    for(i = 1; i <= m; i++) {
        cin >> hole[i].x >> hole[i].cnt;
        sum += hole[i].cnt;
    }
    if(sum < n) {
        cout << -1;
        return 0;
    }
    sort(hole + 1, hole + m + 1);
    for(i = 1; i <= n; i++)
      if(i <= hole[1].cnt)
        dp[1][i] = dp[1][i - 1] + abs(hole[1].x - mouse[i]);
     else
        dp[1][i] = (1LL << 50);
     for(j = 2; j <= m; j++) {
        for(i = 1; i <= n; i++)
             dp[j & 1][i] = (1LL << 50);
        long long s = 0;
        int b = 0, e = 0;
        deq[0] = {0, 0};
        for(i = 1; i <= n; i++) {
             s += abs(hole[j].x - mouse[i]);
             while(b <= e && deq[e].first + s >= dp[1 - j & 1][i])
                e--;
             deq[++e] = {dp[1 - j & 1][i] - s, i};
             if(i - deq[b].second > hole[j].cnt)
                b++;
             dp[j & 1][i] = deq[b].first + s;
        }
     }
     cout << dp[m & 1][n];
   // cin.close();
   // cout.close();
    return 0;
}