#include <bits/stdc++.h>

using namespace std;

const int maxn = 212345;

char s[maxn];
int n, k, ans;

int main() {
  scanf("%d%d", &n, &k);
  scanf("%s", s + 1);
  for (char now = 'a'; now <= 'z'; now++) {
    int cur = 0;
    for (int i = 1; i <= n; i++) if (s[i] == now) {
      int j = 0;
      while (i + j <= n && s[i + j] == now) j++;
      cur += j / k;
      i = i + j;
    }
    ans = max(ans, cur);
  }
  printf("%d", ans);
}