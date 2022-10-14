#include <bits/stdc++.h>
using namespace std;
using lint = long long;

const lint MAX = 600005;

pair<lint, lint> tree[600005];
vector<lint> coord;

void update(lint x, lint y) {
  x = lower_bound(begin(coord), end(coord), x) - begin(coord) + 1;
  for (lint i = x; i < MAX; i += (i & -i)) {
    tree[i].first += y;
    tree[i].second++;
  }
}

pair<lint, lint> query(lint x) {
  pair<lint, lint> res = {0, 0};
  x = lower_bound(begin(coord), end(coord), x) - begin(coord) + 1;
  
  for (lint i = x; i > 0; i -= (i & -i)) {
    res.first += tree[i].first;
    res.second += tree[i].second;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<pair<lint, lint>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    a[i].first += 1e9;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].second;
    a[i].second += 1e9;
    coord.emplace_back(a[i].second);
  }
  sort(begin(a), end(a));
  sort(begin(coord), end(coord));
  coord.resize(unique(begin(coord), end(coord)) - begin(coord));

  lint ans = 0;
  
  for (lint i = 0; i < n; i++) {
    pair<lint, lint> lessSpeed = query(a[i].second); // (sum, cnt)
    ans += a[i].first * lessSpeed.second - lessSpeed.first;
    update(a[i].second, a[i].first);
  }

  cout << ans << "\n";
  return 0;
}