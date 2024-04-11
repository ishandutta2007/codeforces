#include <bits/stdc++.h>

using namespace std;

const int N = 50;

char a[N][N], b[N][N];
int posa[N], posb[N];

int main() {
  scanf("%s", a[0]);
  scanf("%s", a[1]);
  scanf("%s", b[0]);
  scanf("%s", b[1]);
  int cnt = 0;
  if (a[0][0] <= 'C') {
    posa[a[0][0] - 'A'] = cnt++;
  }
  if (a[0][1] <= 'C') {
    posa[a[0][1] - 'A'] = cnt++;
  }
  if (a[1][1] <= 'C') {
    posa[a[1][1] - 'A'] = cnt++;
  }
  if (a[1][0] <= 'C') {
    posa[a[1][0] - 'A'] = cnt++;
  }
  cnt = 0;
  if (b[0][0] <= 'C') {
    posb[b[0][0] - 'A'] = cnt++;
  }
  if (b[0][1] <= 'C') {
    posb[b[0][1] - 'A'] = cnt++;
  }
  if (b[1][1] <= 'C') {
    posb[b[1][1] - 'A'] = cnt++;
  }
  if (b[1][0] <= 'C') {
    posb[b[1][0] - 'A'] = cnt++;
  }
  for (int i = 0; i < 10; i++) {
    int f = 0;
    for (int j = 0; j < 3; j++) {
      if (posa[j] != (posb[j] + i) % 3) {
        f = 1;
      }
    }
    if (!f) {
      puts("YES");
      return 0;
    }
  }
  puts("NO");
  return 0;
}