#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n, t;
char a[N];

int main() {
  scanf("%d %d", &n, &t);
  scanf("%s", a + 1);
  int cnt = 0;
  int has = 0;
  int pos = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == '.') {
      has = i;
      continue;
    }
    if (has) {
      if (a[i] == '4') {
        cnt++;
      } else if (a[i] > '4') {
        cnt++;
        pos = i;
        break;
      } else {
        cnt = 0;
      }
    }
  }
  if (pos == 0) {
    printf("%s", a + 1);
    return 0;
  }
  cnt = min(cnt, t);
  for (int i = pos; i >= pos - cnt + 1; i--) {
    if (a[i] >= '5') {
      if (a[i - 1] != '.') {
        a[i - 1]++;
      } else {
        a[i - 2]++;
      }
    }
  }
  int last = pos -cnt;
  int be = 1;
  if (pos - cnt == has) {
    last--;
    for (int i = has - 1; i > 1; i--) {
      if (a[i] > '9') {
        a[i] = '0';
        a[i - 1]++;
      }
    }
    if (a[1] > '9') {
      a[1] = '0';
      a[0] = '1';
      be = 0;
    }
  }
  for (int i = be; i <= last; i++) {
    printf("%c", a[i]);
  }
  return 0;
}