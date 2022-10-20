#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int a[N], b[N];
int n;
int pos0A, pos0B;
int nxt[N];

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", a+ i);
    if (!a[i]) {
      pos0A = i;
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", b + i);
    if (!b[i]) {
      pos0B = i;
    }
  }
  for (int i = pos0A; i; i--) {
    swap(a[i], a[i - 1]);
  }
  for (int i = pos0B; i; i--) {
    swap(b[i], b[i - 1]);
  }
  for (int i = 1; i < n - 1; i++) {
    nxt[a[i]] = a[i + 1];
  }
  nxt[a[n - 1]] = a[1];
  int f = 0;
  for (int i = 1; i < n - 1; i++) {
    if (nxt[b[i]] != b[i + 1]) {
      f = 1;
      break;
    }
  }
  if (nxt[b[n - 1]] != b[1]) {
    f = 1;
  }
  cout <<(f ? "NO" : "YES");
  return 0;
}