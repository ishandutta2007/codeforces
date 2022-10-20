#include <bits/stdc++.h>

using namespace std;

const int N = 200100;

int n, m;
set<int> s[N];
int dd[N];
int res[N];
priority_queue <pair<int, int> > p;
vector <int> a[N];

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    for (int j = 1; j <= k; j++) {
      int u;
      cin >> u;
      s[i].insert(u);
      a[abs(u)].push_back(i);
    }
    p.push(make_pair(-s[i].size(), i));
  }
  while (!p.empty()) {
    int u = p.top().second;
    p.pop();
    if (dd[u]) {
      continue;
    }
    if (s[u].empty()) {
      cout << "NO";
      return 0;
    }
    dd[u] = 1;
    int x = *s[u].begin();
    int X = abs(x);
    if (x > 0) {
      res[X] = 1;
    } else {
      res[X] = 0;
    }
    if (a[X].size() > 1) {
      int v;
      if (a[X][0] == u) {
        v = a[X][1];
      } else {
        v = a[X][0];
      }
      if (dd[v]) {
        continue;
      }
      if (s[v].find(x) != s[v].end()) {
        dd[v] = 1;
      } else {
        s[v].erase(x);
        s[v].erase(-x);
        p.push(make_pair(-s[v].size(), v));
      }
    }
  }
  printf("YES\n");
  for (int i = 1; i <= m; i++) {
    printf("%d", res[i]);
  }
  return 0;
}