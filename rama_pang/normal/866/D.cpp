#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  priority_queue<int, vector<int>, greater<int>> pq;
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int p;
    scanf("%d", &p);
    ans -= p;
    pq.emplace(p);
    pq.emplace(p);
    pq.pop();
  }
  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }
  cout << ans << "\n";
  return 0;
}