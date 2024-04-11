#include <bits/stdc++.h>

using namespace std;

const int N = 200100;
typedef pair<int, int> pi;

int n;
char a[N];
int b[N], prev[N], next[N], dd[N];

int Get1(int u) {
  return (dd[u] ? (prev[u] = Get1(prev[u])) : u);
}

int Get2(int u) {
  return (dd[u] ? (next[u] = Get2(next[u])) : u);
}

int main() {
  //freopen("C.inp", "r", stdin);
  scanf("%d", &n);
  scanf("%s", a + 1);
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    next[i] = i + 1;
    prev[i] = i - 1;
  }
  priority_queue <pair<int, pi> > p;
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i + 1]) {
      p.push(make_pair(-abs(b[i] - b[i + 1]), pi(-i, -i - 1)));
    }
  }
  vector <pi> res;
  while (!p.empty()) {
    int u = -p.top().second.first;
    int v = -p.top().second.second;
    p.pop();
    if (dd[u] || dd[v]) {
      continue;
    }
    res.push_back(pi(u, v));
    dd[u] = dd[v] = 1;
    int u2 = Get1(u);
    int v2 = Get2(v);
    if (u2 > 0 && v2 <= n) {
      if (a[u2] != a[v2]) {
        p.push(make_pair(-abs(b[u2] - b[v2]), pi(-u2, -v2)));
      }
    }
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    printf("%d %d\n", res[i].first, res[i].second);
  }
  return 0;
}