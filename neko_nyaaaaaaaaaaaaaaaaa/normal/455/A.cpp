#include <bits/stdc++.h>
using namespace std;

int main() {
      int n;
      cin >> n;
      vector<long long> count(100001, 0);
      while (cin >> n) count[n]++;
      vector<long long> dp(100001, 0);
      dp[0] = count[0];
      dp[1] = max(count[0], count[1]);
      for (int i = 2; i < 100001; i++) {
            dp[i] = max(dp[i-1], dp[i-2] + count[i]*i);
      }
      cout << dp[100000];
}