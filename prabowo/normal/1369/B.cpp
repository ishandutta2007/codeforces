#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int MOD = 998244353;

int n;
char s[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);
  bool ok = true;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && s[j] == s[i]) ++j;
    if (s[i] == '0' && i == 0) {
      for (int k = i; k < j; ++k) printf("0");
    } else if (s[i] == '1' && j == n) {
      for (int k = i; k < j; ++k) printf("1");
    } else if (s[i] == '1' && ok) {
      printf("0");
      ok = false;
    }
    i = j;
  }
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}