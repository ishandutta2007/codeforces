#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int mod = 998244353;
  int w, h; cin >> w >> h;

  int ans = 1;
  for(int i = 1; i <= w + h; ++i) ans += ans, ans %= mod;

  cout << ans;

  return 0;
}