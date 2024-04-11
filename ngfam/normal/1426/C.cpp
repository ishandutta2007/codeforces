#include<bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int ntest; cin >> ntest;
  while(ntest--) {
    int n; cin >> n;

    int ans = n + 5;
    for(int i = 1; i * i - 5 <= n; ++i) {
      int cost = 0;
      if(n % i == 0) {
        cost = i - 1 + n / i - 1;
      }
      else {
        cost = i - 1 + n / i;
      }
      ans = min(ans, cost);
    }

    cout << ans << endl;
  }

  return 0;
}