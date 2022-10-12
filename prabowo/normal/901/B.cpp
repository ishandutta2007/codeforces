#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  vector<int> p = {}, q = {1};
  for (int i = 0; i < n; ++i) {
    vector<int> r = q;
    r.push_back(0);
    for (int i = (int) r.size() - 1; i > 0; --i) {
      r[i] = r[i-1];
    }
    r[0] = 0;

    for (int i = 0; i < p.size(); ++i) {
      r[i] = (r[i] + p[i]) & 1;
    }

    p = q; q = r;
  }

  printf("%d\n", (int) q.size() - 1);
  for (int i = 0; i < q.size(); ++i) printf("%d ", q[i]); printf("\n");
  printf("%d\n", (int) p.size() - 1);
  for (int i = 0; i < p.size(); ++i) printf("%d ", p[i]); printf("\n");
  return 0;
}