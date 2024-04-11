#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, m;
vector<int> edges[N];

bool one[N];

bool setTwo;
bool two[N];

int ans[N];

int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;

    edges[u].push_back(v);
    edges[v].push_back(u);
  }

  for (int i = 0; i < n; ++i) one[i] = true;

  vector<int> v1, v2, v3;
  v1.push_back(0);
  for (int i = 0; i < edges[0].size(); ++i) {
    one[edges[0][i]] = false;
  }

  for (int i = 1; i < n; ++i) {
    bool allNotOne = true;
    for (int v: edges[i]) {
      if (one[v]) {
        allNotOne = false;
        break;
      }
    }

    if (allNotOne) v1.push_back(i);
    else if (!setTwo) {
      setTwo = true;
      for (int v: edges[i]) {
        if (one[v]) continue;
        two[v] = true;
      }
      v3.push_back(i);
    } else {
      if (two[i]) {
        v2.push_back(i);
      } else {
        v3.push_back(i);
      }
    }
  }

  if (v1.size() == 0 || v2.size() == 0 || v3.size() == 0) return 0 * printf("-1\n");

  for (int u: v1) {
    // cerr << u << endl;
    int cnt = 0;
    for (int v: edges[u]) {
      if (one[v]) return 0 * printf("-1\n");
      ++cnt;
    }

    if (cnt != v2.size() + v3.size()) return 0 * printf("-1\n");
    ans[u] = 1;
  }

  for (int u: v2) {
    // cerr << u << endl;
    int cnt = 0;
    for (int v: edges[u]) {
      if (two[v]) return 0 * printf("-1\n");
      ++cnt;
    }

    if (cnt != v1.size() + v3.size()) return 0 * printf("-1\n");
    ans[u] = 2;
  }

  for (int u: v3) {
    // cerr << u << endl;
    int cnt = 0;
    for (int v: edges[u]) {
      if (!one[v] && !two[v]) return 0 * printf("-1\n");
      ++cnt;
    }

    if (cnt != v2.size() + v1.size()) return 0 * printf("-1\n");
    ans[u] = 3;
  }

  for (int i = 0; i < n; ++i) {
    printf("%d ", ans[i]);
  }
    printf("\n");
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