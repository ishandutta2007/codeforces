#include <bits/stdc++.h>
using namespace std;

const int maxn = 112345;

int k, n;
vector<int> G[maxn];
int a[maxn], b[maxn];

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  for (int i = 1; i <= n; i++) G[a[i]].emplace_back(b[i]);
  int need = 0;
  vector<int> tab;
  for (int i = 1; i <= k; i++) {
    if (G[i].empty()) need++;
    else {
      sort(G[i].begin(), G[i].end());
      for (int j = 0; j < int(G[i].size()) - 1; j++) tab.emplace_back(G[i][j]);
    }
  }
  sort(tab.begin(), tab.end());
  long long ans = 0;
  for (int i = 0; i < need; i++) ans += tab[i];
  printf("%lld", ans);
}