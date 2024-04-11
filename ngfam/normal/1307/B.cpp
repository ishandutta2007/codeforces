#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n, x;
    cin >> n >> x;

    set<int> a, b;
    for(int i = 0; i < n; ++i) {
      int x; cin >> x;
      a.insert(x);
      b.insert(x + x);
    }

    int ans = 1e9;
    for(int d : a) {
      if(x % d == 0) ans = min(ans, x / d);
      else {
        if(d > x) ans = min(ans, 2);
        else ans = min(ans, x / d + 1);
      }
    }

    cout << ans << endl;
  }

  return 0;
}