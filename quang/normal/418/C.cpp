#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[110], b[110];

void get(int *a, int u) {
  if (u == 1) {
    a[1] = 1;
    return;
  }
  if (u == 2) {
    a[1] = 3;
    a[2] = 4;
    return;
  }
  if (u % 2) {
    a[1] = 2;
    for (int i = 2; i < u; i++) {
      a[i] = 1;
    }
    a[u] = (u + 1) / 2;
  } else {
    for (int i = 1; i < u; i++) {
      a[i] = 1;
    }
    a[u] = (u - 2) / 2;
  }
}

int main() {
  cin >> n >> m;
  get(a, n);
  get(b, m);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << a[i] * b[j] << " ";
    }
    cout << endl;
  }
  return 0;
}