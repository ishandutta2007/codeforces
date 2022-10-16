#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int check(vector<int> &a, int k, int n) {
      for (int i = 0; i < n; i++) {
            if (a[i] != a[i % k]) return 0;
      }
      return 1;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      vector<int> b(n+1), a(n);
      for (int i = 1; i <= n; i++) {
            cin >> b[i];
            a[i-1] = b[i] - b[i-1];
      }

      vector<int> ans;
      for (int i = 1; i <= n; i++) {
            if (check(a, i, n)) ans.push_back(i);
      }

      cout << ans.size() << '\n';
      for (int i: ans) cout << i << ' ';

      return 0;
}