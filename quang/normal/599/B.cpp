#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
int f[N], b[N], a[N];
int cnt[N], pos[N];
bool flag = 0;

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", f + i);
    cnt[f[i]]++;
    pos[f[i]] = i;
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d", b + i);
    if (!pos[b[i]]) {
      puts("Impossible");
      return 0;
    }
    a[i] = pos[b[i]];
    if (cnt[b[i]] >= 2) {
      flag = 1;
    }
  }
  if (!flag) {
    puts("Possible");
    for (int i = 1; i <= m; i++) {
      printf("%d ", a[i]);
    }
  } else {
    puts("Ambiguity");
  }
  return 0;
}