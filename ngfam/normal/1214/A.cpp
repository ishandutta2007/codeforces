#include <bits/stdc++.h>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL); 

  int n, d, e;
  cin >> n >> d >> e;

  int ans = n;
  for(int i = 0; i <= n; ++i) {
    if(i * d > n) break;
    ans = min(ans, (n - i * d) % (e * 5));
  }

  cout << ans;

  return 0;
}