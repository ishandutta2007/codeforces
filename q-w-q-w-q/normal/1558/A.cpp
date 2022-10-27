#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int t, st[200005], top;
bool ok[200005];
int main() {
  cin >> t;
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int t1 = (n + m + 1) / 2, t2 = (n + m) / 2;
    for (int i = 0; i <= n; i++) {
      if (i > t1 || n - i > t2) continue;
      ok[t1 - i + n - i] = 1;
    }
    t1 = (n + m) / 2, t2 = (n + m + 1) / 2;
    for (int i = 0; i <= n; i++) {
      if (i > t1 || n - i > t2) continue;
      ok[t1 - i + n - i] = 1;
    }
    top = 0;
    for (int i = 0; i <= n + m; i++)
      if (ok[i]) st[++top] = i, ok[i] = 0;
    printf("%d\n", top);
    for (int i = 1; i <= top; i++) printf("%d%c", st[i], " \n"[i == top]);
  }
}