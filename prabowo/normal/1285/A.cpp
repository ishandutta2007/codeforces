#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
char s[N];

int main() {
  scanf("%d", &n);
  scanf("%s", s);

  int l = 0, r = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') ++l;
    else ++r;
  }

  printf("%d\n", l + r + 1);
  return 0;
}