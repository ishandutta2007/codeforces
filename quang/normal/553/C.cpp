#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, m, cnt;
vector <pair<int, int> > hates;
vector <int> a[N];
int dd[N];

struct dsu {
  int a[N];

  dsu() {
    for (int i = 1; i <= 100000; i++) {
      a[i] = i;
    }
  }

  int pa(int x) {
    return (a[x] == x ? x : (a[x] = pa(a[x])));
  }

  bool check(int x, int y) {
    int x1 = pa(x);
    int y1 = pa(y);
    if (x1 == y1) {
      return 1;
    }
    return 0;
  }

  void join(int x, int y) {
    int x1 = pa(x);
    int y1 = pa(y);
    if (x1 == y1) {
      return;
    }
    a[x1] = y1;
  }
} t;

void dfs(int u, int x) {
  dd[u] = x + 1;
  for (int i = 0; i < a[u].size(); i++) {
    int v = a[u][i];
    if (dd[v]) {
      if (dd[v] != ((x ^ 1) + 1)) {
        cout << 0 << endl;
        exit(0);
      }
    } else {
      dfs(v, x ^ 1);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  cnt = n;
  for (int i = 1; i <= m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c == 1) {
      t.join(a, b);
    } else {
      hates.push_back(make_pair(a, b));
    }
  }
  for (int i = 0; i < hates.size(); i++) {
    int x = hates[i].first;
    int y = hates[i].second;
    if (t.check(x, y)) {
      cout << 0 << endl;
      return 0;
    }
    a[t.pa(x)].push_back(t.pa(y));
    a[t.pa(y)].push_back(t.pa(x));
  }
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!dd[i] && t.pa(i) == i) {
      cnt++;
      dfs(i, 0);
    }
  }
  int res = 1;
  for (int i = 1; i < cnt; i++) {
    res = 1ll * res * 2 % 1000000007;
  }
  cout << res << endl;
  return 0;
}