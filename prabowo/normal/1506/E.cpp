#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int a[N];
bool used[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    used[i + 1] = false;
  }

  int cur = 1;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || a[i] != a[i - 1]) {
      printf("%d ", a[i]);
      used[a[i]] = true;
    } else {
      while (used[cur]) ++cur;
      printf("%d ", cur);
      used[cur] = true;
    }
  }
  printf("\n");

  int lst = 0;
  priority_queue<int> pq;
  for (int i = 0; i < n; ++i) {
    if (i == 0 || a[i] != a[i - 1]) {
      printf("%d ", a[i]);
      for (int j = lst + 1; j < a[i]; ++j) pq.push(j);
      lst = a[i];
    } else {
      printf("%d ", pq.top());
      pq.pop();
    }
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}