#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  vector<tuple<int, int, int>> ans;
  for (int i = 0; i + 2 < n; i += 2) {
    int x = (a[i] ^ a[i + 1] ^ a[i + 2]);
    a[i] = a[i + 1] = a[i + 2] = x;
    ans.emplace_back(i, i + 1, i + 2);
  }

  for (int i = 0; i + 2 < n; i += 2) {
    a[i] = a[i + 1] = a[n - 1];
    ans.emplace_back(i, i + 1, n - 1);
  }

  if (a[n - 1] != a[n - 2]) return 0 * printf("NO\n");
  printf("YES\n%d\n", (int) ans.size());
  for (tuple<int, int, int> t: ans) {
    int x, y, z;
    tie(x, y, z) = t;
    printf("%d %d %d\n", x + 1, y + 1, z + 1);
  }
  return 0;
}