#include <bits/stdc++.h>
using namespace std;

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

      int n, k; cin >> n >> k;
      if (k > n) {cout << "NO"; return 0;}
      priority_queue<int> pq;
      for (int i = 30; i >= 0; i--) {
            if (n >= (1 << i)) {
                  pq.push(1 << i);
                  n -= 1 << i;
            }
      }

      if (pq.size() > k) cout << "NO";
      else {
            while (pq.size() < k) {
                  int t = pq.top();
                  pq.pop();
                  pq.push(t/2);
                  pq.push(t/2);
            }
            cout << "YES\n";
            while (pq.size()) {
                  cout << pq.top() << ' ';
                  pq.pop();
            }
      }

	return 0;
}