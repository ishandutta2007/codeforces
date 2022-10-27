#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 200005;
int main() {
  int n, m, ans;
  cin >> n >> m, ans = n;
  int *s = new int[n + 1];
  memset(s, 0, (n + 1) << 2);
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    s[x]++;
    if (s[x] == 1) ans--;
  }
  cin >> m;
  while (m--) {
    int op;
    scanf("%d", &op);
    if (op == 3) {
      printf("%d\n", ans);
      continue;
    }
    int x, y;
    scanf("%d%d", &x, &y);
    if (x > y) swap(x, y);
    if (op == 1)
      s[x]++, ans -= s[x] == 1;
    else
      s[x]--, ans += !s[x];
  }
  delete[] s;
}