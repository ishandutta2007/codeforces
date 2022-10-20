#include <bits/stdc++.h>

using namespace std;

const int N = 110;

int n, a, b;
int cur[2];
int res[N][N];

int main() {
  scanf("%d %d %d", &n, &a, &b);
  cur[0] = 2;
  cur[1] = 1;
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      int x = (i + j + 1) % 2;
      if (cur[x] <= n) {
        res[i][j] = cur[x];
        cur[x] += 2;
      }
    }
  }
  if (cur[0] <= n || cur[1] <= n) {
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < a; i++) {
    for (int j = 0; j < b; j++) {
      printf("%d ", res[i][j]);
    }
    printf("\n");
  }
  return 0;
}