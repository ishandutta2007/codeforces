#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
typedef pair<long long, long long> pi;

int n, m;
long long l[N], r[N];
pi a[N];
pair<pi, long long> b[N];
long long res[N];
priority_queue <pi > q;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  for (int i = 1; i < n; i++) {
    b[i].first.first = l[i + 1] - r[i];
    b[i].first.second = r[i + 1] - l[i];
    b[i].second = i;
  }
  sort(a + 1, a + m + 1);
  sort(b + 1, b + n);
  int cur = 1;
  for (int i = 1; i <= m; i++) {
    while (b[cur].first.first <= a[i].first && cur < n) {
      q.push(pi(-b[cur].first.second, b[cur].second));
      cur++;
    }
    while (!q.empty() && -q.top().first < a[i].first) {
      //int x = -q.top().first;
      q.pop();
    }
    if (!q.empty()) {
      res[q.top().second] = a[i].second;
      q.pop();
    }
  }
  for (int i = 1; i < n; i++) {
    if (!res[i]) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes\n";
  for (int i = 1; i < n; i++) {
    cout << res[i] << " ";
  }
  return 0;
}