#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];
int cnt;
int used[N];
int pos2 = -1;
vector <int> x[N];

void go(int u) {
  while (1) {
    if (used[u]) {
      break;
    }
    used[u] = 1;
    x[cnt].push_back(u);
    u = a[u];
  }
  if (x[cnt].size() == 2) {
    pos2 = cnt;
  }
  if (x[cnt].size() % 2 == 1) {
    puts("NO");
    exit(0);
  }
}

int main() {
  //ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  //freopen("input.txt", "r", stdin);
  #endif // Doflamingo
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    if (a[i] == i) {
      printf("YES\n");
      for (int j = 1; j <= n; j++) {
        if (j != i) {
          printf("%d %d\n", i, j);
        }
      }
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      cnt++;
      go(i);
    }
  }
  if (pos2 == -1) {
    puts("NO");
    return 0;
  }
  printf("YES\n");
  for (int i = 1; i <= cnt; i++) {
    if (i == pos2) {
      printf("%d %d\n", x[i][0], x[i][1]);
    } else {
      for (int j = 0; j < x[i].size(); j++) {
        printf("%d %d\n", x[pos2][j % 2], x[i][j]);
      }
    }
  }
  return 0;
}