#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      set<int> s;
      int g = 0;
      while (n--) {
            int x; cin >> x;
            s.insert(x);
            g = __gcd(g, x);
      }
      if (g != 1) {cout << -1; return 0;}

      for (auto it = s.begin(); it != s.end(); it++) {
            for (int j = 2*(*it); j <= 300000; j += *it) {
                  if (s.find(j) != s.end()) s.erase(j);
            }
      }    
      // ayyylmao
      vector<int> a(s.begin(), s.end());
      n = a.size();
      if (a[0] == 1) {cout << 1; return 0;}

      int ans = n;
      for (int t = 0; t <= 1000000; t++) {
            set<int> st;
            int g = 0;
            while (g != 1 && st.size() < ans) {
                  int k = uniform_int_distribution<int>(0, n-1)(rng);
                  st.insert(k);
                  g = __gcd(g, a[k]);
            }
            ans = min(ans, int(st.size()));
      }
      cout << ans;

      return 0;
}