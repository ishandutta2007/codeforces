#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest;
  cin >> ntest;
  while(ntest--) {
    int n, d;
    cin >> n >> d;
    int ans = 0;
    for(int i = 0; i < n; ++i) {
      int x; cin >> x;
      if(i == 0) ans += x;
      else {
        int y = min(x, d / i);
        ans += y;
        d -= y * i;
      }
    }

    cout << ans << endl;
  }

  return 0;
}