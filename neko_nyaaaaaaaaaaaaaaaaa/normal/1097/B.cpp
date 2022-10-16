#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, s = 0;
vector<int> a(80);

void dfs(int i, int sum) {
      if (i == n) {
            if (sum % 360 == 0) {cout << "YES"; exit(0);}
            return;
      }

      dfs(i+1, sum + a[i]);
      dfs(i+1, sum - a[i]);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      for (int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
      }
      dfs(0, 0);
      cout << "NO";

      return 0;
}