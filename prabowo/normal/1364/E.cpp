#include <bits/stdc++.h>
using namespace std;

const int N = 2105;

int n;

int bit[N];

map<pair<int, int>, int> cache;

int query_made = 0;
int ask(int i, int j) {
  if (i > j) swap(i, j);
  if (cache.find({i, j}) != cache.end()) return cache[{i, j}];
  ++query_made;
  // return (i | j);
  printf("? %d %d\n", i+1, j+1);
  fflush(stdout);
  int ret;
  scanf("%d", &ret);
  if (ret == -1) assert(0);
  return cache[{i, j}] = ret;
}

int ans[N];

int solve() {
  scanf("%d", &n);

  vector<int> idxs(n); iota(idxs.begin(), idxs.end(), 0);
  int i = idxs[0], j = idxs[1], OR = ask(0, 1);

  for (int k = 2; k < n; ++k) {
    int tmp = ask(j, idxs[k]);
    if (OR < tmp);
    else if (OR > tmp) {
      i = idxs[k];
      OR = tmp;
    } else {
      j = idxs[k];
      OR = ask(i, j);
    }
  }

  int zero = -1;
  while (zero == -1) {
    int r = rand() % n;
    if (r == i || r == j) continue;
    if (ask(r, i) < ask(r, j)) {
      zero = i;
    } else if (ask(r, i) > ask(r, j)){
      zero = j;
    }
  }

  for (int i = 0; i < n; ++i) {
    if (zero == i) {
      ans[i] = 0;
    } else {
      ans[i] = ask(zero, i);
    }
  }

  printf("!");
  for (int i = 0; i < n; ++i) printf(" %d", ans[i]);
  printf("\n");

  // cerr << query_made << endl;

  fflush(stdout);
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}