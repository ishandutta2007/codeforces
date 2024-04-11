#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      multiset<int> s;
      for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
      }
      int cur = *s.begin();
      int start = cur;
      s.erase(s.begin());

      while (s.size()) {
            if (s.find(cur+1) != s.end()) {
                  s.erase(s.find(++cur));
            } else if (s.find(cur-1) != s.end()) {
                  s.erase(s.find(--cur));
            } else {
                  cout << "NO"; return 0;
            }
      }

      if (abs(cur - start) == 1) cout << "YES";
      else cout << "NO";

      return 0;
}