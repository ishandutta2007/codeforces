#include <bits/stdc++.h>

using namespace std;

const int N = 3010;

int n;
int x[N], y[N], top;
pair<int, pair<int, int> > st[N * N];
bitset<N> adj[N];

int sqr(int u) {
  return u * u;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &x[i], &y[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int dis = sqr(abs(x[i] - x[j])) + sqr(abs(y[i] - y[j]));
      st[top++] = make_pair(dis, make_pair(i, j));
    }
  }
  sort(st, st + top);
  for (int i = top - 1 ;i >= 0; i--) {
    int dis = st[i].first;
    int a = st[i].second.first;
    int b = st[i].second.second;
    if ((adj[a] & adj[b]).any()) {
      printf("%0.17f", sqrt(dis) / 2);
      return 0;
    }
    adj[a][b] = 1;
    adj[b][a] = 1;
  }
  return 0;
}