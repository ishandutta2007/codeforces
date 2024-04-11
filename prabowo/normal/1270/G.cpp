#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int n;
int a[N];

bool vis[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    vis[i] = false;
  }

  int cur = 0;
  while (!vis[cur]) {
    vis[cur] = true;
    cur = cur - a[cur];
  }

  vector<int> ans;
  ans.push_back(cur);
  for (int i = cur - a[cur]; i != cur; i = i - a[i]) {
    ans.push_back(i);
  }

  printf("%d\n", (int) ans.size());
  for (int u: ans) printf("%d ", u+1);
  printf("\n");

  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}