#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int A, B, n;
int a[N], b[N];

int solve() {
  scanf("%d %d %d", &A, &B, &n);
  long long sum = 0, largest = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }
  for (int i = 0; i < n; ++i) {
    int turn = (b[i] + A - 1) / A;
    sum += 1LL * turn * a[i];
    largest = max(largest, 1LL * a[i]);
  }

  if (sum - largest < B) printf("YES\n");
  else printf("NO\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    solve();
  }
  return 0;
}