#include "bits/stdc++.h"
using namespace std;

int n, m, q, colors;
int a[305][305];

vector<pair<int, int>> Add[2000005];
vector<pair<int, int>> Del[2000005];

int AnsDif[2000005];

int p[305 * 305];
int find(int x) {
  return (p[x] == x ? x : p[x] = find(p[x]));
}

bool unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) {
    return false;
  }
  p[x] = y;
  return true;
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void recalc(const vector<pair<int, int>> &event, int coeff) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      a[i][j] = 0;
      p[i * m + j] = i * m + j;
    }
  }

  for (auto &e : event) {
    int x = e.first / m, y = e.first % m;
    int qi = e.second;
    a[x][y] = 1;
    int comp = 1;

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (0 <= nx && nx < n && 0 <= ny && ny < m && a[nx][ny] == 1) {
        comp -= unite(x * m + y, nx * m + ny);
      }
    }

    AnsDif[qi] += comp * coeff;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  cin >> n >> m >> q;
  for (int i = 0; i < q; i++) {
    int x, y, c;
    cin >> x >> y >> c;
    x--, y--;

    colors = c + 1;

    Add[c].emplace_back(x * m + y, i);
    Del[a[x][y]].emplace_back(x * m + y, i);
    a[x][y] = c;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      Del[a[i][j]].emplace_back(i * m + j, q);
    }
  }

  for (int i = 0; i < colors; i++) {
    recalc(Add[i], +1);
  }

  for (int i = 0; i < colors; i++) { // all deletions are after additions, so we can batch proccess them
    reverse(begin(Del[i]), end(Del[i]));
    recalc(Del[i], -1);
  }

  int cur_ans = 1;
  for (int i = 0; i < q; i++) {
    cur_ans += AnsDif[i];
    cout << cur_ans << "\n";
  }

  return 0;
}