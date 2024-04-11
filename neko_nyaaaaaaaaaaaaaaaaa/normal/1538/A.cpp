#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &it : a)
    cin >> it;

  int mn = min_element(a.begin(), a.end()) - a.begin() + 1;
  int mx = max_element(a.begin(), a.end()) - a.begin() + 1;
  
  if(mn <= n / 2 && mx <= n / 2)
    cout << max(mn, mx) << endl;
  else if(mn > n / 2 && mx > n / 2)
    cout << max(n - mx, n - mn) + 1 << endl;
  else{
    cout << min({max(mx, mn), max(n - mx + 1, n - mn + 1), min(mn, mx) + (n - max(mn, mx) + 1)}) << endl;
  }
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}