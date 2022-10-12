#include <bits/stdc++.h>
using namespace std;

const int N = 505;

int n;
int a[N], b[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &b[i]);
  }

  if (n & 1) {
    if (a[n/2] != b[n/2]) return 0 * printf("No\n");
  }

  vector<pair<int, int>> v1, v2;
  for (int i = 0; i < n/2; ++i) {
    v1.emplace_back(a[i], a[n-i-1]);
    v2.emplace_back(b[i], b[n-i-1]);

    if (v1.back().second < v1.back().first) swap(v1.back().first, v1.back().second);
    if (v2.back().second < v2.back().first) swap(v2.back().first, v2.back().second);
  }

  sort(v1.begin(), v1.end());
  sort(v2.begin(), v2.end());

  if (v1 == v2) printf("Yes\n");
  else printf("No\n");

  return 0;
}


int main() {
  int t = 1;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
  return 0;
}