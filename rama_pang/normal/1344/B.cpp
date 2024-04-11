#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const int LIM = 1005;

int ans = 0;
int p[LIM * LIM + LIM];
int Find(int x) {
  return p[x] == x ? x : p[x] = Find(p[x]);
}
void Join(int x, int y) {
  x = Find(x);
  y = Find(y);
  if (x != y) {
    p[x] = y;
    ans--;
  }
}
void NewComponent(int x) {
  if (p[x] == -1) {
    p[x] = x;
    ans++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(p, -1, sizeof(p));

  int n, m;
  cin >> n >> m;

  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int has = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') has = 1;
    }
  }
  if (!has) {
    cout << 0 << "\n";
    return 0;
  }

  vector<int> white_row(n);
  vector<int> white_col(m);

  for (int i = 0; i < n; i++) {
    int yes = 1;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') yes = 0;
    }
    white_row[i] = yes;
  }
  for (int j = 0; j < m; j++) {
    int yes = 1;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == '#') yes = 0;
    }
    white_col[j] = yes;
  }

  int can = 1;

  for (int i = 0; i < n; i++) {
    int st = -1, et = -1, cnt = 0;
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') cnt++;
    }
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        st = j;
        while (j + 1 < m && a[i][j + 1] == '#') {
          j++;
        }
        et = j;
        break;
      }
    }
    if (st != -1 && cnt != et - st + 1) {
      can = 0;
    }
    if (st == -1) {
      int yes = 0;
      for (int j = 0; j < m; j++) {
        if (white_col[j]) yes = 1;
      }
      if (!yes) {
        can = 0;
      }
    }
  }

  for (int j = 0; j < m; j++) {
    int st = -1, et = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
      if (a[i][j] == '#') cnt++;
    }
    for (int i = 0; i < n; i++) {
      if (a[i][j] == '#') {
        st = i;
        while (i + 1 < n && a[i + 1][j] == '#') {
          i++;
        }
        et = i;
        break;
      }
    }
    if (st != -1 && cnt != et - st + 1) {
      can = 0;
    }
    if (st == -1) {
      int yes = 0;
      for (int i = 0; i < n; i++) {
        if (white_row[i]) yes = 1;
      }
      if (!yes) {
        can = 0;
      }
    }
  }
  
  if (!can) {
    cout << -1 << "\n";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') NewComponent(i * LIM + j);
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j + 1 < m; j++) {
      if (a[i][j] == '#' && a[i][j + 1] == '#') {
        Join(i * LIM + j, i * LIM + j + 1);
      }
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 0; i + 1 < n; i++) {
      if (a[i][j] == '#' && a[i + 1][j] == '#') {
        Join(i * LIM + j, (i + 1) * LIM + j);
      }
    }
  }

  cout << ans << "\n";
  return 0;
}