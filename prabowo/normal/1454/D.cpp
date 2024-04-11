#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

int cnt[N];

int solve() {
  long long n;
  scanf("%lld", &n);

  vector<pair<int, long long>> v;
  for (long long i = 2; i*i <= n; ++i) {
    if (n % i > 0) continue;
    int e = 0;
    do {
      ++e;
      n /= i;
    } while (n % i == 0);

    v.emplace_back(e, i);
  }

  if (n > 1) v.emplace_back(1, n);
  sort(v.begin(), v.end());

  vector<long long> ans(v.back().first, 1LL);
  for (int i = (int) v.size() - 1; i >= 0; --i) {
    for (int j = 0; j < v[i].first; ++j) {
      ans[ans.size() - j - 1] *= v[i].second;
    }
  }

  printf("%d\n", (int) ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%lld ", ans[i]);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}