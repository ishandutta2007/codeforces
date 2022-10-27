#include <cstdio>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

const int N = 200005;
int n, ans, a[N], d[N];
vector<int> to[N];
unordered_set<int> q[N];

void dfs(int i, int fa) {
  d[i] = d[fa] ^ a[i];
  q[i].insert(d[i]);

  bool ok = 0;
  for (int j : to[i]) {
    if (j == fa)
      continue;
    dfs(j, i);
    if (q[i].size() < q[j].size())
      swap(q[i], q[j]);
    for (int x : q[j]) {
      if (q[i].find(x ^ a[i]) != q[i].end())
        ok = 1;
    }
    for (int x : q[j])
      q[i].insert(x);
  }

  if (ok)
    ans++, q[i].clear();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i != n; i++) {
    int x, y;
    cin >> x >> y;
    to[x].push_back(y), to[y].push_back(x);
  }

  dfs(1, 0);

  cout << ans;
}