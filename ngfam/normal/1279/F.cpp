#include <bits/stdc++.h>
#define int long long
 
using namespace std;
 
int n, k, l; string s;
 
pair < int, int > alien(vector < int > &a, int C) {
  vector < int > dp(a.size() + 5, 0);
  vector < bool > take(a.size() + 5, false);
 
  for(int i = l; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if(dp[i - l] + a[i] - a[i - l] - C > dp[i]) {
      dp[i] = dp[i - l] + a[i] - a[i - l] - C;
      take[i] = 1;
    }
  }
 
  int p = n, ret = 0;
  while(p > 0) {
    if(take[p]) {
      ret++;
      p -= l;
    }
    else {
      p--;
    }
  }
 
  return make_pair(ret, dp[n]);
}
 
int solve(vector < int > a) {
  for(int i = 1; i <= n; ++i) a[i] += a[i - 1];
 
  int low = 0, high = n + 244, ans = high;
  while(low <= high) {
    int mid = (low + high) >> 1;
    if(alien(a, mid).first > k) {
      low = mid + 1;
    }
    else {
      ans = mid;
      high = mid - 1;
    }
  }
  return a[n] - (alien(a, ans).second + ans * k);
}
 
main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
 
  cin >> n >> k >> l >> s;
  
  if(n / l <= k) {
    cout << 0;
    return 0;
  }
 
  vector < int > v(n + 5);
  for(int i = 0; i < s.size(); ++i) if(s[i] < 'a') v[i + 1] = 1;
 
  int ans = solve(v);
  for(int i = 1; i <= n; ++i) v[i] = 1 - v[i];
  ans = min(ans, solve(v));
 
  cout << ans << "\n";
 
  return 0;
}