#include <bits/stdc++.h>
using namespace std;

int main() {
  int l, r;
  scanf("%d %d", &l, &r);

  int n = 1;
  vector<tuple<int, int, int>> edges;

  int diff = r - l + 1;
  while (diff > 1 << (n-1)) {
    edges.emplace_back(0, n, 1);
    for (int i = 1; i < n; ++i) {
      edges.emplace_back(i, n, 1 << (i-1));
    }
    ++n;
  }

  while ((diff & -diff) != diff) {
    int msb = 31 - __builtin_clz(diff);
    edges.emplace_back(msb + 1, n, diff ^= (1 << msb));
  }
  while (diff > 1) {
    int msb = 31 - __builtin_clz(diff);
    edges.emplace_back(msb, n, diff >>= 1); 
  }
  edges.emplace_back(0, n++, 1);
  
  if (l > 1) {
    edges.emplace_back(n - 1, n, l - 1);
    ++n;
  }

  printf("YES\n");
  printf("%d %d\n", n, (int) edges.size());
  for (tuple<int, int, int> edge : edges) {
    int u, v, w;
    tie(u, v, w) = edge;

    printf("%d %d %d\n", u + 1, v + 1, w);
  }

  return 0;
}