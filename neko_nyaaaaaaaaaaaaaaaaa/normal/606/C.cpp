#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    
    int n;
  	int ans = 0;
    cin >> n;
    vector<int> a(n+1);
    vector<int> dp(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[a[i]] = dp[a[i] - 1] + 1;
      	ans = max(ans, dp[a[i]]);
    }
    cout << n-ans << '\n';
    
    return 0;
}