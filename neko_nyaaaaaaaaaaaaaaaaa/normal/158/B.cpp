#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> freq(5);
      for (int i = 0; i < n; i++) {
            int x; cin >> x;
            freq[x]++;
      }

      // pair up 4s with... nothing else :D
      int ans = freq[4];

      // pair up 3s with 1s
      ans += freq[3];
      freq[1] = max(0, freq[1] - freq[3]);

      // pair up 2s with itself
      ans += freq[2]/2;

      // if odd number of 2s, let's pair them with 1s
      if (freq[2] % 2 != 0) {
            ans++;
            freq[1] = max(0, freq[1] - 2);
      }

      // pair up the rest of the 1s
      if (freq[1] % 4 == 0) {
            ans += freq[1]/4;
      } else {
            ans += freq[1]/4 + 1;
      }

      // done :D
      cout << ans;

      return 0;
}