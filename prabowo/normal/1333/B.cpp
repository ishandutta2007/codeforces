#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n;
int a[N], b[N];

int solve() {
  scanf("%d", &n);

  int countNeg = 0, countPos = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    if (a[i] < 0) countNeg += 1;
    if (a[i] > 0) countPos += 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  for (int i = n-1; i >= 0; --i) {
    if (a[i] < 0) countNeg -= 1;
    if (a[i] > 0) countPos -= 1;

    if (b[i] < a[i] && countNeg == 0) return 0 * printf("NO\n");
    if (b[i] > a[i] && countPos == 0) return 0 * printf("NO\n");
  }

  printf("YES\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}