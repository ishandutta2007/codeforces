#include <bits/stdc++.h>

using namespace std;

const int N = 2010;

int a[N + N], b[N + N];

int main() {
  long long res = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    res += a[x + y];
    a[x + y]++;
    res += b[x - y + N];
    b[x - y + N]++;
  }
  cout << res << endl;
  return 0;
}