#include <bits/stdc++.h>

using namespace std;

int const MOD = 1000000007;

void add(int &a, int b) {
  a += b;
  if (a >= MOD) a -= MOD;
}

int f[42], when[42];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  int s = 1;
  int c = getchar();
  while (c <= 32) {
    c = getchar();
  }
  int cn = 0;
  while (c > 32) {
    int olds = s;
    add(s, s);
    add(s, MOD - f[c - 'a']);
    f[c - 'a'] = olds;
    when[c - 'a'] = ++cn;
    c = getchar();
  }
  for (int i = 0; i < n; i++) {
    int v = -1;
    for (int j = 0; j < k; j++) {
      if (v < 0 || when[v] > when[j]) {
        v = j;
      }
    }
    when[v] = ++cn;
    int olds = s;
    add(s, s);
    add(s, MOD - f[v]);
    f[v] = olds;
  }
  printf("%d\n", s);
}