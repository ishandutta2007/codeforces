#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
int l, r;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  sort(a + 1, a + n + 1);
  int moves = (n - 1) / 2;
  int res = 2 * 1e9;
  for (int i = 0; i <= moves; i++) {
    int r = n - (moves - i);
    res = min(res, a[r] - a[i + 1]);
  }
  cout << res << endl;
  return 0;
}