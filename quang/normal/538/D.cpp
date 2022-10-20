#include <bits/stdc++.h>

using namespace std;


const int N = 200;

int n;
char a[N][N], b[N][N];
char res[N][N];

bool check(int u, int v) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 'o') {
        int nextu = u + i;
        int nextv = v + j;
        if (nextu < 1|| nextv < 1 || nextu > n || nextv > n) {
          continue;
        }
        if (a[nextu][nextv] == '.') {
          return 0;
        }
      }
    }
  }
  return 1;
}

void tim(int u, int v) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j] == 'o') {
        int nextu = u + i;
        int nextv = v + j;
        if (nextu < 1|| nextv < 1 || nextu > n || nextv > n) {
          continue;
        }
        b[nextu][nextv] = 'x';
      }
    }
  }
}

bool recheck() {
  memset(b, '.', sizeof b);
  for (int i = -n + 1; i <= n - 1; i++) {
    for (int j = -n + 1; j <= n - 1; j++) {
      if (res[i + n][j + n] == 'x') {
        tim(i, j);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
      if (a[i][j] == 'o') {
        b[i][j] = 'o';
      }
      if (a[i][j] != b[i][j]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }
  res[n][n] = 'o';
  for (int i = -n + 1; i <= n- 1; i++) {
    for (int j = -n + 1; j <= n - 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      if (check(i, j)) {
        res[i + n][j + n] = 'x';
      } else {
        res[i + n][j + n] = '.';
      }
    }
  }
  if (!recheck()) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (int i = -n + 1; i <= n - 1; i++) {
    for (int j = -n + 1; j <= n - 1; j++) {
      cout << res[i + n][j + n];
    }
    cout << endl;
  }
  return 0;
}