#include <bits/stdc++.h>
using namespace std;

const int N = 500005;

int n;
bool vis[N];
int ans[N];

int solve() {
  scanf("%d", &n);
  
  int cur = n;
  int idx = n;
  for (int i = n/2; i > 0; --i) {
    while (idx > cur) ans[idx--] = i + 1;
    for (int j = i*2; j <= n; j += i) {
      if (!vis[j]) --cur;
      vis[j] = true;
    }
  }
  for (int i = 2; i <= idx; ++i) ans[i] = 1;

  for (int i = 2; i <= n; ++i) printf("%d ", ans[i]);
  printf("\n");

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) solve();
  return 0;
}

// 1 2 3 4 5 6 7 9