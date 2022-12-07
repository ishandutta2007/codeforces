#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n, k1, k2;
    cin >> n >> k1 >> k2;
    int ans;
    for(int i = 1; i <= n; ++i) {
      int x; cin >> x;
      if(x == n) ans = (i <= k1);
    }
    cout << (ans ? "YES" : "NO") << endl;
  }

  return 0;
}