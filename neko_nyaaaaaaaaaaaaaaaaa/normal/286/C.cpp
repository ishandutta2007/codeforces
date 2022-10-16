#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      if (n % 2) {cout << "NO"; return 0;}
      vector<int> a(n+1); vector<int> b(n+1);
      for (int i = 1; i <= n; i++) cin >> a[i];
      reverse(a.begin()+1, a.end());
      int t; cin >> t;
      while (t--) {
            int x; cin >> x; b[n - x + 1]++;
      }

      vector<int> s;
      vector<int> ans(n+1);
      for (int i = 1; i <= n; i++) {
            if (s.empty() || s.back() != abs(a[i])) {
                  s.push_back(a[i]); ans[i] = -a[i];
            } else {
                  if (b[i]) {
                        s.push_back(a[i]);
                        ans[i] = -a[i];
                  } else {
                        s.pop_back();
                        ans[i] = a[i];
                  }
            }
      }

      if (s.size()) {cout << "NO";}
      else {
            cout << "YES\n";
            for (int i = n; i; i--) cout << ans[i] << ' ';
      }

      return 0;
}