#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);

  int n;
  string s;

  cin >> n >> s;

  vector < long long > a(n + 1);
	for(int i = 1; i <= n; ++i) cin >> a[i];


  /// f[i][j][k] = solve the i -> j segments with k elements equal to s[i] in its front

  static long long f[105][105][105];

  function < long long(int, int, int) > dp = [&](int l, int r, int k) {
    long long &val = f[l][r][k];

    if(val != -1) return val;
    val = 0;
    if(l > r) return val;    

    val = a[k + 1] + dp(l + 1, r, 0);
    for(int i = l; i <= r; ++i) {
      val = max(val, dp(l, i, 0) + dp(i + 1, r, 0));
    }

    for(int i = l + 1; i <= r; ++i) {
      if(s[l] != s[i]) continue;
      val = max(val, dp(i, r, k + 1) + dp(l + 1, i - 1, 0));
    }
    return val;
  };

  memset(f, -1, sizeof f);

  cout << dp(0, n - 1, 0) << endl;

  return 0;
}