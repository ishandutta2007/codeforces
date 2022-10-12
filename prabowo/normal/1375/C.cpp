#include <bits/stdc++.h>
using namespace std;

const int N = 300005;
const int MOD = 998244353;

int n;
int a[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  printf(a[0] < a[n-1] ? "YES\n" : "NO\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}