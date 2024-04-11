#include <bits/stdc++.h>
using namespace std;

int grid[4][4] = {
  {4, 3, 6, 12},
  {7, 5, 9, 15},
  {14, 1, 11, 10},
  {13, 8, 16, 2}
};

int ans[505][505];

void Solve(int N, int x, int y) {
  static int cnt = 1;
  if (N == 4) {
    swap(ans[x - 1][y], ans[x - 1][y + 1]);
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        ans[i + x][y + j] = cnt + grid[i][j] - 1;
      }
    }
    return;
  }

  if (N & 1) {
    for (int rep = 0; rep < N - 1; rep++) {
      ans[x][y] = cnt++;
      x--;
    }
    ans[x][y] = cnt++;
    for (int rep = 0; rep < N - 1; rep++) {
      ans[x][--y] = cnt++;
    }
    x++;
    return Solve(N - 1, x, y);
  } else {
    for (int rep = 0; rep < N - 1; rep++) {
      ans[x][y] = cnt++;
      y++;
    }
    ans[x][y] = cnt++;
    for (int rep = 0; rep < N - 1; rep++) {
      ans[++x][y] = cnt++;
    }
    y--;
    return Solve(N - 1, x, y);
  }
}

int Rook() {
  int vis[5][5] = {};
  int x, y;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (ans[i][j] == 1) {
        x = i, y = j;
        break;
      }
    }
  }

  int cnt = 0;
  int res = 0;
  while (cnt < 9) {
    cnt++;
    vis[x][y] = 1;
    int mn = 1e9;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (vis[i][j]) continue;
        if (i == x || j == y) {
          mn = min(mn, ans[i][j]);
        }
      }
    }
    if (mn == 1e9) {
      res++;
      for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
          if (vis[i][j]) continue;
          mn = min(mn, ans[i][j]);
        }
      }
    }
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (vis[i][j]) continue;
        if (ans[i][j] == mn) {
          x = i, y = j;
        }
      }
    }
  }

  return res; 

}

int Queen() {
  int vis[5][5] = {};
  int x, y;
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      if (ans[i][j] == 1) {
        x = i, y = j;
        break;
      }
    }
  }

  int cnt = 0;
  int res = 0;
  while (cnt < 9) {
    cnt++;
    vis[x][y] = 1;
    int mn = 1e9;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (vis[i][j]) continue;
        for (int k = -2; k <= 2; k++) {
          if (i == x || j == y || (i + k == x && j + k == y) || (i - k == x && j + k == y)) {
            mn = min(mn, ans[i][j]);
          }
        }
      }
    }
    if (mn == 1e9) {
      res++;
      for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
          if (vis[i][j]) continue;
          mn = min(mn, ans[i][j]);
        }
      }
    }
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (vis[i][j]) continue;
        if (ans[i][j] == mn) {
          x = i, y = j;
        }
      }
    }
  }

  return res; 

}

void Gen3() {

  vector<int> p(9);
  iota(begin(p), end(p), 1);
  do {
    int ptr = 0;
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        ans[i][j] = p[ptr++];
      }
    }

    if (Rook() < Queen()) {
      return;
    }
  } while (next_permutation(begin(p), end(p)));

}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int N;
  cin >> N;

  if (N <= 2) {
    cout << -1 << "\n";
    return 0;
  }

  if (N == 3) {
    Gen3();
  } else if (N & 1) {
    Solve(N, N, N);
  } else {
    Solve(N, 1, 1);
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cout << ans[i][j] << " \n"[j == N];
    }
  }
}