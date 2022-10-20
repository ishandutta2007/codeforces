#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n, q;
int a[N * 2], last[N * 2], cnt[N * 2];
long long s[N * 2], b;

int main() {
  //freopen("E.inp", "r", stdin);
  scanf("%d %d", &n, &q);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    a[i + n] = a[i];
    last[i] = i;
  }
  for (int i = 1; i <= n * 2; i++) {
    s[i] = s[i - 1] + a[i];
  }
  while (q--) {
    scanf("%I64d", &b);
    int j = 1;
    for (int i = n + 1; i <= n * 2; i++) {
      while (s[i] - s[j] > b) {
        j++;
      }
      last[i] = last[j];
      cnt[i] = cnt[j] + 1;
      if (i - last[i] >= n) {
        printf("%d\n", cnt[i]);
        break;
      }
    }
  }
}