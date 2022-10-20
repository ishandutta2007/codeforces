#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

map<int, int> x, y;
map<pair<int, int>, int> xy;

int main() {
  int n;
  scanf("%d", &n);
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    res += x[u];
    res += y[v];
    res -= xy[make_pair(u, v)];
    x[u]++;
    y[v]++;;
    xy[make_pair(u, v)]++;
  }
  cout << res << endl;
  return 0;
}