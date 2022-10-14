#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const int MAXN = 1005;

int N, M, T;
string A[MAXN];

int dist[MAXN][MAXN][2];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(dist, -1, sizeof(dist));

  cin >> N >> M >> T;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  queue<pair<pair<int, int>, int>> q;
  auto Inside = [&](int x, int y) {
    return 0 <= x && x < N && 0 <= y && y < M;
  };

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int d = 0; d < 4; d++) {
        if (Inside(i + dx[d], j + dy[d]) && A[i][j] == A[i + dx[d]][j + dy[d]]) {
          dist[i][j][A[i][j] - '0'] = 0;
          q.push({{i, j}, A[i][j] - '0'});
          break;
        }
      }
    }
  }

  while (!q.empty()) {
    int x = q.front().first.first;
    int y = q.front().first.second;
    int b = q.front().second;
    q.pop();
    if (dist[x][y][b ^ 1] == -1) {
      dist[x][y][b ^ 1] = dist[x][y][b] + 1;
      q.push({{x, y}, b ^ 1});
    }
    for (int d = 0; d < 4; d++) {
      if (Inside(x + dx[d], y + dy[d])) {
        if (dist[x + dx[d]][y + dy[d]][b ^ 1] == -1) {
          dist[x + dx[d]][y + dy[d]][b ^ 1] = dist[x][y][b] + 1;
          q.push({{x + dx[d], y + dy[d]}, b ^ 1});
        }
      }
    }
  }
/*
  for (int tm = 0; tm <= 5; tm++) {
    cout << "\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        int x, y;
        x = i, y = j;
        lint t = tm;

        int st = dist[x][y][A[x][y] - '0'];
        if (st == -1) {
          cout << A[x][y];
          continue;
        }

        t -= st;
        if (t < 0) {
          cout << A[x][y];
          continue;
        }

        t %= 2;
        int ans = (A[x][y] - '0');
        if (t) ans ^= 1;
        cout << ans;
      }
      cout << "\n";
    }
    cout << "\n";
  }
*/
  while (T--) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    
    lint t;
    cin >> t;

    int st = dist[x][y][A[x][y] - '0'];
    // cout << st << "\n";
    if (st == -1 || t < st) {
      cout << A[x][y] << "\n";
      continue;
    }

    t -= st;
    t %= 2;
    int ans = (A[x][y] - '0');
    if (t) ans ^= 1;
    cout << ans << "\n";
  }
}

/*
2 4 0
0010
1101
*/