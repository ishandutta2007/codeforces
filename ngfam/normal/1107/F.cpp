#include <bits/stdc++.h>

using namespace std;

struct CreditOffer{
  int a;
  int b;
  int k;
};  

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  int n;
  cin >> n;
  vector < CreditOffer > a(n);

  for(auto &p : a) {
    cin >> p.a >> p.b >> p.k;
  }

  sort(a.begin(), a.end(), [&](CreditOffer u, CreditOffer v){
    return u.b < v.b;
  });

  long long ans = 0;

  for(int days = 0; days <= n; ++days) {
    vector < long long > dp(days + 5);
    for(auto &p : a) {
      for(int d = days; d >= 1; --d) {
        dp[d] = max(dp[d], dp[d] + p.a - 1LL * p.k * p.b);
        dp[d] = max(dp[d], dp[d - 1] + p.a - 1LL * (days - d) * p.b);
      }
    }
    for(auto &x : dp) ans = max(ans, x);
  }

  cout << ans;

  return 0;
}