#include <bits/stdc++.h>

using namespace std;

const int N = 150010;

int n;
int a[N];
int cnt = 0;
int b[N];
int wrong[N];
int s;

bool check(int u) {
  if (u & 1) {
    return a[u] < a[u + 1];
  }
  return a[u] > a[u + 1];
}

bool check(int u, int v) {
  int ss = s;
  swap(a[u], a[v]);
  if (wrong[v - 1] && check(v - 1)) {
    ss--;
  }
  if (!wrong[v - 1] && !check(v - 1)) {
    ss++;
  }
  if (wrong[v] && check(v)) {
    ss--;
  }
  if (!wrong[v] && !check(v)) {
    ss++;
  }
  if (wrong[u - 1] && check(u - 1) && u - 1 != v - 1 && u - 1 != v) {
    ss--;
  }
  if (!wrong[u - 1] && !check(u - 1)&& u - 1 != v - 1 && u - 1 != v) {
    ss++;
  }
  if (wrong[u] && check(u) && u  != v - 1 && u  != v) {
    ss--;
  }
  if (!wrong[u] && !check(u)&& u != v - 1 && u != v) {
    ss++;
  }
  swap(a[u], a[v]);
  return ss == 0;
}

int main() {
  scanf("%d", &n);
  a[0] = 2e9;
  if (n % 2 == 0) {
    a[n + 1] = -2e9;
  } else {
    a[n + 1] = 2e9;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i < n; i++) {
    if ((i & 1) && (a[i] >= (a[i + 1]))) {
      b[i] = b[i + 1] = 1;
      wrong[i] = 1;
      s++;
    }
    if ((i % 2 == 0) && (a[i] <= a[i + 1])) {
      b[i] = b[i + 1] = 1;
      wrong[i] = 1;
      s++;
    }
  }
  for (int i = 1; i <= n; i++) {
    cnt += b[i];
  }
  int res = 0;
  if (cnt > 6) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (!b[i]) {
      continue;
    }
    for (int j = 1; j <= n; j++) {
      if (i == j) {
        continue;
      }
      int x = check(i, j);
      if (b[j]) {
        res += (i < j) * x;
      } else {
        res += x;
      }
    }
  }
  cout << res << endl;
  return 0;
}