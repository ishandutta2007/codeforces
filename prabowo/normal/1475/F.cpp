#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005;

int n;
char a[N][N];
char b[N][N];

void toggle(char &c) {
  if (c == '0') c = '1';
  else c = '0';
}

bool same() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (a[i][j] != b[i][j]) return false;
    }
  }
  return true;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", b[i]);
  }

  for (int i = 0; i < n; ++i) {
    if (a[i][0] != b[i][0]) {
      for (int j = 0; j < n; ++j) {
        toggle(a[i][j]);
      }
    }
  }

  for (int j = 1; j < n; ++j) {
    if (a[0][j] != b[0][j]) {
      for (int i = 0; i < n; ++i) {
        toggle(a[i][j]);
      }
    }
  }

  if (same()) return 0 * printf("YES\n");

  for (int i = 0; i < n; ++i) for (int j = 1; j < n; ++j) toggle(a[i][j]);

  for (int j = 1; j < n; ++j) {
    if (a[0][j] != b[0][j]) {
      for (int i = 0; i < n; ++i) {
        toggle(a[i][j]);
      }
    }
  }

  if (same()) return 0 * printf("YES\n");

  printf("NO\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}