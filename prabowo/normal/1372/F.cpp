#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
int a[N];

map<pair<int, int>, pair<int, int>> cache;
pair<int, int> ask(int l, int r) {
  if (cache.find({l, r}) != cache.end()) return cache[{l, r}];
  printf("? %d %d\n", l+1, r+1);
  fflush(stdout);
  int x, f;
  scanf("%d %d", &x, &f);
  return cache[{l, r}] = make_pair(x, f);
}

int ans[N];
void answer() {
  printf("!");
  for (int i = 0; i < n; ++i) {
    printf(" %d", ans[i]);
  }
  printf("\n");
}

map<int, int> len;
int dfs(int l, int r) {
  if (l > r) return r;
  int x, f;
  tie(x, f) = ask(l, r);

  if (len.find(x) != len.end()) {
    int lenx = len[x];
    len.erase(x);

    for (int i = r-f+1; i <= r-f+lenx; ++i) {
      ans[i] = x;
    }
    dfs(l, r-f);
    return r-f+lenx;
  }

  len[x] = f;
  while (len.find(x) != len.end()) {
    l = dfs(l, l + f - 1) + 1;
  }
  return dfs(l, r);
}

int solve() {
  scanf("%d", &n);

  dfs(0, n-1);

  answer();
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}