#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int solve() {
  vector<int> v(4);
  for (int i = 0; i < 4; ++i) {
    scanf("%d", &v[i]);
  }
  vector<int> a = v;
  sort(v.begin(), v.end());

  vector<int> b = {max(a[0], a[1]), max(a[2], a[3])};
  sort(b.begin(), b.end());

  if (b[0] == v[2] && b[1] == v[3]) printf("YES\n");
  else printf("NO\n");
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