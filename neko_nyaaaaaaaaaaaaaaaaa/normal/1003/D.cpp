#include <bits/stdc++.h>
using namespace std;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);
      
      int n, q, x;
      cin >> n >> q;
      
      map<int, int> cnt;
      while (n--) {
            cin >> x;
            cnt[x]++;
      }
      
      while (q--) {
            cin >> x;
            
            int ans = 0;
            for (int i = 30; i >= 0 && x > 0; i--) {
                  int need = min(cnt[1 << i], x / (1 << i));
                  ans += need;
                  x -= need*(1 << i);
            }
            
            if (x) cout << "-1\n";
            else cout << ans << '\n';
      }
      
      return 0;
}