#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(auto &it : a)
    cin >> it;

  int sum = accumulate(a.begin(), a.end(), (int)0);
  if(sum % n != 0){
    cout << -1 << endl;
    return;
  }

  int reqd = sum / n;
  int ans = 0;
  for(int i = 0; i < n; i++){
    if(a[i] > reqd)
      ans++;
  }
  cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int t; cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}