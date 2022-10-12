#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d %d", &n, &k);
  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    v[i] = a[i];
  }
  sort(v.begin(), v.end());

  for (int i = 0; i < n; ++i) a[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin();

  int ans = 0;
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && a[j] - a[i] == j - i) ++j;
    i = j;
    ++ans;
  }

  if (ans <= k) printf("Yes\n");
  else printf("No\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}