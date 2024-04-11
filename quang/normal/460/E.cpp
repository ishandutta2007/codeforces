#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pi;

int n, r, res, magic;
pi st[10];
vector <pi> a;
pi ans[10];

int dis(pi u, pi v) {
  return (u.first - v.first) * (u.first - v.first) + (u.second - v.second) * (u.second - v.second);
}

bool cmp(pi u, pi v) {
  return dis(u, pi(0, 0)) > dis(v, pi(0, 0));
}

void go(int u, int id, int sum) {
  if (id > n) {
    if (sum > res) {
      res = sum;
      for (int i = 1; i <= n; i++) {
        ans[i] = st[i];
      }
    }
    return;
  }
  if (u >= magic) {
    return;
  }
  go(u + 1, id, sum);
  for (int i = 1; i < id; i++) {
    sum += dis(a[u], st[i]);
  }
  st[id] = a[u];
  go(u, id + 1, sum);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> r;
  for (int i = -r; i <= r; i++) {
    for (int j = -r; j <= r; j++) {
      if (dis(pi(i, j), pi(0, 0)) <= r * r) {
        a.push_back(pi(i, j));
      }
    }
  }
  sort(a.begin(), a.end(), cmp);
  magic = min(32, (int)a.size());
  go(0, 1, 0);
  cout << res << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i].first << ' ' << ans[i].second << endl;
  }
  return 0;
}