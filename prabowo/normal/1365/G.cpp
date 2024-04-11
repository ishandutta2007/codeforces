#include <bits/stdc++.h>
using namespace std;

int n;

long long ask(vector<int> idxs) {
  if (idxs.size() == 0) return 0LL;
  printf("? %d", (int) idxs.size());
  for (int idx: idxs) {
    printf(" %d", idx);
  }
  printf("\n");
  fflush(stdout);

  long long ret;
  scanf("%lld", &ret);
  return ret;
}

void answer(vector<long long> ans) {
  printf("!");
  for (long long u: ans) {
    printf(" %lld", u);
  }
  printf("\n");
  fflush(stdout);
}

long long sum[13];

int solve() {
  scanf("%d", &n);

  vector<int> queries[13];
  vector<int> masks;
  for (int i = 0; masks.size() < n; ++i) {
    if (__builtin_popcount(i) != 6) continue;
    masks.push_back(i);
    for (int j = 0; j < 13; ++j) {
      if (i >> j & 1) queries[j].push_back(masks.size());
    }
  }

  for (int i = 0; i < 13; ++i) sum[i] = ask(queries[i]);

  vector<long long> v;
  for (int i = 0; i < n; ++i) {
    long long ans = 0;
    for (int j = 0; j < 13; ++j) {
      if (masks[i] >> j & 1) continue;
      ans |= sum[j];
    }
    v.push_back(ans);
  }

  answer(v);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}