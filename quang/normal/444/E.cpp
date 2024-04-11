#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int n;
pair<int, pair<int, int> > a[N];
int p[N], s[N], x[N];

int getpar(int u) {
  return p[u] == u ? u : p[u] = getpar(p[u]);
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d", &a[i].second.second, &a[i].second.first, &a[i].first);
  }
  sort(a + 1, a + n);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    s[i] = 1;
    scanf("%d", x + i);
    sum += x[i];
  }
  for (int i = 1; i < n; i++) {
    int u = getpar(a[i].second.first), v = getpar(a[i].second.second);
    p[u] = v;
    s[v] += s[u];
    x[v] += x[u];
    if (s[v] > sum - x[v]) {
      printf("%d\n", a[i].first);
      return 0;
    }
  }
  printf("0");
  return 0;
}