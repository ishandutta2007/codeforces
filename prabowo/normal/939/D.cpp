#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n;
char s[N], t[N];

int par[N];
int root(int u) {
  if (u == par[u]) return u;
  return par[u] = root(par[u]);
}

int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  scanf("%s", t);

  for (int i = 0; i < 26; ++i) par[i] = i;

  vector<pair<char, char>> edges;
  for (int i = 0; i < n; ++i) {
    if (root(s[i] - 'a') != root(t[i] - 'a')) {
      edges.emplace_back(s[i], t[i]);
      par[root(s[i] - 'a')] = root(t[i] - 'a');
    }
  }

  printf("%d\n", (int) edges.size());
  for (int i = 0; i < edges.size(); ++i) {
    printf("%c %c\n", edges[i].first, edges[i].second);
  }
  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}