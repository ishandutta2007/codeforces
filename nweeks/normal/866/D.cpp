#include <bits/stdc++.h>
#include <queue>
#define int long long
using namespace std;

const int INF = -1e18;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  priority_queue<int, vector<int>, greater<int>> pq;
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum -= x;
    pq.push(x);
    pq.push(x);
    pq.pop();
  }
  while (!pq.empty()) {
    sum += pq.top();
    pq.pop();
  }
  cout << sum << endl;
}