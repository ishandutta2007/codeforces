#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, d, h;
vector <pair<int, int> > edge;
vector <int > a[N];
int cur;
int dis[N];

int dfs(int u, int p = 0) {
  int pos = u;
  for (int v : a[u]) {
    if (v == p) {
      continue;
    }
    dis[v] = dis[u] + 1;
    int foo = dfs(v, u);
    if (dis[foo] > dis[pos]) {
      pos = foo;
    }
  }
  return pos;
}

int main() {
  cin >> n >> d >> h;
  if (h * 2 < d) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 1; i <= h; i++) {
    edge.push_back(make_pair(i, i + 1));
    a[i].push_back(i + 1);
    a[i + 1].push_back(i);
  }
  cur = h + 1;
  int pre = 1;
  for (int i = 1; i <= d - h; i++) {
    edge.push_back(make_pair(pre, ++cur));
    a[pre].push_back(cur);
    a[cur].push_back(pre);
    pre = cur;
    if (cur > n) {
      puts("-1");
      return 0;
    }
  }
  for (int i = cur + 1; i <= n; i++) {
    edge.push_back(make_pair(h, i));
    a[h].push_back(i);
    a[i].push_back(h);
  }
  dis[1] = 0;
  int x = dfs(1);
  if (dis[x] != h) {
    puts("-1");
    return 0;
  }
  dis[x] = 0;
  x = dfs(x);
  if (dis[x] != d) {
    puts("-1");
    return 0;
  }
  for (pair<int, int> foo : edge) {
    printf("%d %d\n", foo.first, foo.second);
  }
  return 0;
}