#include <bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    long long sumxor = 0, sum = 0;
    for(int i = 1; i <= n; ++i) {
      int x; cin >> x;
      sumxor ^= x;
      sum += x;
    }
    cout << 2 << "\n" << sumxor << " " << (sum + sumxor) << "\n";
  }

  return 0;
}