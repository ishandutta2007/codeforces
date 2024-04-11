#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int t;
int cnt[1 << 18];

int solve() {
  scanf("%d", &t);
  while (t--) {
    getchar();
    char c;
    long long a;
    scanf("%c %lld", &c, &a);

    int mask = 0;
    for (int i = 0; i < 18; ++i) {
      if (a % 10 & 1) {
        mask |= 1 << i;
      }
      a /= 10;
    }

    if (c == '+') {
      ++cnt[mask];
    } else if (c == '-') {
      --cnt[mask];
    } else if (c == '?') {
      printf("%d\n", cnt[mask]);
    }
  }
  return 0;
}


int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}