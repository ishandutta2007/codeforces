#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <deque>
#include <set>
#include <unordered_map>

using namespace std;

int main(){
  int t;
  cin >> t;
  for (int query = 0; query < t; ++query){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> dp(n);
    dp.back() = (s[n - 1] == '0');
    for (int i = n - 2; i >= 0; --i){
      if (s[i] == '0')
        dp[i] = dp[i + 1] + 1;
      else
        dp[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i){
      if (i + 1 < n && s[i] == '1' && s[i + 1] == '0'){
        ans += 2;
        continue;
      }
      int cur = i + dp[i];
      if (cur == n)
        continue;
      int k = (s[cur] - '0');
      int len = dp[i] + 1;
      while (k < len && i + len < n){
       k = k * 2 + (s[i + len] - '0');
       ++len;
      }
      if (k == len)
        ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}