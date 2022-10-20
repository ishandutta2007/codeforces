#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m;
char a[N][N];
long long dis[4][N][N];
bool used[N][N];
int x[] = {0, 1, 0, -1};
int y[] = {1, 0, -1, 0};

void go(int val) {
  priority_queue <pair<int, pair<int, int> > > p;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dis[val][i][j] = 1e9;
      used[i][j] = 0;
      if (a[i][j] - '0' == val) {
        p.push(make_pair(0, make_pair(i, j)));
        dis[val][i][j] = 0;
      }
    }
  }
  while (!p.empty()) {
    pair<int, int> u = p.top().second;
    p.pop();
    if (used[u.first][u.second]) {
      continue;
    }
    used[u.first][u.second] = 1;
    for (int i = 0; i < 4; i++) {
      pair<int, int> v;
      v.first = u.first + x[i];
      v.second = u.second + y[i];
      if (a[v.first][v.second] == '#') {
        continue;
      }
      int add = (a[v.first][v.second] == '.');
      if (dis[val][v.first][v.second] > dis[val][u.first][u.second] + add) {
        dis[val][v.first][v.second] = dis[val][u.first][u.second] + add;
        p.push(make_pair(-dis[val][v.first][v.second], v));
      }
    }
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i <= m + 1; i++) {
    a[0][i] = a[n + 1][i] = '#';
  }
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
  }
  for (int i = 0; i <= n + 1; i++) {
    a[i][0] = a[i][m + 1] = '#';
  }
  go(1);
  go(2);
  go(3);
  long long res = 1e9 + 10;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '#') {
        continue;
      }
      if (a[i][j] == '.') {
        res = min(res, dis[1][i][j] + dis[2][i][j] + dis[3][i][j] - 2);
      } else {
        res = min(res, dis[1][i][j] + dis[2][i][j] + dis[3][i][j]);
      }
    }
  }
  if (res >= 1e9) {
    cout << -1;
  } else {
    cout << res;
  }
    return 0;
}