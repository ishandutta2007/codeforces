#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n;
int a[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int u;
    scanf("%d", &u);
    a[u]++;
  }
  int res = 0;
  for (int i = 0; i < N - 1; i++) {
    int x = a[i] / 2;
    a[i + 1] += x;
    res += a[i] % 2;
  }
  res += a[N - 1] % 2;
  cout << res << endl;
  return 0;
}