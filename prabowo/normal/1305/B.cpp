#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int n;
char s[N];

int solve() {
  scanf("%s", s);

  n = strlen(s);
  int l = 0, r = n-1;
  vector<int> v;
  for (;;) {
    while (r >= 0 && s[r] != ')') --r;
    while (l < n && s[l] != '(') ++l;

    if (l < r) {
      v.push_back(l++);
      v.push_back(r--);
    } else break;
  }

  sort(v.begin(), v.end());

  if (v.size()) {
    printf("1\n");
    printf("%d\n", (int) v.size());
    for (int u: v) {
      printf("%d ", u+1);
    }
    printf("\n");
  } else printf("0\n");

  return 0;
}

int main() {
  int t = 1;
  // scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}