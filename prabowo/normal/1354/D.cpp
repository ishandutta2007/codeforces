#include <bits/stdc++.h>
using namespace std;

const int LN = 20;
const int N = 1 << LN;

int n, q;

struct BIT {
  int sum[N + 1];

  void update(int x, int val) {
    for (int i = x; i <= N; i += i & -i) {
      sum[i] += val;
    }
  }

  int query(int k) {
    int cur = 0, lst = 0;
    for (int i = LN-1; i >= 0; --i) {
      if (sum[cur + (1 << i)] >= k) {
        lst = cur + (1 << i);
      } else {
        k -= sum[cur += (1 << i)];        
      }
    }

    return lst;
  }
} tree;

int solve() {
  scanf("%d %d", &n, &q);

  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);

    tree.update(a, 1);
  }

  int sz = n;
  while (q--) {
    int k;
    scanf("%d", &k);
    if (k > 0) tree.update(k, 1), ++sz;
    else tree.update(tree.query(-k), -1), --sz;
  }

  printf("%d\n", sz > 0 ? tree.query(1) : 0);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();  
  return 0;
}