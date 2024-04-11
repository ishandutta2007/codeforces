#include <bits/stdc++.h>
using namespace std;

#define int long long

int n, m;

void normalize(vector<vector<int>> &split) {
      vector<vector<int>> ans;
      vector<int> a(n), ind(n+1);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
            ind[a[i]] = i;
      }

      for (auto b: split) {
            vector<int> k;
            for (int i: b) {
                  if (k.empty()) k.push_back(i);
                  else {
                        if (ind[k.back()] != ind[i] - 1) {
                              ans.push_back(k);
                              k.clear();
                              k.push_back(i);
                        } else {
                              k.push_back(i);
                        }
                  }
            }
            if (k.size()) ans.push_back(k);
      }

      swap(ans, split);
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> m;
      vector<int> a(n), ind(n+1);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
            ind[a[i]] = i;
      }
      if (m == 1) {
            cout << n*(n-1)/2 + n;
            return 0;
      }

      vector<vector<int>> split;
      split.push_back(a);
      for (int turn = 1; turn < m; turn++) {
            normalize(split);
      }

      int ans = 0;
      for (int i = 0; i < split.size(); i++) {
            int ss = split[i].size();
            ans += ss*(ss-1)/2 + ss;
            //cout << ss << endl;
      }
      cout << ans;

      return 0;
}