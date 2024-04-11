#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100005;
int n, k[N], m;
bool u[N];
vector<bool> ans[N];
vector<int> to[N];
struct num {
  int v, id, p;
  bool operator<(const num &j) const { return v < j.v; }
} a[N << 1];

void dfs(int i) {
  while (!to[i].empty()) {
    int x = to[i].back();
    to[i].pop_back();
    if (u[x >> 1])
      continue;
    u[x >> 1] = 1, ans[a[x].id][a[x].p] = 1;
    dfs(a[x].id);
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> k[i];
    ans[i].resize(k[i]);
    for (int j = 0; j != k[i]; j++) {
      int x;
      cin >> x;
      a[m++] = num{x, i, j};
    }
  }

  sort(a, a + m);
  for (int i = 0; i != m; i += 2) {
    if (a[i].v != a[i + 1].v) {
      puts("NO");
      return 0;
    }
    to[a[i].id].push_back(i + 1);
    to[a[i + 1].id].push_back(i);
  }

  for (int i = 1; i <= n; i++)
    dfs(i);

  puts("YES");
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j != k[i]; j++)
      putchar(ans[i][j] ? 'R' : 'L');
    putchar('\n');
  }
}