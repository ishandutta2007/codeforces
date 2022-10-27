#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1005;
int n, d, fa[N], sz[N];
int st[N], top;

int find(int x) {
  while (x != fa[x])
    x = fa[x] = fa[fa[x]];
  return x;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> d;
  for (int i = 1; i <= n; i++)
    fa[i] = i, sz[i]++;

  for (int i = 1, cnt = 0; i <= d; i++) {
    int x, y;
    cin >> x >> y;
    x = find(x), y = find(y);

    if (x != y)
      fa[x] = y, sz[y] += sz[x], cnt++;

    top = 0;
    for (int i = 1; i <= n; i++)
      if (find(i) == i)
        st[++top] = sz[i];

    sort(st + 1, st + top + 1, greater<int>());

    int ans = 0;
    for (int j = 1; j <= 1 + i - cnt; j++)
      ans += st[j] - (j == 1);
    cout << ans << '\n';
  }
}