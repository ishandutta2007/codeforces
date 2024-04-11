#include <bits/stdc++.h>

using namespace std;

const int N = 22;

int a[N][N];
int n, m;

void check() {
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != j) {
        cnt++;
      }
    }
    if (cnt > 2) {
      return;
    }
  }
  puts("YES");
  exit(0);
  return;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      scanf("%d", a[i] + j);
    }
  }
  check();
  for (int i = 1; i <= m; i++) {
    for (int j = i + 1; j <= m; j++) {
      for (int x = 1; x <= n; x++) {
        swap(a[x][i], a[x][j]);
      }
      check();
      for (int x = 1; x <= n; x++) {
        swap(a[x][i], a[x][j]);
      }
    }
  }
  puts("NO");
	return 0;
}