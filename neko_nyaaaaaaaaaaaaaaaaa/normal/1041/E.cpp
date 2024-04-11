#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> f(n+1);
      for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            f[x]++;
            f[y]++;
      }
      if (f[n] != n-1) {cout << "NO"; return 0;}

      vector<int> ans(n+1);
      ans[1] = n;
      int petr = 2;
      int ind = 1;
      for (int i = n-1, j = 1; i; i--) {
            int dist = f[i];
            if (dist == 0) {
                  while (ans[petr]) petr++;
                  if (petr > ind) {cout << "NO"; return 0;}
                  ans[petr] = i; continue;
            } else {
                  ind += dist;
                  if (ind > n) {cout << "NO"; return 0;}
                  ans[ind] = i;
            }
      }
      cout << "YES\n";
      for (int i = 1; i < n; i++) {
            cout << ans[i] << " " << ans[i+1] << "\n";
      }

      return 0;
}