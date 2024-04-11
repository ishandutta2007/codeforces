#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
      ios::sync_with_stdio(0); cin.tie(0);

      int n; cin >> n;
      int m; cin >> m;
      vector<int> a(n);
      for (int i = 0; i < n; i++) {
            cin >> a[i];
      }
      sort(a.begin(), a.end());
      int ans2 = a[n-1] + m;
      int ans1;
      priority_queue<int, vector<int>, greater<int>> pq;
      for (int i = 0; i < n; i++) {
            pq.push(a[i]);
      }
      while (m--) {
            int p = pq.top();
            pq.pop();
            pq.push(p+1);
      }
      while (pq.size()) {
            ans1 = pq.top();
            pq.pop();
      }
      cout << ans1 << " " << ans2;

      return 0;
}