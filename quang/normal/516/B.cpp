#include <bits/stdc++.h>

#define Task "B"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 2020;

int x[] = {0, -1, 0, 1};
int y[] = {1, 0, -1, 0};

int n, m;
int sl[N][N];
char a[N][N];

void Fill(int u, int v, int w) {
  if (w == 0) {
    a[u][v] = '<';
    a[u][v + 1] = '>';
  }
  if (w == 1) {
    a[u][v] = 'v';
    a[u - 1][v] = '^';
  }
  if (w == 2) {
    a[u][v] = '>';
    a[u][v - 1] = '<';
  }
  if (w == 3) {
    a[u][v] = '^';
    a[u + 1][v] = 'v';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  //fi, fo;
  cin >> n >> m;
  memset(a, '*', sizeof a);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  queue < pair <int, int> > q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != '.') {
        continue;
      }
      for (int k = 0; k < 4; k++) {
        int i2 = i + x[k];
        int j2 = j + y[k];
        sl[i][j] += (a[i2][j2] == '.');
      }
      if (sl[i][j] == 0) {
        cout << "Not unique";
        return 0;
      }
      if (sl[i][j] == 1) {
        q.push(make_pair(i, j));
      }
    }
  }
  while (!q.empty()) {
    int u = q.front().first;
    int v = q.front().second;
    q.pop();
    if (a[u][v] != '.') {
      continue;
    }
    int huong = -1;
    for (int k = 0; k < 4; k++) {
      int i2 = u + x[k];
      int j2 = v + y[k];
      if (a[i2][j2] == '.') {
        huong = k;
        break;
      }
    }
    if (huong == -1) {
      cout << "Not unique";
      return 0;
    }
    Fill(u, v, huong);
    for (int k = 0; k < 4; k++) {
      int i2 = u + x[k];
      int j2 = v + y[k];
      if (a[i2][j2] == '.') {
        sl[i2][j2]--;
        if (sl[i2][j2] == 1) {
          q.push(make_pair(i2, j2));
        }
      }
    }
    u += x[huong];
    v += y[huong];
    for (int k = 0; k < 4; k++) {
      int i2 = u + x[k];
      int j2 = v + y[k];
      if (a[i2][j2] == '.') {
        sl[i2][j2]--;
        if (sl[i2][j2] == 1) {
          q.push(make_pair(i2, j2));
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == '.') {
        cout << "Not unique";
        return 0;
      }
    }
  }
  for (int i = 1; i <= n; i++, cout << endl) for (int j = 1; j <= m; j++)
    cout << a[i][j];
  return 0;
}