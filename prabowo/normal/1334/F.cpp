#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n, m;
int a[N], p[N];
int b[N];

vector<int> pos[N];

struct BIT {
  long long sum[N];
  void update(int x, int val) {
    for (int i = x+1; i <= n; i += i & -i) sum[i] += val;
  }
  long long query(int x) {
    long long ret = 0;
    for (int i = x+1; i > 0; i -= i & -i) ret += sum[i];
    return ret;
  }
} bit;

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &p[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) scanf("%d", &b[i]);

  for (int i = 0; i < n; ++i) {
    pos[a[i]].push_back(i);
  }

  vector<pair<int, long long>> costs = {{-1, 0LL}};
  int lst = 0;
  for (int i = 0; i < m; ++i) {
    vector<pair<int, long long>> ncosts;

    for (int j = lst + 1; j <= b[i]; ++j) {
      for (int idx: pos[j]) if (p[idx] > 0) bit.update(idx, p[idx]);
    }
    long long all = bit.query(n-1);

    for (int idx: pos[b[i]]) {
      int prv = lower_bound(costs.begin(), costs.end(), make_pair(idx, 0LL)) - costs.begin() - 1;
      if (prv >= 0) {
        ncosts.emplace_back(idx, costs[prv].second + all - bit.query(idx - 1) + (p[idx] < 0 ? p[idx] : 0));
      }
    }

    for (int j = lst + 1; j <= b[i]; ++j) {
      for (int idx: pos[j]) if (p[idx] > 0) bit.update(idx, -p[idx]);
    }
    lst = b[i];

    if (ncosts.size() == 0) return 0 * printf("NO\n");

    for (int i = 1; i < ncosts.size(); ++i) ncosts[i].second = max(ncosts[i].second, ncosts[i-1].second);
    costs = ncosts;
  }

  long long ans = -costs.back().second;
  for (int i = 0; i < n; ++i) ans += p[i];
  printf("YES\n%lld\n", ans);
  return 0;
}